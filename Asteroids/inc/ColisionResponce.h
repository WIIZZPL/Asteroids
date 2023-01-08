#pragma once

class Player;
class Bullet;
class Barrier;
class Asteroid;

struct ColisionResponce {
	static void asteroidAsteroid(Asteroid& asteroidA, Asteroid& asteroidB);
};