#include <string.h>
#include <stdint.h>

#include <GL/gl.h>
#include <stb_image.h>
#include <CNFG.h>
#include <chew.h>

#include "tophat.h"

// declaration needed to leech off of rawdraw
#ifdef _WIN32
#define glActiveTexture glActiveTextureCHEW
#endif

GLuint th_blit_prog = -1;
GLuint th_blit_prog_color = -1;
GLuint th_blit_prog_pr = -1;
GLuint th_blit_prog_pos = -1;
GLuint th_blit_prog_tex = -1;

extern th_global thg;

th_image *th_load_image(char *path) {
	int w, h, c;

	unsigned char *data = stbi_load(path, &w, &h, &c, 0);

	th_image *img;
	img = malloc(sizeof(th_image));
	img->dm.w = w;
	img->dm.h = h;
	img->channels = c;
	img->filter = 1;
	img->crop = (th_rect){0, 0, 1, 1};
	img->flipv = 0;
	img->fliph = 0;

	if (data == NULL) {
		th_error("could not find image at path %s", path);
		img->data = NULL;
		return img;
	}

	// Faster way, but it doesn't seem to work. TODO FIXME
	/*if (c == 4) {
		img->rdimg = (unsigned int *)data;

		return img;
	}*/

	_th_rdimg(img, data);
	stbi_image_free(data);

	return img;
}

void th_free_image(th_image *img) {
	CNFGDeleteTex(img->gltexture);

	free(img->data);
	free(img);
}

void th_image_from_data(th_image *img, uint32_t *data, th_vf2 dm) {
	img->data = malloc(sizeof(uint32_t) * dm.w * dm.h);
	memcpy(img->data, data, sizeof(uint32_t) * dm.w * dm.h);
	img->dm = dm;
	img->flipv = 0;
	img->fliph = 0;
	img->crop = (th_rect){0, 0, 1, 1};
	img->channels = 4;
	img->filter = 1;

	img->gltexture = th_gen_texture(img->data, dm, img->filter);
}

void th_image_set_filter(th_image *img, int filter) {
	img->filter = filter;
	CNFGDeleteTex(img->gltexture);
	img->gltexture = th_gen_texture(img->data, img->dm, img->filter);
}

// stolen from rawdraw
unsigned int th_gen_texture(uint32_t *data, th_vf2 dm, unsigned filter) {
	GLuint tex;

	glGenTextures(1, &tex);
	glEnable(GL_TEXTURE_2D);
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

	if (filter)
		filter = GL_NEAREST;
	else
		filter = GL_LINEAR;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, dm.w, dm.h, 0,  GL_RGBA,
		GL_UNSIGNED_BYTE, data);

	return (unsigned int)tex;
}

// stolen from rawdraw
void th_blit_tex(th_image *img, th_transform t, uint32_t color) {
	CNFGFlushRender();

	th_quad q = th_ent_transform(
		&(th_ent){
			.rect = (th_rect){
				.w = (img->crop.w - img->crop.x) * img->dm.x,
				.h = (img->crop.h - img->crop.y) * img->dm.y},
			.t = t});

	for (uu i=0; i < 4; i++) {
		q.v[i].x *= thg.scaling;
		q.v[i].y *= thg.scaling;
	}

	th_vf2 p = th_quad_min(q);

	short sw, sh;
	CNFGGetDimensions(&sw, &sh);
	glUseProgram(th_blit_prog);
	glUniform2f(th_blit_prog_pr, 1.f/sw, -1.f/sh);
	glUniform2f(th_blit_prog_pos, -0.5f+p.x/(float)sw, 0.5f-p.y/(float)sh);
	glUniform1i(th_blit_prog_tex, 0);

	float colors[4];
	for (int i=0; i < 4; ++i)
		colors[i] = ((color >> (8 * i)) & 0xff) / (float)0xff;
	glUniform4f(th_blit_prog_color, colors[3], colors[2], colors[1], colors[0]);

	glBindTexture(GL_TEXTURE_2D, img->gltexture);

	sh *= -1;
	const float verts[] = {
		(q.tl.x - p.x)/sw, (q.tl.y - p.y)/sh,
		(q.tr.x - p.x)/sw, (q.tr.y - p.y)/sh,
		(q.br.x - p.x)/sw, (q.br.y - p.y)/sh,
		(q.tl.x - p.x)/sw, (q.tl.y - p.y)/sh,
		(q.br.x - p.x)/sw, (q.br.y - p.y)/sh,
		(q.bl.x - p.x)/sw, (q.bl.y - p.y)/sh};

	th_rect bounds = img->crop;
	bounds.x *= 255;
	bounds.y *= 255;
	bounds.w *= 255;
	bounds.h *= 255;
	if (img->flipv)
		SWAP_VARS(bounds.y, bounds.h, fu);
	if (img->fliph)
		SWAP_VARS(bounds.x, bounds.w, fu);
	uint8_t tex_verts[] = {
		bounds.x, bounds.y, bounds.w, bounds.y, bounds.w, bounds.h,
		bounds.x, bounds.y, bounds.w, bounds.h, bounds.x, bounds.h };

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_TRUE, 0, verts);
	glVertexAttribPointer(1, 2, GL_UNSIGNED_BYTE, GL_TRUE, 0, tex_verts);

	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void _th_rdimg(th_image *img, unsigned char *data) {
	uint32_t *rd = malloc(sizeof(uint32_t) * img->dm.w * img->dm.h);

	for (int x=0; x < img->dm.w; x++) {
		for (int y=0; y < img->dm.h; y++) {
			int rd_index = (y * img->dm.w) + x;
			int data_index = ((y * img->dm.w) + x) * img->channels;
			rd[rd_index] = 0;

			for (int poff=0; poff < img->channels; poff++) {
				rd[rd_index] += data[data_index + poff] << ((3 - poff) * 8);
			}

			if (img->channels == 3)
				rd[rd_index] += 0xff;
		}
	}

	img->data = rd;
}

void th_image_init() {
	const char *attribs[] = {
		"vert", "tex_vert"
	};
	th_blit_prog = th_gl_create_prog(
		"uniform vec2 pr; /* pixel ratio */\n"
		"uniform vec2 pos;\n"
		"attribute vec3 vert;\n"
		"attribute vec4 tex_vert;\n"
		"varying vec2 tc;\n"
		"void main() { gl_Position = vec4( vert.xy+pos, vert.z, 0.5 ); tc = tex_vert.xy; }\n",
		
		"varying vec2 tc;"
		"uniform sampler2D tex;"
		"uniform vec4 modColor;"
		"void main() { gl_FragColor = texture2D(tex,tc).wzyx * modColor;}",
		attribs, 2);

	th_blit_prog_color = glGetUniformLocation(th_blit_prog, "modColor");
	th_blit_prog_pr = glGetUniformLocation(th_blit_prog, "pr");
	th_blit_prog_pos = glGetUniformLocation(th_blit_prog, "pos");
	th_blit_prog_tex = glGetUniformLocation(th_blit_prog, "tex");
}

void th_image_deinit() {
	while (thg.image_count--) {
		th_image *img = thg.images[thg.image_count];
		CNFGDeleteTex(img->gltexture);
		free(img->data);
		free(img);
	}
}
