#include "Player.h"

#include <allegro5/allegro.h>
#include "App.h"
#include "Bullet.h"

#define N_VECTORS 4
#define SHIP_HEIGHT 20.0f

#define ACCELERATION 1500
#define DRAG 0.98f
#define THETA_V 5

#define BULLET_FIRE_TIMER 0.15f

#define PI 3.14159265359f

Player::Player(){
	Vector2D* ship = new Vector2D[N_VECTORS];

	ship[0] = Vector2D(0, -SHIP_HEIGHT);
	ship[1] = Vector2D(-SHIP_HEIGHT, +SHIP_HEIGHT);
	ship[2] = Vector2D(0, SHIP_HEIGHT /2);
	ship[3] = Vector2D(+SHIP_HEIGHT, +SHIP_HEIGHT);

	polygon = new Polygon(N_VECTORS, ship);
	
	P = Vector2D(App::getDisplayWidth() / 2, App::getDisplayHeight() / 2);
	D = Vector2D(0, -1);
	V = Vector2D();
	A = Vector2D();
	theta = 0;

	colour = al_map_rgb(255, 255, 255);
	lineThickness = 2;

	bulletTimer = 0;
}

Player::~Player(){
	delete polygon;
}

void Player::update(float dt, char* keyboardState, std::vector<Bullet*>& bullets){

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
		if (bulletTimer == BULLET_FIRE_TIMER) {
			bullets.push_back(new Bullet(P + D * SHIP_HEIGHT, D));
			bulletTimer = 0;
		}
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

	bulletTimer = fminf(bulletTimer+dt, BULLET_FIRE_TIMER);

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

void Player::reset(){
	P = Vector2D(App::getDisplayWidth() / 2, App::getDisplayHeight() / 2);
	D = Vector2D(0, -1);
	V = Vector2D();
	A = Vector2D();
	theta = 0;
}
