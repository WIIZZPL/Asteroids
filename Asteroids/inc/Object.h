#pragma once

#include <allegro5/allegro.h>
#include "Polygon.h"

/// <summary>
/// Klasa bazowa obiekt. Rodzic wszystkich obiektów z którymi mo¿na wejœæ w interacje.
/// </summary>
class Object{
protected:
	/// <summary>
	/// WskaŸnik na obiekt Polygon. Definuje on kszta³t obiektu oraz hitbox.
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
	/// Vector2D prêdkoœci.
	/// </summary>
	Vector2D V;
	/// <summary>
	/// Vector2D przyspieszenia.
	/// </summary>
	Vector2D A;
	/// <summary>
	/// Zmienna przechowuj¹ca obrócenie poligonu.
	/// </summary>
	float theta;
	/// <summary>
	/// Prêdkoœæ obrócenia.
	/// </summary>
	float theta_v;
	/// <summary>
	/// Kolor boków poligonu.
	/// </summary>
	ALLEGRO_COLOR colour;
	/// <summary>
	/// Gruboœæ lini poligonu.
	/// </summary>
	float lineThickness;

public:
	/// <summary>
	/// Fukcja sprawdzaj¹ca kolizjê miêdzy obiektem a punktem.
	/// </summary>
	/// <param name="A">Referencja do obiektu.</param>
	/// <param name="B">Referencja do punktu.</param>
	/// <returns>Czy koliduj¹.</returns>
	static bool colissionObjectPoint(const Object& A, const Vector2D& B);
	/// <summary>
	/// Fukcja sprawdzaj¹ca kolizjê miêdzy obiektem a innym obiektem.
	/// </summary>
	/// <param name="A">Referencja do obiektu.</param>
	/// <param name="B">Referencja do obiektu.</param>
	/// <returns>Czy koliduj¹.</returns>
	static bool colissionObjectObject(const Object& A, const Object& B);
	/// <summary>
	/// Obwija obiekt do oko³a ekranu. Tz. Obiekt który znajdzie siê na lewo poza oknem, przejdzie na prawo, i vice versa dla prawa, góry, i do³u.
	/// </summary>
	/// <param name="displayWidth">Szerokoœæ okna w pikselach.</param>
	/// <param name="displayHeight">Wysokoœæ okna w pikselach.</param>
	void wrapAroundScreen(unsigned int displayWidth, unsigned int displayHeight);
};

