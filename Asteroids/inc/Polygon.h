#pragma once

#include <vector>
#include "Vector2D.h"

struct ALLEGRO_COLOR;

class Polygon{
private:
	int size;
	Vector2D* points;
	Vector2D O;
	std::vector<Vector2D*> wireframe; // (size-2)*3 number of pointers to points, each three define a simplex

public:
	Polygon(int size, Vector2D* points);
	~Polygon();

	Vector2D getCentrePoint(float angle);

	void draw(const Vector2D& P, float angle, const ALLEGRO_COLOR& lineColour, float lineThickness) const;
	void draw(const Vector2D& P, float angle, const ALLEGRO_COLOR& lineColour, float lineThickness, const ALLEGRO_COLOR& fillColour) const;
	void drawWireFrame(const Vector2D& P, float angle, const ALLEGRO_COLOR& lineColour, float lineThickness) const;

	bool isVisible(const Vector2D& P, float angle, unsigned int displayWidth, unsigned int displayHeight, float margin = 0) const;

	Vector2D getWidthMagnitudes(float angle) const;
	Vector2D getHeightMagnitudes(float angle) const;
	Vector2D getDimentions(float angle) const;

	static bool collisionPolygonPoint(const Polygon& polygon, const Vector2D& P, float angleP, const Vector2D& R);
	static bool collisionPolygonPolygon(const Polygon& polygon, const Vector2D& P, float angleP, const Polygon& otherPolygon, const Vector2D& R, float angleR);
};

