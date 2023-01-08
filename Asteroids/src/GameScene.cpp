#include "GameScene.h"

#include "Player.h"
#include "Asteroid.h"
#include "ColisionResponce.h"
#include "App.h"

#define STARTING_LIVES 3
#define MAX_TOTAL_RADIUS 1000
#define NEW_ASTEROID_TIMER 5
#define MIN_NO_ASTEROIDS 1
#define START_NO_ASTEROIDS 5

char GameScene::keyboardState[ALLEGRO_KEY_MAX];

GameScene::GameScene(){
	score = 0;

	player = new Player();
	lives = STARTING_LIVES;

	radiusAvailable = MAX_TOTAL_RADIUS;
	asteroidTimer = 0;
	while (asteroids.size() < START_NO_ASTEROIDS) {
		Asteroid* newAsteroid = Asteroid::AsteroidFactory(App::getDisplayWidth(), App::getDisplayHeight(), *player, radiusAvailable);
		if (newAsteroid != nullptr) asteroids.push_back(newAsteroid);
	}
}

GameScene::~GameScene(){
	delete player;
	for (auto& asteroid : asteroids) delete asteroid;
}

void GameScene::processInput(ALLEGRO_EVENT& event){
	do {
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			keyboardState[event.keyboard.keycode] = 3;
		}
		else if (event.type == ALLEGRO_EVENT_KEY_UP) {
			keyboardState[event.keyboard.keycode] = keyboardState[event.keyboard.keycode] ^ 1;
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) App::getInstance().stop();
			if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) continue;
		}
	} while (false);
}

void GameScene::update(double dt){
	player->update(dt, keyboardState);
	for (auto& asteroid : asteroids) asteroid->update(dt);

	asteroidsSpawn(dt);

	colissionsHandling();
}

void GameScene::render(double lag) const{
	al_clear_to_color(backgroundColor);

	player->render(lag);
	for (auto& asteroid : asteroids) asteroid->render(lag);
}

void GameScene::asteroidsSpawn(double dt) {
	asteroidTimer += dt;
	if (asteroidTimer >= NEW_ASTEROID_TIMER || asteroids.size() < MIN_NO_ASTEROIDS) {
		asteroidTimer -= NEW_ASTEROID_TIMER;
		do {
			Asteroid* newAsteroid = Asteroid::AsteroidFactory(App::getDisplayWidth(), App::getDisplayHeight(), *player, radiusAvailable);
			if (newAsteroid == nullptr) break;
			asteroids.push_back(newAsteroid);
		} while (asteroids.size() < MIN_NO_ASTEROIDS);
	}
}

void GameScene::colissionsHandling() {
	
}