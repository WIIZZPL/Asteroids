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
	/// Generowana jest w losowym miejscu poza ekranem, w odleg�o�ci od gracza wi�kszej ni� SAFETY_RADIUS.
	/// Pr�dko�� i kierunek jest losowy, przyspieszenie zerowe.
	/// Kszta�tem asteroidy jest losowo wygenerowany wielok�t, ma on od MIN_SIDES do MAX_SIDES bok�w, a ka�dy kont jest oddalony od �rodka o radius +- DEVIATION.
	/// </summary>
	/// <param name="displayWidth">Szeroko�� ekranu w pikselach.</param>
	/// <param name="displayHeight">Wysoko�� ekranu w pikselach.</param>
	/// <param name="player">Referencja do gracza.</param>
	/// <param name="r">Promie� asteroidy</param>
	Asteroid(unsigned int displayWidth, unsigned int displayHeight, Object& player, float r);
	/// <summary>
	/// Konstruktor asterodiy - dla od�amk�w.
	/// Kszta�t asteroid jest generowany w ten sam spos�b co dla Asteroid(unsigned int displayWidth, unsigned int displayHeight, Object& player, float r).
	/// Lecz pozycja jest podawana jako parametr.
	/// </summary>
	/// <param name="P">Pozycja asteroidy.</param>
	/// <param name="r">Promie� asteroidy</param>
	Asteroid(Vector2D P, float r);
	~Asteroid();

	/// <summary>
	/// Uaktualnia stan asteroidy.
	/// </summary>
	/// <param name="dt">krok czasu.</param>
	void update(float dt);
	/// <summary>
	/// Renderuje asteroid�.
	/// </summary>
	/// <param name="lag">Op�nienie.</param>
	void render(float lag) const;
	/// <summary>
	/// Fabryka asteroid. Sprawdza czy ilo�� dost�pnego promienia (radiusAvailable) jest wi�ksza ni� MIN_SPAWN_RADIUS. Je�li nie, zwraca nullptr.
	/// W przeciwnym wypadku wybiera losow� warto�� z przedzia�u od MIN_SPAWN_RADIUS do min(MAX_SPAWN_RADIUS, radiusAvailable).
	/// Poczym zwraca wska�nik na now� asteroid� o tym rozmiarze.
	/// </summary>
	/// <param name="displayWidth">Szeroko�� okna w pikselach.</param>
	/// <param name="displayHeight">Wysoko�� okna w pikselach.</param>
	/// <param name="player">Referencja do gracza.</param>
	/// <param name="radiusAvailable">Referencja do dost�pnej ilo�ci promienia.</param>
	/// <returns>nullptr lub wska�nik na now� asteroid�.</returns>
	static Asteroid* AsteroidFactory(unsigned int displayWidth, unsigned int displayHeight, Object& player, float& radiusAvailable);
	/// <summary>
	/// Rozbija asteroid�.
	/// Je�li radius/2 > MIN_RADIUS, tworzone s� dwie nowe asteroidy o tym rozmiarze, na pozycji asteroidy, i zostaj� umieszczone w asteroids.
	/// W przeciwnym razie score jest zwi�kszany o POINTS_FOR_BREAK * radius, i radiusAvailable jest zwi�kszany o radius.
	/// </summary>
	/// <param name="asteroids">Referencja do vector'a wska�nik�w na asteroidy.</param>
	/// <param name="radiusAvailable">Referencja do ilo�ci dost�pnego promienia.</param>
	/// <param name="score">Referencja do licznika punkt�w.</param>
	void AsteroidBreak(std::vector<Asteroid*>& asteroids, float& radiusAvailable, unsigned long long int& score);

	float getRadius() { return radius; }
};

