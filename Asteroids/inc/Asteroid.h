#pragma once

#include "Object.h"

class Asteroid : public Object {
private:
	const float mass;

public:
	Asteroid(unsigned int displayWidth, unsigned int displayHeight, Object& player, float r);
	~Asteroid();

	void update(float dt);
	void render(float lag) const;

	static Asteroid* AsteroidFactory(unsigned int displayWidth, unsigned int displayHeight, Object& player, float& radiusAvailable);

	friend struct ColisionResponce;
};

