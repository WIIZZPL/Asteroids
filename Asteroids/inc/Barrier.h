#pragma once

#include "Object.h"

/// <summary>
/// Klasa bariery. S³u¿y do os³oniêcia gracza przed asteroidami na pacz¹tku gry i po œmierci.
/// Zastêpujê tzw. I-frames. Poniewa¿ obiekt jest nieruchomy, nieposiada funkcji update().
/// </summary>
class Barrier : public Object{
private:
	/// <summary>
	/// Czy bariera jest aktywna, jeœli nie, nie powinna byæ brana pod uwagê.
	/// </summary>
	bool active;

public:
	Barrier();
	~Barrier();
	/// <summary>
	/// Renderuje barierê.
	/// </summary>
	/// <param name="lag">OpóŸnienie.</param>
	void render(float lag) const;
	
	/// <summary>
	/// Zwraca stan pola active.
	/// </summary>
	/// <returns>aktywnoœæ bariery.</returns>
	bool isActive() const;
	/// <summary>
	/// Prze³¹cza aktywnoœæ bariery na swoj¹ odwrotnoœæ. Tz. Aktywna stajê siê nieaktywna; nieaktywna staje siê aktywna.
	/// </summary>
	void toggle();
};

