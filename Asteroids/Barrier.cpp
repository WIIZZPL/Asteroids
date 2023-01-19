#include "Barrier.h"

#include "App.h"

#define SIDES_AMOUNT 6
#define SIDE_LENGTH 50

#define PI 3.14159265359f

Barrier::Barrier(){
	active = true;
	colour = al_map_rgb(0, 180, 216);
	lineThickness = 2;
	P = Vector2D(App::getDisplayWidth() / 2, App::getDisplayHeight() / 2);

	Vector2D* points = new Vector2D[SIDES_AMOUNT];
	for (int i = 0; i < SIDES_AMOUNT; i++) {
		points[i] = Vector2D(0, SIDE_LENGTH).rotated(2*PI/SIDES_AMOUNT*i);
	}
	polygon = new Polygon(SIDES_AMOUNT, points);
}

Barrier::~Barrier(){
	delete polygon;
}

void Barrier::render(float lag) const{
	if(active) polygon->draw(P, 0, colour, lineThickness);
}

bool Barrier::isActive() const{
	return active;
}

void Barrier::toggle(){
	active = active ^ true;
}
