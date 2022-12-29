#pragma once
#include "Polygon.h"
#include "allegro5/allegro5.h"
#include "allegro5/allegro_primitives.h"

class Player{
private:
	Polygon* polygon;
	Vector2D* P; // Position
	Vector2D* D; // Direction Vector
	Vector2D* V; // Speed
	Vector2D* A; // Acceleration
	float theta; // rotation

	ALLEGRO_COLOR shipColour;
	float lineThickness;

	//Thruster* thruster;

public:
	Player(unsigned int displayWidth, unsigned int displayHeight);
	~Player();

	void update(float dt, char* keyboardState, unsigned int displayWidth, unsigned int displayHeight);
	void render(float lag);
};

