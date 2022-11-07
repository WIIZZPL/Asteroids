#include "button.h"

Button* createButton(const float x, const float y, const float w, const float h, const ALLEGRO_BITMAP* bmp) {
	Button* newButton = (Button*)malloc(sizeof(Button));
	if (!newButton || !bmp) exit(138);
	newButton->x = x;
	newButton->y = y;
	newButton->w = w;
	newButton->h = h;
	newButton->bmp = bmp;
	return newButton;
}

int colissionPointButton(Button* thisButton, float x, float y) {
	return (thisButton->x <= x && x <= thisButton->x + thisButton->w) && (thisButton->y <= y && y <= thisButton->y + thisButton->h);
}

void renderButton(Button* thisButton) {
	al_draw_scaled_bitmap(thisButton->bmp, 0, 0, al_get_bitmap_width(thisButton->bmp), al_get_bitmap_height(thisButton->bmp),
		thisButton->x * displayWidth + displayX, thisButton->y * displayHeight + displayY, thisButton->w * displayWidth, thisButton->h * displayHeight, 0);
}

void destroyButton(Button** thisButton) {
	if (!*thisButton) return;
	al_destroy_bitmap((*thisButton)->bmp);
	free(*thisButton);
	*thisButton = NULL;
}