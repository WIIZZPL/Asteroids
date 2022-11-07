#pragma once

#include "globals.h"

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

typedef struct Circle {
	float x, y, theta;
	float v_x, v_y, v_theta;
	float r;
	ALLEGRO_BITMAP* bmp;
} Circle;

Circle* createCircle(const float x, const float y, const float theta, const float v_x, const float v_y, const float v_theta, ALLEGRO_BITMAP* bmp);

void updateCircle(Circle* thisCircle, double dt);
void renderCircle(Circle* thisCircle);

void destroyCircle(Circle** thisCircle);