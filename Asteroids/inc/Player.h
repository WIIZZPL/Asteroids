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
	/// Uaktualnia stan gracza. Przesuwa go wedle prêdkoœci i przyspieszenia. Jeœli keyboardState wykazuje wciœniêcie klawiszy góra-dó³, odpowiednio przyspiesza w tym kierunku;
	/// Jeœli natomiast wykazuje lewo-prawo, obraca graczem; A jeœli spacjê, tworzy nowy obiekt Bullet i umieszcza wskaŸnik w vector'ze bullets.
	/// </summary>
	/// <param name="dt"> krok czasu. </param>
	/// <param name="keyboardState"> tablica ze wciœniêtymi klawiszami. </param>
	/// <param name="bullets"> referencja na vector wskaŸników na bullet. </param>
	void update(float dt, char* keyboardState, std::vector<Bullet*>& bullets);
	/// <summary>
	/// Renderuje gracza.
	/// </summary>
	/// <param name="lag"> opóŸnienie. </param>
	void render(float lag) const;
	/// <summary>
	/// Funkcja resetuj¹ca gracza w stan pocz¹tkowy; Tz. Na œrodek ekranu, skierowany ku górze.
	/// </summary>
	void reset();
};

