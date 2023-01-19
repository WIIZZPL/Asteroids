#pragma once

#include "Object.h"

class Barrier : public Object{
private:
	bool active;

public:
	Barrier();
	~Barrier();
	void render(float lag) const;
	
	bool isActive() const;
	void toggle();
};

