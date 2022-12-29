#pragma once

struct Vector2D{
	float x, y;

	Vector2D();
	Vector2D(const Vector2D& v);
	Vector2D(float a);
	Vector2D(float x, float y);

	Vector2D& operator=(const Vector2D& rhs);

	float dotProduct(const Vector2D& rhs);
	float magnitude();
	void rotate(float angle);
	Vector2D rotated(float angle);
	void rotate(const Vector2D& O, float angle);
	Vector2D rotated(const Vector2D& O, float angle);

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

