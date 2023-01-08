#pragma once

#include <allegro5/allegro.h>
#include "Polygon.h"

class Object{
protected:
	Polygon* polygon;
	Vector2D P; // Position
	Vector2D D; // Direction Vector
	Vector2D V; // Speed
	Vector2D A; // Acceleration
	float theta; // rotation
	float theta_v;

	ALLEGRO_COLOR colour;
	float lineThickness;

	static unsigned int numberOfInstances;

public:
	static bool colissionObjectPoint(const Object& A, const Vector2D& B);
	static bool colissionObjectObject(const Object& A, const Object& B);
	unsigned int getNumberOfInstances() const;
	void wrapAroundScreen(unsigned int displayWidth, unsigned int displayHeight);
};

