#pragma once
/// <summary>
/// Struktura Wektora dwuwymiarowego.
/// Przeci��ona jest dla wielu operator�w umo�liwiaj�c �atwiejsz� do zrozumienia matematyk� liniow�.
/// </summary>
struct Vector2D{
	/// <summary>
	/// Warto�ci x i y wektora.
	/// </summary>
	float x, y;
	/// <summary>
	/// Konstruktor domy�lny, wszystkie warto�ci na 0.
	/// </summary>
	Vector2D() : x(0), y(0) {};
	/// <summary>
	/// Konstruktor kopiuj�cy.
	/// </summary>
	/// <param name="v">Vector2D do skopiowania</param>
	Vector2D(const Vector2D& v) : x(v.x), y(v.y) {};
	/// <summary>
	/// Konstruktor jednowarto�ciowy, obie warto�ci na a.
	/// </summary>
	/// <param name="a">Warto�� obydw�ch p�l.</param>
	Vector2D(float a) : x(a), y(a) {};
	/// <summary>
	/// Konstruktor pe�ny.
	/// </summary>
	/// <param name="x">Warto�� x.</param>
	/// <param name="y">Warto�� y.</param>
	Vector2D(float x, float y) : x(x), y(y) {};

	Vector2D& operator=(const Vector2D& rhs);
	/// <summary>
	/// Zwraca iloczyn skalarny this o rhs.
	/// </summary>
	/// <param name="rhs"></param>
	/// <returns>Iloczyn skalarny</returns>
	float dotProduct(const Vector2D& rhs);
	/// <summary>
	/// Zwraca d�ugo�� wektora.
	/// </summary>
	/// <returns>D�ugo�� wektora.</returns>
	float magnitude();
	/// <summary>
	/// Obraca wektor o angle radian�w wed��g punktu 0,0.
	/// </summary>
	/// <param name="angle">K�t.</param>
	void rotate(float angle);
	/// <summary>
	/// Zwraca wektor obr�cony o angle radian�w wed��g punktu (0, 0).
	/// </summary>
	/// <param name="angle">K�t.</param>
	/// <returns>Wektor obr�cony o k�t.</returns>
	Vector2D rotated(float angle) const;
	/// <summary>
	/// Obraca wektor o angle radian�w wed��g punktu O.
	/// </summary>
	/// <param name="O">O� obrotu.</param>
	/// <param name="angle">K�t.</param>
	void rotateAround(const Vector2D& O, float angle);
	/// <summary>
	/// Zwraca wektor obrucony o angle radian�w wed��g punktu O.
	/// </summary>
	/// <param name="O">O� obrotu.</param>
	/// <param name="angle">K�t.</param>
	/// <returns>Wektor obrucony o k�t.</returns>
	Vector2D rotatedAround(const Vector2D& O, float angle) const;

	friend Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
	friend Vector2D& operator+=(Vector2D& lhs, const Vector2D& rhs);
	friend Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);
	friend Vector2D& operator-=(Vector2D& lhs, const Vector2D& rhs);
	friend Vector2D operator*(const Vector2D& lhs, const float& rhs);
	friend Vector2D& operator*=(Vector2D& lhs, const float& rhs);
	friend Vector2D operator/(const Vector2D& lhs, const float& rhs);
	friend Vector2D& operator/=(Vector2D& lhs, const float& rhs);

	/// <summary>
	/// Sprawdza czy wektory s� takie same.
	/// </summary>
	friend bool operator==(const Vector2D& lhs, const Vector2D& rhs);
	/// <summary>
	/// Sprawdza czy wektory s� inne.
	/// </summary>
	friend bool operator!=(const Vector2D& lhs, const Vector2D& rhs);
	/// <summary>
	/// Sprawdza czy d�ugo�� wektora lhs jest mniejsza ni� rhs.
	/// </summary>
	friend bool operator<(const Vector2D& lhs, const Vector2D& rhs);
	/// <summary>
	/// Sprawdza czy d�ugo�� wektora lhs jest mniejsza b�d� r�wna rhs.
	/// </summary>
	friend bool operator<=(const Vector2D& lhs, const Vector2D& rhs);
	/// <summary>
	/// Sprawdza czy d�ugo�� wektora lhs jest wi�ksza ni� rhs.
	/// </summary>
	friend bool operator>(const Vector2D& lhs, const Vector2D& rhs);
	/// <summary>
	/// Sprawdza czy d�ugo�� wektora lhs jest wi�ksza b�d� r�wna rhs.
	/// </summary>
	friend bool operator>=(const Vector2D& lhs, const Vector2D& rhs);
};

