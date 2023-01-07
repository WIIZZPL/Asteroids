#include "Player.h"

#define N_VECTORS 4
#define SHIP_HEIGHT 0.025

#define ACCELERATION 1500
#define DRAG 0.98
#define THETA_V 5

Player::Player(unsigned int displayWidth, unsigned int displayHeight){
	
	float ship_radius = displayHeight * SHIP_HEIGHT;
	Vector2D* ship = new Vector2D[N_VECTORS];

	ship[0] = Vector2D(0, -ship_radius);
	ship[1] = Vector2D(-ship_radius, +ship_radius);
	ship[2] = Vector2D(0, ship_radius/2);
	ship[3] = Vector2D(+ship_radius, +ship_radius);

	polygon = new Polygon(N_VECTORS, ship);

	P = new Vector2D(displayWidth / 2, displayHeight / 2);
	D = new Vector2D(0, -1);
	V = new Vector2D();
	A = new Vector2D();
	theta = 0;

	colour = al_map_rgb(255, 255, 255);
	lineThickness = 2;
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
		*A = *D * ACCELERATION;
	}
	if (keyboardState[ALLEGRO_KEY_DOWN]) {
		keyboardState[ALLEGRO_KEY_DOWN] = keyboardState[ALLEGRO_KEY_DOWN] ^ 2;
		*A = Vector2D() - *D * ACCELERATION;
	}
	if (keyboardState[ALLEGRO_KEY_SPACE]) {
		keyboardState[ALLEGRO_KEY_SPACE] = keyboardState[ALLEGRO_KEY_SPACE] ^ 2;
		//TODO
		D->rotate(-theta);
		theta = 0;
	}
	if (keyboardState[ALLEGRO_KEY_RIGHT] || keyboardState[ALLEGRO_KEY_LEFT]) {

		if (keyboardState[ALLEGRO_KEY_RIGHT]) {
			keyboardState[ALLEGRO_KEY_RIGHT] = keyboardState[ALLEGRO_KEY_RIGHT] ^ 2;
			theta -= THETA_V * dt;
			D->rotate(-THETA_V * dt);
		}
		if (keyboardState[ALLEGRO_KEY_LEFT]) {
			keyboardState[ALLEGRO_KEY_LEFT] = keyboardState[ALLEGRO_KEY_LEFT] ^ 2;
			theta += THETA_V * dt;
			D->rotate(THETA_V * dt);
		};
		while (theta < 0) theta += 6.28318530718;
		while (theta > 6.28318530718) theta -= 6.28318530718;
	}

	*V *= DRAG;
	*V += *A * dt;
	*P += *V * dt;

	//Wrapping
	if (!polygon->isVisible(*P, theta, displayWidth, displayHeight)) {
		Vector2D H = polygon->getDimentions(theta);

		if (P->x < 0) P->x += displayWidth + H.x;
		else if (P->x > displayWidth) P->x -= displayWidth + H.x;
		if (P->y < 0) P->y += displayHeight + H.y;
		else if (P->y > displayHeight) P->y -= displayHeight + H.y;
	}
}

void Player::render(float lag){
	Vector2D p = Vector2D(*P) + *V * lag;
	polygon->draw(p, theta, colour, lineThickness);
}
