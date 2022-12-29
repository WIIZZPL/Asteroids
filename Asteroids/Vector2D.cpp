#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(const Vector2D& v) : x(v.x), y(v.y) {}

Vector2D::Vector2D(float a) : x(a), y(a) {}

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

Vector2D& Vector2D::operator=(const Vector2D& rhs) {
	if (this == &rhs) return *this;
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

float Vector2D::dotProduct(const Vector2D& rhs) {
	return this->x * rhs.x + this->y * rhs.y;
}

float Vector2D::magnitude(){
	return sqrtf(this->x * this->x + this->y * this->y);
}

void Vector2D::rotate(float angle) {
	float magnitude = this->magnitude();
	float x = this->x;
	this->x = this->x * cosf(angle) + this->y * sinf(angle);
	this->y = this->y * cosf(angle) - x * sinf(angle);
	*this *= magnitude / this->magnitude();
}

Vector2D Vector2D::rotated(float angle) {
	Vector2D R = *this;
	float magnitude = R.magnitude();
	float x = R.x;
	R.x = R.x * cosf(angle) + R.y * sinf(angle);
	R.y = R.y * cosf(angle) - x * sinf(angle);
	R *= magnitude / R.magnitude();
	return R;
}

void Vector2D::rotate(const Vector2D& O, float angle){
	*this -= O;
	float magnitude = this->magnitude();
	float x = this->x;
	this->x = this->x * cosf(angle) + this->y * sinf(angle);
	this->y = this->y * cosf(angle) - x * sinf(angle);
	*this *= magnitude / this->magnitude();
	*this += O;
}

Vector2D Vector2D::rotated(const Vector2D& O, float angle) {
	Vector2D R = *this - O;
	float magnitude = R.magnitude();
	R.x = R.x * cosf(angle) + R.y * sinf(angle);
	R.y = R.y * cosf(angle) - x * sinf(angle);
	R *= magnitude / R.magnitude();
	R += O;
	return R;
}

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
	Vector2D r;
	r.x = lhs.x + rhs.x;
	r.y = lhs.y + rhs.y;
	return r;
}

Vector2D& operator+=(Vector2D& lhs, const Vector2D& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
}

Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs) {
	Vector2D r;
	r.x = lhs.x - rhs.x;
	r.y = lhs.y - rhs.y;
	return r;
}

Vector2D& operator-=(Vector2D& lhs, const Vector2D& rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	return lhs;
}

Vector2D operator*(const Vector2D& lhs, const float& rhs) {
	Vector2D r;
	r.x = lhs.x * rhs;
	r.y = lhs.y * rhs;
	return r;
}

Vector2D& operator*=(Vector2D& lhs, const float& rhs) {
	lhs.x *= rhs;
	lhs.y *= rhs;
	return lhs;
}

Vector2D operator/(const Vector2D& lhs, const float& rhs) {
	Vector2D r;
	r.x = lhs.x / rhs;
	r.y = lhs.y / rhs;
	return r;
}

Vector2D& operator/=(Vector2D& lhs, const float& rhs) {
	lhs.x /= rhs;
	lhs.y /= rhs;
	return lhs;
}

bool operator==(const Vector2D& lhs, const Vector2D& rhs){
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const Vector2D& lhs, const Vector2D& rhs){
	return lhs.x != rhs.x || lhs.y != rhs.y;
}

bool operator<(const Vector2D& lhs, const Vector2D& rhs){
	return lhs.x * lhs.x + lhs.y * lhs.y < rhs.x* rhs.x + rhs.y * rhs.y;
}

bool operator<=(const Vector2D& lhs, const Vector2D& rhs){
	return lhs.x * lhs.x + lhs.y * lhs.y <= rhs.x* rhs.x + rhs.y * rhs.y;
}

bool operator>(const Vector2D& lhs, const Vector2D& rhs){
	return lhs.x * lhs.x + lhs.y * lhs.y > rhs.x* rhs.x + rhs.y * rhs.y;
}

bool operator>=(const Vector2D& lhs, const Vector2D& rhs){
	return lhs.x * lhs.x + lhs.y * lhs.y >= rhs.x* rhs.x + rhs.y * rhs.y;
}
