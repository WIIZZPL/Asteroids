#pragma once

#include "Scene.h"

class GameScene : public Scene {
private:

public:
	GameScene();
	~GameScene();
	void processInput(ALLEGRO_EVENT& event);
	void update(double t, double dt);
	void render(ALLEGRO_DISPLAY* display, double lag);
};