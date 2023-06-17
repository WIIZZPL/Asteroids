#pragma once

#include "Object.h"

struct Vector2D;

/// <summary>
/// Klasa pocisku. Wystrzeliwany przez Player. Porusza siê ruchem jednostajnym prostoliniowym.
/// </summary>
class Bullet : public Object{
private:

public:
	/// <summary>
	/// Konstruktor. Wymaga pozycji i kierunku ruchu gracza. Pocisk bêdzie siê porusza³ w kierunku playerD, z prêdkoœci¹ BULLET_SPEED.
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
	/// <param name="lag">OpóŸnienie.</param>
	void render(float lag) const;
	/// <summary>
	/// Sprawdza czy pocisk jest poza ekranem. Jeœli true powinien zostaæ wtedy usuniêty.
	/// </summary>
	/// <param name="displayWidth">Szerokoœæ ekranu w pikselach.</param>
	/// <param name="displayHeight">Wysokoœæ ekranu w pikselach</param>
	/// <returns>Czy pocisk jest poza ekranem.</returns>
	bool shouldBeRemoved(unsigned int displayWidth, unsigned int displayHeight);
};

