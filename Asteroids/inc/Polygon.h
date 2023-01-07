#pragma once
#include "Vector2D.h"
#include <exception>
#include <limits>
#include <vector>
#include "allegro5/allegro5.h"
#include "allegro5/allegro_primitives.h"

class Polygon{
private:
	int size;
	Vector2D* points;
	Vector2D* O;
	Vector2D** wireframe; // (size-2)*3 number of pointers to points, each three define a simplex

public:
	Polygon(int size, Vector2D* points);
	~Polygon();

	Vector2D getCentrePoint(float angle);

	void draw(const Vector2D& P, float angle, ALLEGRO_COLOR& lineColour, float lineThickness);
	void drawWireFrame(const Vector2D& P, float angle, ALLEGRO_COLOR& lineColour, float lineThickness);

	bool isVisible(const Vector2D& P, float angle, unsigned int displayWidth, unsigned int displayHeight, float margin = 0);

	Vector2D getWidthMagnitudes(float angle);
	Vector2D getHeightMagnitudes(float angle);
	Vector2D getDimentions(float angle);

	static bool collisionPolygonPoint(const Polygon& polygon, const Vector2D& P, float angleP, const Vector2D& R);
	static bool collisionPolygonPolygon(const Polygon& polygon, const Vector2D& P, float angleP, const Polygon& otherPolygon, const Vector2D& R, float angleR);
};

