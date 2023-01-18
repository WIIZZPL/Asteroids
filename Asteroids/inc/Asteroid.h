#pragma once

#include "Object.h"

#include <vector>

class Asteroid : public Object {
private:
	const float radius;

public:
	Asteroid(unsigned int displayWidth, unsigned int displayHeight, Object& player, float r);
	Asteroid(Vector2D P, float r);
	~Asteroid();

	void update(float dt);
	void render(float lag) const;

	static Asteroid* AsteroidFactory(unsigned int displayWidth, unsigned int displayHeight, Object& player, float& radiusAvailable);
	void AsteroidBreak(unsigned int displayWidth, unsigned int displayHeight, std::vector<Asteroid*>& asteroids, float& radiusAvailable, unsigned long long int& score);

	friend struct ColisionResponce;
};

