#pragma once
#include "Vector2D.h"
#include <exception>
#include "allegro5/allegro5.h"
#include "allegro5/allegro_primitives.h"

class Polygon{
private:
	int size;
	Vector2D* points;
	Vector2D* O;

public:
	Polygon(int size, Vector2D* points);
	~Polygon();

	const Vector2D& getCentrePoint();

	const Vector2D getPointFurthestFrom(const Vector2D& P, float angle, const Vector2D& R);
	const Vector2D getPointClosestFrom(const Vector2D& P, float angle, const Vector2D& R);

	void draw(const Vector2D& P, float angle, ALLEGRO_COLOR& lineColour, float lineThickness);
	void draw(const Vector2D& P, float angle, ALLEGRO_COLOR& lineColour, float lineThickness, ALLEGRO_COLOR& fill);

	bool collision(const Vector2D& P, float angle, const Vector2D& R);
	bool collision(const Vector2D& P, float angleP, const Vector2D& R, const Polygon& otherPolygon, float angleR);

	bool isVisible(const Vector2D& P, float angle, unsigned int displayWidth, unsigned int displayHeight);
};

