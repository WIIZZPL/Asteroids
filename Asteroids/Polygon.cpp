#include "Polygon.h"
#include <stdio.h>
class ZeroPointsException : public std::exception {
public:
	const char* what() {
		return "Zero Points in the Polygon Exception";
	}
};

Polygon::Polygon(int size, Vector2D* points) : size(size), points(points) {
	if (size == 0) throw ZeroPointsException();
	O = new Vector2D;
	for (int i = 0; i < size; i++) {
		*O += points[i];
	}
	*O /= size;
}

Polygon::~Polygon(){
	delete[] points;
	delete O;
}

void Polygon::draw(const Vector2D& P, float angle, ALLEGRO_COLOR& lineColour, float lineThickness) {
	for (int i = 0; i < size-1; i++) {
		Vector2D t = points[i].rotated(angle);
		Vector2D t1 = points[i + 1].rotated(angle);
		al_draw_line(t.x + P.x, t.y + P.y, t1.x + P.x, t1.y + P.y, lineColour, lineThickness);
	}
	Vector2D t = points[size - 1].rotated(angle);
	Vector2D t1 = points[0].rotated(angle);
	al_draw_line(t.x + P.x, t.y + P.y, t1.x + P.x, t1.y + P.y, lineColour, lineThickness);
}

void Polygon::draw(const Vector2D& P, float angle, ALLEGRO_COLOR& lineColour, float lineThickness, ALLEGRO_COLOR& fill) {
	for (int i = 0; i < size - 1; i++) {
		Vector2D t = points[i].rotated(angle);
		Vector2D t1 = points[i + 1].rotated(angle);
		al_draw_filled_triangle(t.x + P.x, t.y + P.y, t1.x + P.x, t1.y + P.y, P.x, P.y, fill);
	}
	Vector2D t = points[size - 1].rotated(angle);
	Vector2D t1 = points[0].rotated(angle);
	al_draw_filled_triangle(t.x + P.x, t.y + P.y, t1.x + P.x, t1.y + P.y, P.x, P.y, fill);

	draw(P, angle, lineColour, lineThickness);
}

bool Polygon::collision(const Vector2D& P, float angle, const Vector2D& R) {
	
	for (int i = 0; i < size - 1; i++) {
		Vector2D A = points[i].rotated(angle);
		Vector2D B = points[i + 1].rotated(angle);

		float w1 = (P.x * (B.y - P.y) + (R.y - P.y) * (B.x - P.x) - R.x * (B.y - P.y)) / ((A.y - P.y) * (B.x - P.x) - (A.x - P.x) * (B.y - P.y));
		float w2 = (R.y - P.y - w1 * (A.y - P.y)) / (B.y - P.y);

		if (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1) return true;
	}
	Vector2D A = points[0].rotated(angle);
	Vector2D B = points[size - 1].rotated(angle);

	float w1 = (P.x * (B.y - P.y) + (R.y - P.y) * (B.x - P.x) - R.x * (B.y - P.y)) / ((A.y - P.y) * (B.x - P.x) - (A.x - P.x) * (B.y - P.y));
	float w2 = (R.y - P.y - w1 * (A.y - P.y)) / (B.y - P.y);

	return (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1);
}

bool Polygon::collision(const Vector2D& P, float angleP, const Vector2D& R, const Polygon& otherPolygon, float angleR){
	//TODO
	return false;
}

const Vector2D& Polygon::getCentrePoint(){
	return *O;
}

const Vector2D Polygon::getPointFurthestFrom(const Vector2D& P, float angle, const Vector2D& R){
	Vector2D X = points[0].rotated(angle) + P;
	for (int i = 1; i < size; i++) {
		if ((R - X) < (R - (points[i].rotated(angle) + P))) X = points[i].rotated(angle) + P;
	}
	return X;
}

const Vector2D Polygon::getPointClosestFrom(const Vector2D& P, float angle, const Vector2D& R){
	Vector2D M = points[0].rotated(angle) + P;
	for (int i = 1; i < size; i++) {
		if ((R - M) > (R - (points[i].rotated(angle) + P))) M = points[i].rotated(angle) + P;
	}
	return M;
}

bool Polygon::isVisible(const Vector2D& P, float angle, unsigned int displayWidth, unsigned int displayHeight){
	Vector2D R(displayWidth / 2, displayHeight / 2);
	Vector2D M = getPointClosestFrom(P, angle, R);
	return M.x >= 0 && M.x <= displayWidth && M.y >= 0 && M.y <= displayHeight;
}