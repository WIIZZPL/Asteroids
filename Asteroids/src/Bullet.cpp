#include "Bullet.h"

#include "App.h"

#define BULLET_SPEED 500;
#define BULLET_THETA_SPEED 5;

Bullet::Bullet(const Vector2D& playerP, const Vector2D& playerD) {
	P = playerP;
	V = playerD * BULLET_SPEED;
	theta = 0;
	theta_v = BULLET_THETA_SPEED;
	colour = al_map_rgb(230, 57, 70);
	lineThickness = 2;

	Vector2D* polygonPoints = new Vector2D[4];
	polygonPoints[0] = Vector2D(0, -5);
	polygonPoints[1] = Vector2D(-5, 0);
	polygonPoints[2] = Vector2D(0, 5);
	polygonPoints[3] = Vector2D(5, 0);
	polygon = new Polygon(4, polygonPoints);
}

Bullet::~Bullet() {
	delete polygon;
}

void Bullet::update(float dt){
	P += V * dt;
	theta += theta_v * dt;
}

void Bullet::render(float lag) const{
	Vector2D p = Vector2D(P) + V * lag;
	polygon->draw(p, theta, colour, lineThickness);
}

bool Bullet::shouldBeRemoved(unsigned int displayWidth, unsigned int displayHeight){
	return !polygon->isVisible(P, theta, displayWidth, displayWidth);
}
