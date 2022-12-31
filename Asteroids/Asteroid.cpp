#include "Asteroid.h"

#define MIN_MASS 10
#define MAX_MASS 75
#define MIN_SIDES 8
#define MAX_SIDES 16
#define deviation 0.3

#define safety_radius 100

#define min_v 50
#define max_v 200
#define max_theta_v 15

Asteroid::Asteroid(unsigned int displayWidth, unsigned int displayHeight, Player& player, float r) : r(r) {
	int n = rand() % (MAX_SIDES - MIN_MASS) + MIN_SIDES;
	Vector2D* shape = new Vector2D[n];
	Vector2D D(0, -r);

	float a = 0; // previous steepness: a check to ensure there are no straight lines defined by 3 points
	for (int i = 0; i < n; i++) {
		float ca; //Current steepness;
		do {
			shape[i] = D;
			shape[i] *= 1 + deviation * ((float)rand() / RAND_MAX * 2 - 1);
			D.rotate(6.28318530718 / n);
			if (i == 0) ca = -1;
			else {
				ca = (shape[i].y - shape[i - 1].y) / (shape[i].x - shape[i - 1].x);
			}
		} while (a == ca);
		a = ca;
	}
	polygon = new Polygon(n, shape);

	P = new Vector2D(displayWidth/2, displayHeight/2);

	V = new Vector2D(0, -max_v * (float)rand() / RAND_MAX);
	V->y = fminf(-min_v, V->y);
	V->rotate(6.28318530718 * (float)rand() / RAND_MAX);

	theta = 0;
	theta_v = (float)rand() / RAND_MAX * max_theta_v / r;

	lineThickness = 3;
	asteroidColour = al_map_rgb(rand() % 192 + 64, rand() % 192 + 64, rand() % 192 + 64);
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
	polygon->draw(p, theta, asteroidColour, lineThickness);
	polygon->drawWireFrame(p, theta, asteroidColour, lineThickness);
}

Asteroid* Asteroid::AsteroidFactory(unsigned int displayWidth, unsigned int displayHeight, Player& player, float& massAvailable){
	if (massAvailable < MIN_MASS) return nullptr;
	float r = ((float)rand() / RAND_MAX) * (fminf(MAX_MASS, massAvailable) - MIN_MASS) + MIN_MASS;
	massAvailable -= r;
	return new Asteroid(displayWidth, displayHeight, player, r);
}
