#pragma once

#include "Player.h"
#include "Asteroid.h"

class Asteroid;

struct ColisionResponce {
	static void asteroidAsteroid(Asteroid& asteroidA, Asteroid& asteroidB);
};