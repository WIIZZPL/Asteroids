#pragma once

#include "Object.h"

#include <vector>

/// <summary>
/// Klasa asteroidy.
/// </summary>
class Asteroid : public Object {
private:
	const float radius;

public:
	/// <summary>
	/// Konstruktor asteroidy - dla tworzenia.
	/// Generowana jest w losowym miejscu poza ekranem, w odleg³oœci od gracza wiêkszej ni¿ SAFETY_RADIUS.
	/// Prêdkoœæ i kierunek jest losowy, przyspieszenie zerowe.
	/// Kszta³tem asteroidy jest losowo wygenerowany wielok¹t, ma on od MIN_SIDES do MAX_SIDES boków, a ka¿dy kont jest oddalony od œrodka o radius +- DEVIATION.
	/// </summary>
	/// <param name="displayWidth">Szerokoœæ ekranu w pikselach.</param>
	/// <param name="displayHeight">Wysokoœæ ekranu w pikselach.</param>
	/// <param name="player">Referencja do gracza.</param>
	/// <param name="r">Promieñ asteroidy</param>
	Asteroid(unsigned int displayWidth, unsigned int displayHeight, Object& player, float r);
	/// <summary>
	/// Konstruktor asterodiy - dla od³amków.
	/// Kszta³t asteroid jest generowany w ten sam sposób co dla Asteroid(unsigned int displayWidth, unsigned int displayHeight, Object& player, float r).
	/// Lecz pozycja jest podawana jako parametr.
	/// </summary>
	/// <param name="P">Pozycja asteroidy.</param>
	/// <param name="r">Promieñ asteroidy</param>
	Asteroid(Vector2D P, float r);
	~Asteroid();

	/// <summary>
	/// Uaktualnia stan asteroidy.
	/// </summary>
	/// <param name="dt">krok czasu.</param>
	void update(float dt);
	/// <summary>
	/// Renderuje asteroidê.
	/// </summary>
	/// <param name="lag">OpóŸnienie.</param>
	void render(float lag) const;
	/// <summary>
	/// Fabryka asteroid. Sprawdza czy iloœæ dostêpnego promienia (radiusAvailable) jest wiêksza ni¿ MIN_SPAWN_RADIUS. Jeœli nie, zwraca nullptr.
	/// W przeciwnym wypadku wybiera losow¹ wartoœæ z przedzia³u od MIN_SPAWN_RADIUS do min(MAX_SPAWN_RADIUS, radiusAvailable).
	/// Poczym zwraca wskaŸnik na now¹ asteroidê o tym rozmiarze.
	/// </summary>
	/// <param name="displayWidth">Szerokoœæ okna w pikselach.</param>
	/// <param name="displayHeight">Wysokoœæ okna w pikselach.</param>
	/// <param name="player">Referencja do gracza.</param>
	/// <param name="radiusAvailable">Referencja do dostêpnej iloœci promienia.</param>
	/// <returns>nullptr lub wskaŸnik na now¹ asteroidê.</returns>
	static Asteroid* AsteroidFactory(unsigned int displayWidth, unsigned int displayHeight, Object& player, float& radiusAvailable);
	/// <summary>
	/// Rozbija asteroidê.
	/// Jeœli radius/2 > MIN_RADIUS, tworzone s¹ dwie nowe asteroidy o tym rozmiarze, na pozycji asteroidy, i zostaj¹ umieszczone w asteroids.
	/// W przeciwnym razie score jest zwiêkszany o POINTS_FOR_BREAK * radius, i radiusAvailable jest zwiêkszany o radius.
	/// </summary>
	/// <param name="asteroids">Referencja do vector'a wskaŸników na asteroidy.</param>
	/// <param name="radiusAvailable">Referencja do iloœci dostêpnego promienia.</param>
	/// <param name="score">Referencja do licznika punktów.</param>
	void AsteroidBreak(std::vector<Asteroid*>& asteroids, float& radiusAvailable, unsigned long long int& score);

	float getRadius() { return radius; }
};

