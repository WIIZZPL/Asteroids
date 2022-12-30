#pragma once
#include "Polygon.h"
#include "Player.h"
#include "allegro5/allegro5.h"
#include "allegro5/allegro_primitives.h"

class Asteroid {
private:
	Polygon* polygon;
	Vector2D* P; // Position
	Vector2D* V; // Speed
	float theta; // rotation
	float theta_v; // rotation

	float r;
	float lineThickness;
	ALLEGRO_COLOR asteroidColour;

public:
	Asteroid(unsigned int displayWidth, unsigned int displayHeight, Player& player, float r);
	~Asteroid();

	void update(float dt, unsigned int displayWidth, unsigned int displayHeight);
	void render(float lag);

	static Asteroid* AsteroidFactory(unsigned int displayWidth, unsigned int displayHeight, Player& player, float& massAvailable);
};

