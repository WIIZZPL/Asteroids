#include "Object.h"

bool Object::colissionObjectPoint(const Object& A, const Vector2D& B){
    return Polygon::collisionPolygonPoint(*A.polygon, *A.P, A.theta, B);
}

bool Object::colissionObjectObject(const Object& A, const Object& B){
    return Polygon::collisionPolygonPolygon(*A.polygon, *A.P, A.theta, *B.polygon, *B.P, B.theta);
}
