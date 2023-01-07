#include "Asteroid.h"

#define MIN_RADIUS 10
#define MIN_SPAWN_RADIUS 35
#define MAX_SPAWN_RADIUS 75
#define MIN_SIDES 8
#define MAX_SIDES 16
#define DEVIATION 0.3

#define SAFETY_RADIUS 100

#define MIN_V 50
#define MAX_V 200
#define MAX_THETA_V 20

Asteroid::Asteroid(unsigned int displayWidth, unsigned int displayHeight, Object& player, float r) : mass(3.14159265359 * r * r) {
	int n = rand() % (MAX_SIDES - MIN_SIDES) + MIN_SIDES;
	Vector2D* shape = new Vector2D[n];
	Vector2D D(0, -r);

	float a = 0; // previous steepness: a check to ensure there are no straight lines defined by 3 points
	for (int i = 0; i < n; i++) {
		float ca; //Current steepness;
		do {
			shape[i] = D;
			shape[i] *= 1 + DEVIATION * ((float)rand() / RAND_MAX * 2 - 1);
			D.rotate(6.28318530718 / n);
			if (i == 0) ca = -1;
			else {
				ca = (shape[i].y - shape[i - 1].y) / (shape[i].x - shape[i - 1].x);
			}
		} while (a == ca);
		a = ca;
	}
	polygon = new Polygon(n, shape);

	P = new Vector2D(displayWidth*(float)rand()/RAND_MAX, displayHeight * (float)rand() / RAND_MAX);

	V = new Vector2D(0, -MAX_V * (float)rand() / RAND_MAX);
	V->y = fminf(-MIN_V, V->y);
	V->rotate(6.28318530718 * (float)rand() / RAND_MAX);

	theta = 0;
	theta_v = (float)rand() / RAND_MAX * MAX_THETA_V / r;

	lineThickness = 3;
	colour = al_map_rgb(rand() % 192 + 64, rand() % 192 + 64, rand() % 192 + 64);
}

Asteroid::~Asteroid(){
	delete polygon;
	delete P;
	delete V;
}

void Asteroid::update(float dt, unsigned int displayWidth, unsigned int displayHeight){
	*P += *V * dt;
	theta += theta_v * dt;

	//Wrapping
	if (!polygon->isVisible(*P, theta, displayWidth, displayHeight)) {
		Vector2D H = polygon->getDimentions(theta);

		if (P->x < 0) P->x += displayWidth + H.x;
		else if (P->x > displayWidth) P->x -= displayWidth + H.x;
		if (P->y < 0) P->y += displayHeight + H.y;
		else if (P->y > displayHeight) P->y -= displayHeight + H.y;
	}
}

void Asteroid::render(float lag){
	Vector2D p = Vector2D(*P) + *V * lag;
	polygon->draw(p, theta, colour, lineThickness);
	polygon->drawWireFrame(p, theta, colour, lineThickness);
}

Asteroid* Asteroid::AsteroidFactory(unsigned int displayWidth, unsigned int displayHeight, Object& player, float& radiusAvailable){
	if (radiusAvailable < MIN_SPAWN_RADIUS) return nullptr;
	float r = ((float)rand() / RAND_MAX) * (fminf(MAX_SPAWN_RADIUS, radiusAvailable) - MIN_SPAWN_RADIUS) + MIN_SPAWN_RADIUS;
	radiusAvailable -= r;
	return new Asteroid(displayWidth, displayHeight, player, r);
}
