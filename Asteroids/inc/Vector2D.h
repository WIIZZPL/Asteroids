#pragma once

struct Vector2D{
	float x, y;

	Vector2D() : x(0), y(0) {};
	Vector2D(const Vector2D& v) : x(v.x), y(v.y) {};
	Vector2D(float a) : x(a), y(a) {};
	Vector2D(float x, float y) : x(x), y(y) {};

	Vector2D& operator=(const Vector2D& rhs);

	float dotProduct(const Vector2D& rhs);
	float magnitude();
	void rotate(float angle);
	Vector2D rotated(float angle) const;
	void rotateAround(const Vector2D& O, float angle);
	Vector2D rotatedAround(const Vector2D& O, float angle) const;

	friend Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
	friend Vector2D& operator+=(Vector2D& lhs, const Vector2D& rhs);
	friend Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);
	friend Vector2D& operator-=(Vector2D& lhs, const Vector2D& rhs);
	friend Vector2D operator*(const Vector2D& lhs, const float& rhs);
	friend Vector2D& operator*=(Vector2D& lhs, const float& rhs);
	friend Vector2D operator/(const Vector2D& lhs, const float& rhs);
	friend Vector2D& operator/=(Vector2D& lhs, const float& rhs);

	friend bool operator==(const Vector2D& lhs, const Vector2D& rhs);
	friend bool operator!=(const Vector2D& lhs, const Vector2D& rhs);
	friend bool operator<(const Vector2D& lhs, const Vector2D& rhs);
	friend bool operator<=(const Vector2D& lhs, const Vector2D& rhs);
	friend bool operator>(const Vector2D& lhs, const Vector2D& rhs);
	friend bool operator>=(const Vector2D& lhs, const Vector2D& rhs);
};

