#pragma once

#include "Object.h"
#include <vector>

class Bullet;

class Player : public Object {
private:
	//Thruster* thruster;
	float bulletTimer;

public:
	Player();
	~Player();

	void update(float dt, char* keyboardState, std::vector<Bullet*>& bullets);
	void render(float lag) const;

	void reset();
};

