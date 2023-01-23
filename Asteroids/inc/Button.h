#pragma once

#include "Object.h"

struct ALLEGRO_FONT;

class Button : public Object{
private:
	const ALLEGRO_COLOR fillColour = al_map_rgb(0, 0, 0);
	const ALLEGRO_COLOR textColour = al_map_rgb(255, 255, 255);
	const ALLEGRO_FONT* font;
	const char* str;

public:
	Button(Vector2D P, Vector2D D, const ALLEGRO_FONT* font, const char str[]);
	~Button();

	void render() const;
};

