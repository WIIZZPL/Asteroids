#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(Vector2D& v) : x(v.x), y(v.y) {}

Vector2D::Vector2D(float a) : x(a), y(a) {}

Vector2D::Vector2D(float a, float b) : x(a), y(b) {}

float Vector2D::dotProduct(const Vector2D& rhs) {
	return this->x * rhs.x + this->y * rhs.y;
}

float Vector2D::magnitude(){
	return sqrt(this->x * this->x + this->y * this->y);
}

Vector2D Vector2D::operator+(const Vector2D& rhs) {
	Vector2D r;
	r.x = this->x + rhs.x;
	r.y = this->y + rhs.y;
	return r;
}

Vector2D& Vector2D::operator+=(const Vector2D& rhs) {
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

Vector2D Vector2D::operator-(const Vector2D& rhs) {
	Vector2D r;
	r.x = this->x - rhs.x;
	r.y = this->y - rhs.y;
	return r;
}

Vector2D& Vector2D::operator-=(const Vector2D& rhs) {
	this->x -= rhs.x;
	this->y -= rhs.y;
	return *this;
}

Vector2D Vector2D::operator*(const int& rhs) {
	Vector2D r;
	r.x = this->x * rhs;
	r.y = this->y * rhs;
	return r;
}

Vector2D& Vector2D::operator*=(const int& rhs) {
	this->x *= rhs;
	this->y *= rhs;
	return *this;
}

Vector2D Vector2D::operator/(const int& rhs) {
	Vector2D r;
	r.x = this->x / rhs;
	r.y = this->y / rhs;
	return r;
}

Vector2D& Vector2D::operator/=(const int& rhs) {
	this->x /= rhs;
	this->y /= rhs;
	return *this;
}

Vector2D& Vector2D::operator=(const Vector2D& rhs){
	if (this == &rhs) return *this;
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

bool Vector2D::operator==(const Vector2D& rhs){
	return this->x == rhs.x && this->y == rhs.y;
}