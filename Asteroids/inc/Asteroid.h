#pragma once

#include "Object.h"
#include "ColisionResponce.h"

class Asteroid : public Object {
private:
	float mass;

public:
	Asteroid(unsigned int displayWidth, unsigned int displayHeight, Object& player, float r);
	~Asteroid();

	void update(float dt, unsigned int displayWidth, unsigned int displayHeight);
	void render(float lag);

	static Asteroid* AsteroidFactory(unsigned int displayWidth, unsigned int displayHeight, Object& player, float& radiusAvailable);

	friend struct ColisionResponce;
};

