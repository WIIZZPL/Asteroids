#pragma once

#include <allegro5/allegro.h>

class Scene {
private:

public:
	virtual void processInput();
	virtual void update(double t, double dt);
	virtual void render(ALLEGRO_DISPLAY* display, double lag);
};