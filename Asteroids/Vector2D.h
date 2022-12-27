#pragma once

struct Vector2D{
	float x, y;

	Vector2D();
	Vector2D(Vector2D& v);
	Vector2D(float a);
	Vector2D(float a, float b);

	Vector2D& operator=(const Vector2D& rhs);

	float dotProduct(const Vector2D& rhs);
	float magnitude();

	Vector2D operator+(const Vector2D& rhs);
	Vector2D& operator+=(const Vector2D& rhs);
	Vector2D operator-(const Vector2D& rhs);
	Vector2D& operator-=(const Vector2D& rhs);
	Vector2D operator*(const int& rhs);
	Vector2D& operator*=(const int& rhs);
	Vector2D operator/(const int& rhs);
	Vector2D& operator/=(const int& rhs);

	bool operator==(const Vector2D& rhs);
};

