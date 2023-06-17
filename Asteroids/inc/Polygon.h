#pragma once

#include <vector>
#include "Vector2D.h"

struct ALLEGRO_COLOR;

/// <summary>
/// Klasa poligonu. Przechowuje kszta�t, oraz hitbox.
/// </summary>
class Polygon{
private:
	int size;
	Vector2D* points;
	Vector2D O;
	std::vector<Vector2D*> wireframe; // (size-2)*3 number of pointers to points, each three define a simplex

public:
	/// <summary>
	/// Konstruktor. Po przyj�ciu tablicy punkt�w tworzy hitbox.
	/// </summary>
	/// <param name="size">Rozmiar tablicy points.</param>
	/// <param name="points">Tablica punkt�w poligonu zapisana wed��g kierunku odwrotengo do wskaz�wek zegara.</param>
	Polygon(int size, Vector2D* points);
	~Polygon();
	/// <summary>
	/// Zwraca punkt centralny poligonu przy obrocie angle wok� �rodka.
	/// </summary>
	/// <param name="angle">K�t</param>
	/// <returns>Centroid poligonu</returns>
	Vector2D getCentrePoint(float angle);
	/// <summary>
	/// Renderuje poligon bez wype�nienia.
	/// </summary>
	/// <param name="P">Pozycja �rodka poligonu.</param>
	/// <param name="angle">K�t.</param>
	/// <param name="lineColour">Kolor lini.</param>
	/// <param name="lineThickness">Grubo�� lini.</param>
	void draw(const Vector2D& P, float angle, const ALLEGRO_COLOR& lineColour, float lineThickness) const;
	/// <summary>
	/// Renderuje poligon z wype�nieniem.
	/// </summary>
	/// <param name="P">Pozycja �rodka poligonu.</param>
	/// <param name="angle">K�t.</param>
	/// <param name="lineColour">Kolor lini.</param>
	/// <param name="lineThickness">Grubo�� lini.</param>
	/// <param name="fillColour">Kolor wype�nienia.</param>
	void draw(const Vector2D& P, float angle, const ALLEGRO_COLOR& lineColour, float lineThickness, const ALLEGRO_COLOR& fillColour) const;
	/// <summary>
	/// Rysuje hitbox poligonu.
	/// </summary>
	/// <param name="P">Pozycja �rodka poligonu.</param>
	/// <param name="angle">K�t.</param>
	/// <param name="lineColour">Kolor lini.</param>
	/// <param name="lineThickness">Grubo�� lini.</param>
	void drawWireFrame(const Vector2D& P, float angle, const ALLEGRO_COLOR& lineColour, float lineThickness) const;
	/// <summary>
	/// Sprawdza czy poligon jest widoczny
	/// </summary>
	/// <param name="P">Pozycja �rodka poligonu.</param>
	/// <param name="angle">K�t.</param>
	/// <param name="displayWidth">Szeroko�� okna w pikselach.</param>
	/// <param name="displayHeight">Wysoko�� okna w pikselach.</param>
	/// <param name="margin">Margines</param>
	/// <returns>Czy poligon jest widoczny.</returns>
	bool isVisible(const Vector2D& P, float angle, unsigned int displayWidth, unsigned int displayHeight, float margin = 0) const;
	/// <summary>
	/// Zwraca warto�ci osi x dla najbardziej wysuni�tych na nich punktach.
	/// </summary>
	/// <param name="angle">K�t</param>
	/// <returns>Vector2D, .x �ajbaridzje wysuni�ty w stron� ujemn�, .y - dodatni�.</returns>
	Vector2D getWidthMagnitudes(float angle) const;
	/// <summary>
	/// Zwraca warto�ci osi y dla najbardziej wysuni�tych na nich punktach.
	/// </summary>
	/// <param name="angle">K�t</param>
	/// <returns>Vector2D, .x �ajbaridzje wysuni�ty w stron� ujemn�, .y - dodatni�.</returns>
	Vector2D getHeightMagnitudes(float angle) const;
	/// <summary>
	/// Zwraca wymiary poligonu.
	/// </summary>
	/// <param name="angle">K�t.</param>
	/// <returns>Vector2D, .x - szeroko��, .y - wysoko��</returns>
	Vector2D getDimentions(float angle) const;
	/// <summary>
	/// Sprawdza kolizj� mi�dzy poligonem a punktem.
	/// </summary>
	/// <param name="polygon">Poligon P</param>
	/// <param name="P">Pozycja poligonu P</param>
	/// <param name="angleP">K�t poligonu P</param>
	/// <param name="R">Punkt R</param>
	/// <returns>Czy poligon P koliduje z punktem R</returns>
	static bool collisionPolygonPoint(const Polygon& polygon, const Vector2D& P, float angleP, const Vector2D& R);
	/// <summary>
	/// Sprawdza kolizj� mi�dzy dwoma poligonami.
	/// </summary>
	/// <param name="polygon">Poligon P</param>
	/// <param name="P">Pozycja P</param>
	/// <param name="angleP">K�t P</param>
	/// <param name="otherPolygon">Poligon R</param>
	/// <param name="R">pozycja R</param>
	/// <param name="angleR">K�t R</param>
	/// <returns>Czy poligon P koliduje z poligonem R</returns>
	static bool collisionPolygonPolygon(const Polygon& polygon, const Vector2D& P, float angleP, const Polygon& otherPolygon, const Vector2D& R, float angleR);
};

