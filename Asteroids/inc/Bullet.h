#pragma once

#include "Object.h"

struct Vector2D;

class Bullet : public Object{
private:

public:
	Bullet(const Vector2D& playerP, const Vector2D& playerD);
	~Bullet();
	void update(float dt);
	void render(float lag) const;
	bool shouldBeRemoved(unsigned int displayWidth, unsigned int displayHeight);
};

