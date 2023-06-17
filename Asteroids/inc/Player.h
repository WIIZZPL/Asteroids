#pragma once

#include "Object.h"
#include <vector>

class Bullet;

/// <summary>
/// Klasa gracza. Kierowana przez urzytkownika.
/// </summary>
class Player : public Object {
private:
	//Thruster* thruster;
	float bulletTimer;

public:
	Player();
	~Player();
	/// <summary>
	/// Uaktualnia stan gracza. Przesuwa go wedle pr�dko�ci i przyspieszenia. Je�li keyboardState wykazuje wci�ni�cie klawiszy g�ra-d�, odpowiednio przyspiesza w tym kierunku;
	/// Je�li natomiast wykazuje lewo-prawo, obraca graczem; A je�li spacj�, tworzy nowy obiekt Bullet i umieszcza wska�nik w vector'ze bullets.
	/// </summary>
	/// <param name="dt"> krok czasu. </param>
	/// <param name="keyboardState"> tablica ze wci�ni�tymi klawiszami. </param>
	/// <param name="bullets"> referencja na vector wska�nik�w na bullet. </param>
	void update(float dt, char* keyboardState, std::vector<Bullet*>& bullets);
	/// <summary>
	/// Renderuje gracza.
	/// </summary>
	/// <param name="lag"> op�nienie. </param>
	void render(float lag) const;
	/// <summary>
	/// Funkcja resetuj�ca gracza w stan pocz�tkowy; Tz. Na �rodek ekranu, skierowany ku g�rze.
	/// </summary>
	void reset();
};

