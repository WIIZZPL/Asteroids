#include "Asteroid.h"

#include "App.h"
#include <math.h>

#define MIN_RADIUS 10
#define MIN_SPAWN_RADIUS 50
#define MAX_SPAWN_RADIUS 100
#define MIN_SIDES 8
#define MAX_SIDES 16
#define DEVIATION 0.3f

#define SAFETY_RADIUS 100

#define MIN_V 50
#define MAX_V 200
#define MAX_THETA_V 20

#define POINTS_FOR_BREAK 10

#define PI 3.14159265359f

Asteroid::Asteroid(unsigned int displayWidth, unsigned int displayHeight, Object& player, float r) : radius(r) {
	int noSides = rand() % (MAX_SIDES - MIN_SIDES) + MIN_SIDES;
	Vector2D* shape = new Vector2D[noSides];
	Vector2D D(0, -r);

	float prevSteepnes = 0;
	for (int i = 0; i < noSides; i++) {
		float currSteepness; //Current steepness;
		do {
			shape[i] = D;
			shape[i] *= 1 + DEVIATION * ((float)rand() / RAND_MAX * 2 - 1);
			D.rotate(2.0f * PI / noSides);
			if (i == 0) currSteepness = -1;
			else {
				currSteepness = (shape[i].y - shape[i - 1].y) / (shape[i].x - shape[i - 1].x);
			}
		} while (prevSteepnes == currSteepness);
		prevSteepnes = currSteepness;
	}
	polygon = new Polygon(noSides, shape);

	V = Vector2D(0, -MAX_V * (float)rand() / RAND_MAX);
	V.y = fminf(-MIN_V, V.y);
	V.rotate(2.0f * PI * (float)rand() / RAND_MAX);

	theta = 0;
	theta_v = (float)rand() / RAND_MAX * MAX_THETA_V / r;

	lineThickness = 3;
	colour = al_map_rgb(rand() % 192 + 64, rand() % 192 + 64, rand() % 192 + 64);

	//Pozycja losowa i przesuniêta wedle prêdkoœci - y=ax+b
	P = Vector2D(displayWidth * (float)rand() / RAND_MAX, displayHeight * (float)rand() / RAND_MAX);
	Vector2D HX = polygon->getWidthMagnitudes(theta);
	Vector2D HY = polygon->getHeightMagnitudes(theta);
	float a = V.y / V.x;
	float b = P.y - a * P.x;
	
	std::vector<Vector2D> candidatePoints;

	Vector2D candidatePoint((HY.x - b) / a, HY.x);
	if (HX.x <= candidatePoint.x && candidatePoint.x <= displayWidth + HX.y) candidatePoints.push_back(candidatePoint);
	candidatePoint = Vector2D((displayHeight + HY.y - b) / a, displayHeight + HY.y);
	if (HX.x <= candidatePoint.x && candidatePoint.x <= displayWidth + HX.y) candidatePoints.push_back(candidatePoint);

	candidatePoint =  Vector2D(HX.x, (HX.x) * a + b);
	if (HY.x <= candidatePoint.y && candidatePoint.y <= displayHeight + HY.y) candidatePoints.push_back(candidatePoint);
	candidatePoint = Vector2D(displayWidth + HX.y, (displayWidth + HX.y) * a + b);
	if (HY.x <= candidatePoint.y && candidatePoint.y <= displayHeight + HY.y) candidatePoints.push_back(candidatePoint);

	P = candidatePoints[rand() % candidatePoints.size()];
}

Asteroid::Asteroid(Vector2D P, float r) : radius(r) {
	this->P = P;
	int noSides = rand() % (MAX_SIDES - MIN_SIDES) + MIN_SIDES;
	Vector2D* shape = new Vector2D[noSides];
	Vector2D D(0, -r);

	float prevSteepnes = 0;
	for (int i = 0; i < noSides; i++) {
		float currSteepness; //Current steepness;
		do {
			shape[i] = D;
			shape[i] *= 1 + DEVIATION * ((float)rand() / RAND_MAX * 2 - 1);
			D.rotate(2.0f * PI / noSides);
			if (i == 0) currSteepness = -1;
			else {
				currSteepness = (shape[i].y - shape[i - 1].y) / (shape[i].x - shape[i - 1].x);
			}
		} while (prevSteepnes == currSteepness);
		prevSteepnes = currSteepness;
	}
	polygon = new Polygon(noSides, shape);

	V = Vector2D(0, -MAX_V * (float)rand() / RAND_MAX);
	V.y = fminf(-MIN_V, V.y);
	V.rotate(2.0f * PI * (float)rand() / RAND_MAX);

	theta = 0;
	theta_v = (float)rand() / RAND_MAX * MAX_THETA_V / r;

	lineThickness = 3;
	colour = al_map_rgb(rand() % 192 + 64, rand() % 192 + 64, rand() % 192 + 64);
}

Asteroid::~Asteroid(){
	delete polygon;
}

void Asteroid::update(float dt){
	P += V * dt;
	theta += theta_v * dt;


	unsigned int displayWidth = App::getDisplayWidth();
	unsigned int displayHeight = App::getDisplayHeight();
	if (!polygon->isVisible(P, theta, displayWidth, displayHeight)) {
		wrapAroundScreen(displayWidth, displayHeight);
	}
}

void Asteroid::render(float lag) const{
	Vector2D p = Vector2D(P) + V * lag;
	polygon->draw(p, theta, colour, lineThickness);
	polygon->drawWireFrame(p, theta, colour, lineThickness);
}

Asteroid* Asteroid::AsteroidFactory(unsigned int displayWidth, unsigned int displayHeight, Object& player, float& radiusAvailable){
	if (radiusAvailable < MIN_SPAWN_RADIUS) return nullptr;
	float r = ((float)rand() / RAND_MAX) * (fminf(MAX_SPAWN_RADIUS, radiusAvailable) - MIN_SPAWN_RADIUS) + MIN_SPAWN_RADIUS;
	radiusAvailable -= r;
	return new Asteroid(displayWidth, displayHeight, player, r);
}

void Asteroid::AsteroidBreak(std::vector<Asteroid*>& asteroids, float& radiusAvailable, unsigned long long int& score) {
	if (this->radius / 2 < MIN_RADIUS) {
		radiusAvailable += this->radius;
		score += POINTS_FOR_BREAK * this->radius;
	}
	else {
		asteroids.push_back(new Asteroid(this->P, this->radius / 2));
		asteroids.push_back(new Asteroid(this->P, this->radius / 2));
	}
}