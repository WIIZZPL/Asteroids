#include "Button.h"

#include <allegro5/allegro_ttf.h>

Button::Button(Vector2D P, Vector2D D, const ALLEGRO_FONT* font, const char str[]) : font(font), str(str) {
	theta = 0;
	theta_v = 0;
	colour = al_map_rgb(255, 255, 255);
	lineThickness = 2;

	this->P = P;
	this->D = D;

	Vector2D* points = new Vector2D[4];
	points[0] = Vector2D(0-D/2);
	points[1] = Vector2D(- D.x / 2, D.y / 2);
	points[2] = Vector2D(D / 2);
	points[3] = Vector2D(D.x / 2, - D.y / 2);
	polygon = new Polygon(4, points);
}

Button::~Button(){
	delete polygon;
}

void Button::render() const{
	polygon->draw(P, theta, colour, lineThickness, fillColour);
	al_draw_textf(font, textColour, P.x, P.y-35, ALLEGRO_ALIGN_CENTER, str);
}