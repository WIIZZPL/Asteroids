#include "Object.h"

unsigned int Object::numberOfInstances = 0;

bool Object::colissionObjectPoint(const Object& A, const Vector2D& B){
    return Polygon::collisionPolygonPoint(*A.polygon, A.P, A.theta, B);
}

bool Object::colissionObjectObject(const Object& A, const Object& B){
    return Polygon::collisionPolygonPolygon(*A.polygon, A.P, A.theta, *B.polygon, B.P, B.theta);
}

unsigned int Object::getNumberOfInstances() const{
    return numberOfInstances;
}

void Object::wrapAroundScreen(unsigned int displayWidth, unsigned int displayHeight) {
	Vector2D H = polygon->getDimentions(theta);

	if (P.x < 0) P.x += displayWidth + H.x;
	else if (P.x > displayWidth) P.x -= displayWidth + H.x;
	if (P.y < 0) P.y += displayHeight + H.y;
	else if (P.y > displayHeight) P.y -= displayHeight + H.y;
}