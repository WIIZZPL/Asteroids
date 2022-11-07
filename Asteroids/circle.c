#include "circle.h"

Circle* createCircle(const float x, const float y, const float r, const float theta, ALLEGRO_BITMAP* bmp) {

}

void updateCircle(Circle* thisCircle, double dt) {
	thisCircle->x += thisCircle->v_x * dt;
	thisCircle->y += thisCircle->v_y * dt;
	thisCircle->theta += thisCircle->v_theta * dt;

	if (thisCircle->x - thisCircle->r > 1) thisCircle->x = -thisCircle->r;
	else if (thisCircle->x + thisCircle->r < 0) thisCircle->x = 1 + thisCircle->r;
	else if (thisCircle->y - thisCircle->r > 1) thisCircle->y = -thisCircle->r;
	else if (thisCircle->y + thisCircle->r < 0) thisCircle->y = 1 + thisCircle->r;
}

void renderCircle(Circle* thisCircle) {

}

void destroyCircle(Circle** thisCircle) {

}