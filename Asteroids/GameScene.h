#pragma once

#include "Scene.h"

class GameScene : public Scene {
private:

public:
	void processInput();
	void update(double t, double dt);
	void render(ALLEGRO_DISPLAY* display, double lag);
};