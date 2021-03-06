#include <stdio.h>
#include <stdlib.h>

#include "../lib/rawdraw/CNFG.h"

#include "img/bmp.h"

#include "entity.h"
#include "rect.h"
#include "poly.h"

extern float scaling;

entity entityfrompoly(poly *p, uint32_t color) {
	entity e;
	e.p = p;
	e.color = color;
	e.image = NULL;
	e.id = rand()%9999 + 1;

	return e;
}

/*
entity entityfromrect(rect r, uint32_t color) {
entity e;
e.r = r;
e.color = color;
e.image = NULL;
e.id = rand()%9999;

return e;
}
*/

entity entityfromimage(char path[]) {
	img_t img;

	parsebmp(&path[0], &img);

	entity e;
	//e.r = newrect(0, 0, img.w, img.h);
	e.image = img.content;
	e.id = rand()%9999;

	return e;
}

void draw(entity *o, rect *camera) {
	int camx, camy;
	camx = camera->x - (camera->w / 2);
	camy = camera->y - (camera->h / 2);

	// it returns only if rect doesn't collide with camera.
	if (o->p->x + o->p->w < camx || o->p->x > camx + camera->w) {
		return;
	}

	if (o->p->y + o->p->h < camy || o->p->y > camy + camera->h) {
		return;
	}

	if (o->image == NULL) {
		RDPoint *points;

		points = polytordpoint(o->p, camx, camy);
		CNFGColor(o->color);
		CNFGTackPoly(points, o->p->vc);
		free(points);

		return;
	}

	//CNFGBlitImage(o.image, o.r.x, o.r.y, o.r.w, o.r.h);
}
