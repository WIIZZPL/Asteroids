#pragma once

#include "Object.h"

class Player : public Object {
private:
	//Thruster* thruster;

public:
	Player();
	~Player();

	void update(float dt, char* keyboardState);
	void render(float lag) const;

	friend struct CollisionResponce;
};

