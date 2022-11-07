#pragma once

#include "globals.h"

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

typedef struct Button {
	float x, y;
	float w, h;
	ALLEGRO_BITMAP* bmp;
} Button;

Button* createButton(const float x, const float y, const float w, const float h, const ALLEGRO_BITMAP* bmp);

int colissionPointButton(Button* thisButton, float x, float y);
void renderButton(Button* thisButton);

void destroyButton(Button** thisButton);