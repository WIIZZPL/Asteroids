#pragma once

#include "Object.h"

/// <summary>
/// Klasa bariery. S�u�y do os�oni�cia gracza przed asteroidami na pacz�tku gry i po �mierci.
/// Zast�puj� tzw. I-frames. Poniewa� obiekt jest nieruchomy, nieposiada funkcji update().
/// </summary>
class Barrier : public Object{
private:
	/// <summary>
	/// Czy bariera jest aktywna, je�li nie, nie powinna by� brana pod uwag�.
	/// </summary>
	bool active;

public:
	Barrier();
	~Barrier();
	/// <summary>
	/// Renderuje barier�.
	/// </summary>
	/// <param name="lag">Op�nienie.</param>
	void render(float lag) const;
	
	/// <summary>
	/// Zwraca stan pola active.
	/// </summary>
	/// <returns>aktywno�� bariery.</returns>
	bool isActive() const;
	/// <summary>
	/// Prze��cza aktywno�� bariery na swoj� odwrotno��. Tz. Aktywna staj� si� nieaktywna; nieaktywna staje si� aktywna.
	/// </summary>
	void toggle();
};

