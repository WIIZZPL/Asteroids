#include "Player.h"

#include <allegro5/allegro.h>
#include "App.h"

#define N_VECTORS 4
#define SHIP_HEIGHT 0.025f

#define ACCELERATION 1500
#define DRAG 0.98f
#define THETA_V 5

#define PI 3.14159265359f

Player::Player(){
	
	float ship_radius = App::getDisplayHeight() * SHIP_HEIGHT;
	Vector2D* ship = new Vector2D[N_VECTORS];

	ship[0] = Vector2D(0, -ship_radius);
	ship[1] = Vector2D(-ship_radius, +ship_radius);
	ship[2] = Vector2D(0, ship_radius/2);
	ship[3] = Vector2D(+ship_radius, +ship_radius);

	polygon = new Polygon(N_VECTORS, ship);

	P = Vector2D(App::getDisplayWidth() / 2, App::getDisplayHeight() / 2);
	D = Vector2D(0, -1);
	V = Vector2D();
	A = Vector2D();
	theta = 0;

	colour = al_map_rgb(255, 255, 255);
	lineThickness = 2;

	numberOfInstances++;
}

Player::~Player(){
	delete polygon;
	numberOfInstances--;
}

void Player::update(float dt, char* keyboardState){

	A -= A;

	if (keyboardState[ALLEGRO_KEY_UP]) {
		keyboardState[ALLEGRO_KEY_UP] = keyboardState[ALLEGRO_KEY_UP] ^ 2;
		A = D * ACCELERATION;
	}
	if (keyboardState[ALLEGRO_KEY_DOWN]) {
		keyboardState[ALLEGRO_KEY_DOWN] = keyboardState[ALLEGRO_KEY_DOWN] ^ 2;
		A = Vector2D() - D * ACCELERATION;
	}
	if (keyboardState[ALLEGRO_KEY_SPACE]) {
		keyboardState[ALLEGRO_KEY_SPACE] = keyboardState[ALLEGRO_KEY_SPACE] ^ 2;
		//TODO
		D.rotate(-theta);
		theta = 0;
	}
	if (keyboardState[ALLEGRO_KEY_RIGHT] || keyboardState[ALLEGRO_KEY_LEFT]) {

		if (keyboardState[ALLEGRO_KEY_RIGHT]) {
			keyboardState[ALLEGRO_KEY_RIGHT] = keyboardState[ALLEGRO_KEY_RIGHT] ^ 2;
			theta -= THETA_V * dt;
			D.rotate(-THETA_V * dt);
		}
		if (keyboardState[ALLEGRO_KEY_LEFT]) {
			keyboardState[ALLEGRO_KEY_LEFT] = keyboardState[ALLEGRO_KEY_LEFT] ^ 2;
			theta += THETA_V * dt;
			D.rotate(THETA_V * dt);
		};
		while (theta < 0) theta += 2.0f * PI;
		while (theta > 2.0f * PI) theta -= 2.0f * PI;
	}

	V *= DRAG;
	V += A * dt;
	P += V * dt;

	unsigned int displayWidth = App::getDisplayWidth();
	unsigned int displayHeight = App::getDisplayHeight();
	if (!polygon->isVisible(P, theta, displayWidth, displayHeight)) {
		wrapAroundScreen(displayWidth, displayHeight);
	}
}

void Player::render(float lag) const{
	Vector2D p = Vector2D(P) + V * lag;
	polygon->draw(p, theta, colour, lineThickness);
}
