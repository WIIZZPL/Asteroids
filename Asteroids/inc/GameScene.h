#pragma once

#include <vector>
#include <allegro5/allegro.h>

#include "Scene.h"

#include "Barrier.h"

class Player;
class Asteroid;
class Bullet;
struct ALLEGRO_FONT;

/// <summary>
/// Scena gry faktycznej. Przechowuje gracza, asteroidy, pociski, barierê, iloœæ ¿yæ i punktów, oraz iloœæ dostêpnej œrednicy dla Asteroid.
/// @see scene
/// </summary>
class GameScene : public Scene {
private:
	static char keyboardState[];
	const ALLEGRO_COLOR backgroundColour = al_map_rgb(0, 0, 0);
	const ALLEGRO_COLOR textColour = al_map_rgb(255, 255, 255);
	ALLEGRO_FONT* font;

	unsigned long long int score;

	Player* player;
	unsigned short int lives;

	std::vector<Asteroid*> asteroids;
	float radiusAvailable;
	float asteroidTimer;

	std::vector<Bullet*> bullets;

	Barrier barrier;

	void asteroidsSpawn(double dt);
	void colissionsHandling();

public:
	GameScene();
	~GameScene();
	void processInput(ALLEGRO_EVENT& event);
	void update(double dt);
	void render(double lag) const;
};