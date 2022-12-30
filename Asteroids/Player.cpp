#include "Player.h"
#include <stdio.h>
#define acceleration 1500
#define drag 0.98
#define rotate_speed 5

Player::Player(unsigned int displayWidth, unsigned int displayHeight){
	
	float ship_radius = displayHeight * 0.025;
	Vector2D* ship = new Vector2D[3];

	ship[0] = Vector2D(0, -ship_radius);
	ship[1] = Vector2D(-ship_radius, +ship_radius);
	ship[2] = Vector2D(+ship_radius, +ship_radius);

	polygon = new Polygon(3, ship);

	P = new Vector2D(displayWidth / 2, displayHeight / 2);
	D = new Vector2D(0, -1);
	V = new Vector2D();
	A = new Vector2D();
	theta = 0;

	shipColour = al_map_rgb(255, 255, 255);
	lineThickness = 1;
}

Player::~Player(){
	delete polygon;
	delete P;
	delete D;
	delete V;
	delete A;
}

void Player::update(float dt, char* keyboardState, unsigned int displayWidth, unsigned int displayHeight){

	*A -= *A;

	if (keyboardState[ALLEGRO_KEY_UP]) {
		keyboardState[ALLEGRO_KEY_UP] = keyboardState[ALLEGRO_KEY_UP] ^ 2;
		*A = *D * acceleration;
	}
	if (keyboardState[ALLEGRO_KEY_DOWN]) {
		keyboardState[ALLEGRO_KEY_DOWN] = keyboardState[ALLEGRO_KEY_DOWN] ^ 2;
		*A = Vector2D() - *D * acceleration;
	}
	if (keyboardState[ALLEGRO_KEY_SPACE]) {
		keyboardState[ALLEGRO_KEY_SPACE] = keyboardState[ALLEGRO_KEY_SPACE] ^ 2;
		//TODO
	}
	if (keyboardState[ALLEGRO_KEY_RIGHT] || keyboardState[ALLEGRO_KEY_LEFT]) {

		if (keyboardState[ALLEGRO_KEY_RIGHT]) {
			keyboardState[ALLEGRO_KEY_RIGHT] = keyboardState[ALLEGRO_KEY_RIGHT] ^ 2;
			theta -= rotate_speed * dt;
			D->rotate(Vector2D(), -rotate_speed * dt);
		}
		if (keyboardState[ALLEGRO_KEY_LEFT]) {
			keyboardState[ALLEGRO_KEY_LEFT] = keyboardState[ALLEGRO_KEY_LEFT] ^ 2;
			theta += rotate_speed * dt;
			D->rotate(Vector2D(), rotate_speed * dt);
		};
		while (theta < 0) theta += 6.28318530718;
		while (theta > 6.28318530718) theta -= 6.28318530718;
	}

	*V *= drag;
	*V += *A * dt;
	*P += *V * dt;

	//Wrapping
	if (V->dotProduct(Vector2D(displayWidth/2, displayHeight/2) - *P) < 0 && !polygon->isVisible(*P, theta, displayWidth, displayHeight)) {
		Vector2D H = polygon->getPointFurthestFrom(*P, theta, Vector2D(displayWidth / 2, displayHeight / 2)) - polygon->getPointClosestFrom(*P, theta, Vector2D(displayWidth / 2, displayHeight / 2));

		if (P->x < 0) P->x += displayWidth - H.x;
		else if (P->x > displayWidth) P->x -= displayWidth + H.x;
		if (P->y < 0) P->y += displayHeight - H.y;
		else if (P->y > displayHeight) P->y -= displayHeight + H.y;
	}
}

void Player::render(float lag){
	Vector2D p = Vector2D(*P) + *V * lag;
	polygon->draw(p, theta, shipColour, lineThickness);
}
