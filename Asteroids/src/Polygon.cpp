#include "Polygon.h"

class LessThanSimplexException : public std::exception {
public:
	const char* what() {
		return "Less than three points in a polygon exception";
	}
};

bool isConvex(const Vector2D& A, const Vector2D& B, const Vector2D& C) {
	Vector2D BA = A - B;
	Vector2D BC = C - B;
	return (BA.x * BC.y - BA.y * BC.x) < 0;
}

bool pointInSimplex(const Vector2D& A, const Vector2D& B, const Vector2D& C, const Vector2D& P) {
	float w1 = (A.x * (C.y - A.y) + (P.y - A.y) * (C.x - A.x) - P.x * (C.y - A.y)) / ((B.y - A.y) * (C.x - A.x) - (B.x - A.x) * (C.y - A.y));
	float w2 = (P.y - A.y - w1*(B.y - A.y)) / (C.y - A.y);

	return (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1);
}

bool SimplexInSimplex(const Vector2D& A, const Vector2D& B, const Vector2D& C, const Vector2D& P, const Vector2D& R, const Vector2D& S) {
	if (pointInSimplex(A, B, C, P)) return true;
	if (pointInSimplex(A, B, C, R)) return true;
	if (pointInSimplex(A, B, C, S)) return true;
	if (pointInSimplex(P, R, S, A)) return true;
	if (pointInSimplex(P, R, S, B)) return true;
	return pointInSimplex(P, R, S, C);
}

Polygon::Polygon(int size, Vector2D* points) : size(size), points(points) {
	if (size < 3) throw LessThanSimplexException();
	O = new Vector2D();
	std::vector<Vector2D*> pointsToClip;
	for (int i = 0; i < size; i++) {
		*O += points[i];
		pointsToClip.push_back(points + i);
	}
	*O /= size;

	wireframe = new Vector2D*[(size - 2) * 3];
	int wi = 0;
	int pi = -1, i = 0, ni = 1;
	while (pointsToClip.size() > 3) {
		pi = (pi + 1) % pointsToClip.size();
		i = (pi + 1) % pointsToClip.size();
		ni = (i + 1) % pointsToClip.size();

		{ // First check - internal angle
			if (isConvex(*pointsToClip[pi], *pointsToClip[i], *pointsToClip[ni])) {
				continue;
			}
		}

		{ // Second check - colisions
			bool collides = false;
			for (int j = 0; j < pointsToClip.size(); j++) {
				if (j == pi || j == i || j == ni) continue;
				collides = pointInSimplex(*pointsToClip[pi], *pointsToClip[i], *pointsToClip[ni], *pointsToClip[j]);
				if (collides) break;
			}
			if (collides) {
				continue;
			}
		}

		wireframe[wi++] = pointsToClip[pi];
		wireframe[wi++] = pointsToClip[i];
		wireframe[wi++] = pointsToClip[ni];

		pointsToClip.erase(pointsToClip.begin() + i);
	}
	wireframe[wi++] = pointsToClip[0];
	wireframe[wi++] = pointsToClip[1];
	wireframe[wi++] = pointsToClip[2];
}

Polygon::~Polygon(){
	delete[size] points;
	delete O;
	delete[(size - 2) * 3] wireframe;
}

void Polygon::draw(const Vector2D& P, float angle, ALLEGRO_COLOR& lineColour, float lineThickness) {
	for (int i = 0; i < size - 1; i++) {
		Vector2D t = points[i].rotated(angle) + P;
		Vector2D t1 = points[i + 1].rotated(angle) + P;
		al_draw_line(t.x, t.y, t1.x, t1.y, lineColour, lineThickness);
	}
	Vector2D t = points[size - 1].rotated(angle) + P;
	Vector2D t1 = points[0].rotated(angle) + P;
	al_draw_line(t.x, t.y, t1.x, t1.y, lineColour, lineThickness);
}

void Polygon::drawWireFrame(const Vector2D& P, float angle, ALLEGRO_COLOR& lineColour, float lineThickness) {
	for (int i = 0; i < (size - 2) * 3; i += 3) {
		Vector2D A = wireframe[i]->rotated(angle) + P;
		Vector2D B = wireframe[i+1]->rotated(angle) + P;
		Vector2D C = wireframe[i+2]->rotated(angle) + P;
		al_draw_triangle(A.x, A.y, B.x, B.y, C.x, C.y, lineColour, lineThickness/2);
	}
}

Vector2D Polygon::getCentrePoint(float angle){
	return O->rotated(angle);
}

bool Polygon::isVisible(const Vector2D& P, float angle, unsigned int displayWidth, unsigned int displayHeight, float margin){
	for (int i = 0; i < size; i++) {
		Vector2D t = points[i].rotated(angle) + P;
		if (t.x >= -margin && t.x <= displayWidth+margin && t.y >= -margin && t.y <= displayHeight+margin) return true;
	}
	return false;
}

Vector2D Polygon::getWidthMagnitudes(float angle){
	float mx = FLT_MAX, xx = FLT_MIN;
	for (int i = 0; i < size; i++) {
		Vector2D A = points[i].rotated(angle);
		mx = fminf(mx, A.x);
		xx = fmaxf(xx, A.x);
	}
	return Vector2D(mx, xx);
}

Vector2D Polygon::getHeightMagnitudes(float angle){
	float my = FLT_MAX, xy = FLT_MIN;
	for (int i = 0; i < size; i++) {
		Vector2D A = points[i].rotated(angle);
		my = fminf(my, A.y);
		xy = fmaxf(xy, A.y);
	}
	return Vector2D(my, xy);
}

Vector2D Polygon::getDimentions(float angle){
	float mx = FLT_MAX, my = FLT_MAX, xx = FLT_MIN, xy = FLT_MIN; // max and min x, y

	for (int i = 0; i < size; i++) {
		Vector2D A = points[i].rotated(angle);
		mx = fminf(mx, A.x);
		my = fminf(my, A.y);
		xx = fmaxf(xx, A.x);
		xy = fmaxf(xy, A.y);
	}

	return Vector2D(xx-mx, xy-my);
}

bool Polygon::collisionPolygonPoint(const Polygon& polygon, const Vector2D& P, float angleP, const Vector2D& R) {
	for (int i = 0; i < (polygon.size - 2) * 3; i += 3) {
		Vector2D A = polygon.wireframe[i]->rotated(angleP) + P;
		Vector2D B = polygon.wireframe[i + 1]->rotated(angleP) + P;
		Vector2D C = polygon.wireframe[i + 2]->rotated(angleP) + P;
		if (pointInSimplex(A, B, C, R)) return true;
	}
	return false;
}

bool Polygon::collisionPolygonPolygon(const Polygon& polygon, const Vector2D& P, float angleP, const Polygon& otherPolygon, const Vector2D& R, float angleR) {
	for (int i = 0; i < (polygon.size - 2) * 3; i += 3) {
		Vector2D A = polygon.wireframe[i]->rotated(angleP) + P;
		Vector2D B = polygon.wireframe[i + 1]->rotated(angleP) + P;
		Vector2D C = polygon.wireframe[i + 2]->rotated(angleP) + P;
		for (int j = 0; j < (otherPolygon.size - 2) * 3; j += 3) {
			Vector2D D = otherPolygon.wireframe[j]->rotated(angleR) + R;
			Vector2D E = otherPolygon.wireframe[j + 1]->rotated(angleR) + R;
			Vector2D F = otherPolygon.wireframe[j + 2]->rotated(angleR) + R;

			if (SimplexInSimplex(A, B, C, D, E, F)) return true;
		}
	}
	return false;
}