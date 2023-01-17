#pragma once

#include <vector>
#include <allegro5/allegro.h>

#include "Scene.h"

class Player;
class Asteroid;
class Bullet;
class Polygon;

class GameScene : public Scene {
private:
	static char keyboardState[];
	const ALLEGRO_COLOR backgroundColor = al_map_rgb(0, 0, 0);

	unsigned long long int score;

	Player* player;
	unsigned short int lives;

	std::vector<Asteroid*> asteroids;
	float radiusAvailable;
	float asteroidTimer;

	std::vector<Bullet*> bullets;

	void asteroidsSpawn(double dt);
	void colissionsHandling();

public:
	GameScene();
	~GameScene();
	void processInput(ALLEGRO_EVENT& event);
	void update(double dt);
	void render(double lag) const;
};