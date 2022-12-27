#pragma once

#include <allegro5/allegro.h>

class Scene {
private:

public:
	virtual void processInput(ALLEGRO_EVENT& event) = 0;
	virtual void update(double t, double dt) = 0;
	virtual void render(ALLEGRO_DISPLAY* display, double lag) = 0;
};