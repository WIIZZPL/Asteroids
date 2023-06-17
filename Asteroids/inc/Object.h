#pragma once

#include <allegro5/allegro.h>
#include "Polygon.h"

/// <summary>
/// Klasa bazowa obiekt. Rodzic wszystkich obiekt�w z kt�rymi mo�na wej�� w interacje.
/// </summary>
class Object{
protected:
	/// <summary>
	/// Wska�nik na obiekt Polygon. Definuje on kszta�t obiektu oraz hitbox.
	/// </summary>
	Polygon* polygon;
	/// <summary>
	/// Vector2D pozycji.
	/// </summary>
	Vector2D P;
	/// <summary>
	/// Vector2D kierunku ruchu/rozmiaru.
	/// </summary>
	Vector2D D;
	/// <summary>
	/// Vector2D pr�dko�ci.
	/// </summary>
	Vector2D V;
	/// <summary>
	/// Vector2D przyspieszenia.
	/// </summary>
	Vector2D A;
	/// <summary>
	/// Zmienna przechowuj�ca obr�cenie poligonu.
	/// </summary>
	float theta;
	/// <summary>
	/// Pr�dko�� obr�cenia.
	/// </summary>
	float theta_v;
	/// <summary>
	/// Kolor bok�w poligonu.
	/// </summary>
	ALLEGRO_COLOR colour;
	/// <summary>
	/// Grubo�� lini poligonu.
	/// </summary>
	float lineThickness;

public:
	/// <summary>
	/// Fukcja sprawdzaj�ca kolizj� mi�dzy obiektem a punktem.
	/// </summary>
	/// <param name="A">Referencja do obiektu.</param>
	/// <param name="B">Referencja do punktu.</param>
	/// <returns>Czy koliduj�.</returns>
	static bool colissionObjectPoint(const Object& A, const Vector2D& B);
	/// <summary>
	/// Fukcja sprawdzaj�ca kolizj� mi�dzy obiektem a innym obiektem.
	/// </summary>
	/// <param name="A">Referencja do obiektu.</param>
	/// <param name="B">Referencja do obiektu.</param>
	/// <returns>Czy koliduj�.</returns>
	static bool colissionObjectObject(const Object& A, const Object& B);
	/// <summary>
	/// Obwija obiekt do oko�a ekranu. Tz. Obiekt kt�ry znajdzie si� na lewo poza oknem, przejdzie na prawo, i vice versa dla prawa, g�ry, i do�u.
	/// </summary>
	/// <param name="displayWidth">Szeroko�� okna w pikselach.</param>
	/// <param name="displayHeight">Wysoko�� okna w pikselach.</param>
	void wrapAroundScreen(unsigned int displayWidth, unsigned int displayHeight);
};

