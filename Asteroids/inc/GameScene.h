#pragma once

#include <vector>
#include "Scene.h"
#include "Player.h"
#include "Asteroid.h"
#include "ColisionResponce.h"
#include "App.h"

class GameScene : public Scene {
private:
	static char keyboardState[];
	ALLEGRO_COLOR backgroundColor;

	unsigned long long int score;

	Player* player;
	unsigned short int lives;

	std::vector<Asteroid*> asteroids;
	float radiusAvailable;
	float asteroid_timer;

	void asteroidsSpawn(double dt);
	void colissionsHandling();

public:
	GameScene(unsigned int displayWidth, unsigned int displayHeight);
	~GameScene();
	void processInput(ALLEGRO_EVENT& event);
	void update(double dt);
	void render(double lag);
};