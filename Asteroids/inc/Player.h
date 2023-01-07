#pragma once

#include "Object.h"
#include "ColisionResponce.h"

class Player : public Object {
private:
	//Thruster* thruster;

public:
	Player(unsigned int displayWidth, unsigned int displayHeight);
	~Player();

	void update(float dt, char* keyboardState, unsigned int displayWidth, unsigned int displayHeight);
	void render(float lag);
};

