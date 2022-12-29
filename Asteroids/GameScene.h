#pragma once

#include "Scene.h"
#include "Player.h"
#include "App.h"

class GameScene : public Scene {
private:
	static char keyboardState[];
	ALLEGRO_COLOR backgroundColor;

	Player* player;

public:
	GameScene(unsigned int displayWidth, unsigned int displayHeight);
	~GameScene();
	void processInput(ALLEGRO_EVENT& event);
	void update(double dt);
	void render(double lag);
};