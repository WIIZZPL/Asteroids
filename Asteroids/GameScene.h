#pragma once

#include <vector>
#include "Scene.h"
#include "Player.h"
#include "Asteroid.h"
#include "App.h"

class GameScene : public Scene {
private:
	static char keyboardState[];
	ALLEGRO_COLOR backgroundColor;

	Player* player;
	std::vector<Asteroid*> asteroids;
	float massAvailable;
	float asteroid_timer;

public:
	GameScene(unsigned int displayWidth, unsigned int displayHeight);
	~GameScene();
	void processInput(ALLEGRO_EVENT& event);
	void update(double dt);
	void render(double lag);
};