#pragma once
/// <summary>
/// Struktura Wektora dwuwymiarowego.
/// Przeci¹¿ona jest dla wielu operatorów umo¿liwiaj¹c ³atwiejsz¹ do zrozumienia matematykê liniow¹.
/// </summary>
struct Vector2D{
	/// <summary>
	/// Wartoœci x i y wektora.
	/// </summary>
	float x, y;
	/// <summary>
	/// Konstruktor domyœlny, wszystkie wartoœci na 0.
	/// </summary>
	Vector2D() : x(0), y(0) {};
	/// <summary>
	/// Konstruktor kopiuj¹cy.
	/// </summary>
	/// <param name="v">Vector2D do skopiowania</param>
	Vector2D(const Vector2D& v) : x(v.x), y(v.y) {};
	/// <summary>
	/// Konstruktor jednowartoœciowy, obie wartoœci na a.
	/// </summary>
	/// <param name="a">Wartoœæ obydwóch pól.</param>
	Vector2D(float a) : x(a), y(a) {};
	/// <summary>
	/// Konstruktor pe³ny.
	/// </summary>
	/// <param name="x">Wartoœæ x.</param>
	/// <param name="y">Wartoœæ y.</param>
	Vector2D(float x, float y) : x(x), y(y) {};

	Vector2D& operator=(const Vector2D& rhs);
	/// <summary>
	/// Zwraca iloczyn skalarny this o rhs.
	/// </summary>
	/// <param name="rhs"></param>
	/// <returns>Iloczyn skalarny</returns>
	float dotProduct(const Vector2D& rhs);
	/// <summary>
	/// Zwraca d³ugoœæ wektora.
	/// </summary>
	/// <returns>D³ugoœæ wektora.</returns>
	float magnitude();
	/// <summary>
	/// Obraca wektor o angle radianów wed³óg punktu 0,0.
	/// </summary>
	/// <param name="angle">K¹t.</param>
	void rotate(float angle);
	/// <summary>
	/// Zwraca wektor obrócony o angle radianów wed³óg punktu (0, 0).
	/// </summary>
	/// <param name="angle">K¹t.</param>
	/// <returns>Wektor obrócony o k¹t.</returns>
	Vector2D rotated(float angle) const;
	/// <summary>
	/// Obraca wektor o angle radianów wed³óg punktu O.
	/// </summary>
	/// <param name="O">Oœ obrotu.</param>
	/// <param name="angle">K¹t.</param>
	void rotateAround(const Vector2D& O, float angle);
	/// <summary>
	/// Zwraca wektor obrucony o angle radianów wed³óg punktu O.
	/// </summary>
	/// <param name="O">Oœ obrotu.</param>
	/// <param name="angle">K¹t.</param>
	/// <returns>Wektor obrucony o k¹t.</returns>
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
	/// Sprawdza czy wektory s¹ takie same.
	/// </summary>
	friend bool operator==(const Vector2D& lhs, const Vector2D& rhs);
	/// <summary>
	/// Sprawdza czy wektory s¹ inne.
	/// </summary>
	friend bool operator!=(const Vector2D& lhs, const Vector2D& rhs);
	/// <summary>
	/// Sprawdza czy d³ugoœæ wektora lhs jest mniejsza ni¿ rhs.
	/// </summary>
	friend bool operator<(const Vector2D& lhs, const Vector2D& rhs);
	/// <summary>
	/// Sprawdza czy d³ugoœæ wektora lhs jest mniejsza b¹dŸ równa rhs.
	/// </summary>
	friend bool operator<=(const Vector2D& lhs, const Vector2D& rhs);
	/// <summary>
	/// Sprawdza czy d³ugoœæ wektora lhs jest wiêksza ni¿ rhs.
	/// </summary>
	friend bool operator>(const Vector2D& lhs, const Vector2D& rhs);
	/// <summary>
	/// Sprawdza czy d³ugoœæ wektora lhs jest wiêksza b¹dŸ równa rhs.
	/// </summary>
	friend bool operator>=(const Vector2D& lhs, const Vector2D& rhs);
};

