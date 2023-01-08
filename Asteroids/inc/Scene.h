#pragma once

union ALLEGRO_EVENT;

class Scene {
private:

public:
	virtual void processInput(ALLEGRO_EVENT& event) = 0;
	virtual void update(double dt) = 0;
	virtual void render(double lag) const = 0;
};