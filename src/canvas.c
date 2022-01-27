#include "tophat.h"
#include <chew.h>
#include <GL/gl.h>
#include <string.h>
#include <math.h>
#include "pixelfont.h"

GLuint th_canvas_prog;

static GLuint vao;
static GLuint vbo;

#define BATCH 1024
static int cur_batch = 0;
static float batch_verts[BATCH * 3 * 7];

extern th_global thg;

void th_canvas_init() {
	const char *attribs[] = { "pos", "color" };
	th_canvas_prog = th_gl_create_prog(
		"attribute vec3 pos;\n"
		"attribute vec4 color;\n"
		"varying vec4 vcolor;\n"
		"void main() {\n"
		"  gl_Position = vec4(pos, 1.0);\n"
		"  vcolor = color;\n"
		"}",

		"varying vec4 vcolor;\n"
		"void main() {\n"
		"  gl_FragColor = vcolor;\n"
		"}", attribs, 2);

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(batch_verts), batch_verts, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), NULL);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void *)(3 * sizeof(float)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void th_canvas_flush() {
	if (!cur_batch) return;
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferSubData(GL_ARRAY_BUFFER,
		0, cur_batch * 3 * 7 * sizeof(float), batch_verts);

	glUseProgram(th_canvas_prog);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, cur_batch * 3);
	cur_batch = 0;
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void th_canvas_triangle(uint32_t color, th_vf2 a, th_vf2 b, th_vf2 c) {
	float colors[4];
	for (int i=0; i < 4; ++i)
		colors[3 - i] = ((color >> (8 * i)) & 0xff) / (float)0xff;

	int sw, sh;
	th_window_get_dimensions(&sw, &sh);
	sh *= -1;
	sw /= 2;
	sh /= 2;

	const float verts[] = {
		a.x / sw - 1, a.y / sh + 1, 0,
	 	b.x / sw - 1, b.y / sh + 1, 0,
		c.x / sw - 1, c.y / sh + 1, 0,
	};

	float *base = &batch_verts[cur_batch * 3 * 7];
	for (int i=0; i < 3; ++i) {
		memcpy(base, &verts[i * 3], sizeof(float) * 3);
		base += 3;
		memcpy(base, colors, sizeof(float) * 4);
		base += 4;
	}

	++cur_batch;
	if (cur_batch >= BATCH)
		th_canvas_flush();
}

void th_canvas_rect(uint32_t color, th_rect r) {
	r.x *= thg.scaling;
	r.y *= thg.scaling;
	r.w *= thg.scaling;
	r.h *= thg.scaling;
	th_canvas_triangle(color,
		(th_vf2){{r.x, r.y}},
		(th_vf2){{r.x + r.w, r.y}},
		(th_vf2){{r.x, r.y + r.h}});
	th_canvas_triangle(color,
		(th_vf2){{r.x + r.w, r.y}},
		(th_vf2){{r.x + r.w, r.y + r.h}},
		(th_vf2){{r.x, r.y + r.h}});
}

// stolen from here: stackoverflow.com/questions/1936934/turn-a-line-into-a-rectangle
void th_canvas_line(uint32_t color, th_vf2 f, th_vf2 t, fu thickness) {
	f.x *= thg.scaling;
	f.y *= thg.scaling;
	t.x *= thg.scaling;
	t.y *= thg.scaling;
	thickness *= thg.scaling;

	th_vf2 d = { .x = t.x - f.x, .y = t.y - f.y};
	fu mag = sqrt(d.x*d.x + d.y*d.y);
	d.x /= mag;
	d.y /= mag;
	th_vf2 ortho = { .x = -d.y * thickness * 0.5, .y = d.x * thickness * 0.5 };

	th_canvas_triangle(color,
		(th_vf2){{f.x - ortho.x, f.y - ortho.y}},
		(th_vf2){{f.x + ortho.x, f.y + ortho.y}},
		(th_vf2){{t.x + ortho.x, t.y + ortho.y}});
	th_canvas_triangle(color,
		(th_vf2){{f.x - ortho.x, f.y - ortho.y}},
		(th_vf2){{t.x + ortho.x, t.y + ortho.y}},
		(th_vf2){{t.x - ortho.x, t.y - ortho.y}});
}

void th_canvas_text(char *text, uint32_t color, th_vf2 p, fu size) {
	fu dx = p.x;

	for (;*text; text++) {
		char *glyph = pixelfont[(int)*text];
		if (*text == '\n') {
			p.x = dx;
			p.y += size * 6;
			continue;
		}

		for (int i=0; i < 25; ++i)
			if (glyph[i])
				th_canvas_rect(color,
					(th_rect){ p.x + (i%5)*size,
					p.y + (i/5)*size, size, size});
		p.x += size * 6;
	}
}
