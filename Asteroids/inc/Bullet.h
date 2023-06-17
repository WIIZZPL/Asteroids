#pragma once

#include "Object.h"

struct Vector2D;

/// <summary>
/// Klasa pocisku. Wystrzeliwany przez Player. Porusza si� ruchem jednostajnym prostoliniowym.
/// </summary>
class Bullet : public Object{
private:

public:
	/// <summary>
	/// Konstruktor. Wymaga pozycji i kierunku ruchu gracza. Pocisk b�dzie si� porusza� w kierunku playerD, z pr�dko�ci� BULLET_SPEED.
	/// </summary>
	/// <param name="playerP">Pozycja gracza.</param>
	/// <param name="playerD">Kierunek ruchu gracza.</param>
	Bullet(const Vector2D& playerP, const Vector2D& playerD);
	~Bullet();
	/// <summary>
	/// Uaktualnia stan pocisku.
	/// </summary>
	/// <param name="dt">Krok czasu.</param>
	void update(float dt);
	/// <summary>
	/// Renderuje pocisk na ekranie.
	/// </summary>
	/// <param name="lag">Op�nienie.</param>
	void render(float lag) const;
	/// <summary>
	/// Sprawdza czy pocisk jest poza ekranem. Je�li true powinien zosta� wtedy usuni�ty.
	/// </summary>
	/// <param name="displayWidth">Szeroko�� ekranu w pikselach.</param>
	/// <param name="displayHeight">Wysoko�� ekranu w pikselach</param>
	/// <returns>Czy pocisk jest poza ekranem.</returns>
	bool shouldBeRemoved(unsigned int displayWidth, unsigned int displayHeight);
};

