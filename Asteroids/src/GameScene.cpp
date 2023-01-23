#include "GameScene.h"

#include "App.h"

#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"

#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

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

	font = al_load_font("font.ttf", 50, NULL);
	if (!font) exit(2);
}

GameScene::~GameScene(){
	delete player;
	for (auto& asteroid : asteroids) delete asteroid;
	for (auto& bullet : bullets) delete bullet;
	al_destroy_font(font);
}

void GameScene::processInput(ALLEGRO_EVENT& event){
	do {
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			keyboardState[event.keyboard.keycode] = 3;
		}
		else if (event.type == ALLEGRO_EVENT_KEY_UP) {
			keyboardState[event.keyboard.keycode] = keyboardState[event.keyboard.keycode] ^ 1;
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) App::getInstance().setNextScene(sceneIDs::MENU);
		}
	} while (false);
}

void GameScene::update(double dt){
	player->update(dt, keyboardState, bullets);
	for (auto& asteroid : asteroids) asteroid->update(dt);
	for (auto& bullet : bullets) bullet->update(dt);

	asteroidsSpawn(dt);

	colissionsHandling();
}

void GameScene::render(double lag) const{
	al_clear_to_color(backgroundColour);

	player->render(lag);
	for (auto& asteroid : asteroids) asteroid->render(lag);
	for (auto& bullet : bullets) bullet->render(lag);
	barrier.render(lag);
	
	al_draw_textf(font, textColour, 25, 15, NULL, "Points: %d", score);
	al_draw_textf(font, textColour, 25, 75, NULL, " Lives: %d", lives);
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

	for (int i = 0; i < asteroids.size(); i++) {
		
		if (barrier.isActive() && Object::colissionObjectObject(*asteroids[i], barrier)) {
			float radius = asteroids[i]->getRadius();
			delete asteroids[i];
			asteroids.erase(asteroids.begin() + i);
			asteroids.push_back(new Asteroid(App::getDisplayWidth(), App::getDisplayHeight(), *player, radius));
			continue;
		}

		if (Object::colissionObjectObject(*asteroids[i], *player)) {
			if (--lives == 0) App::getInstance().setNextScene(sceneIDs::MENU);
			barrier.toggle();
			player->reset();
			while (bullets.size() > 0 && Object::colissionObjectObject(barrier, *bullets.back())){
				delete bullets.back();
				bullets.pop_back();
			}
		}

		for (int j = 0; j < bullets.size(); j++) {
			if (i < asteroids.size() && Object::colissionObjectObject(*asteroids[i], *bullets[j])) {
				asteroids[i]->AsteroidBreak(App::getDisplayWidth(), App::getDisplayHeight(), asteroids, radiusAvailable, score);
				delete asteroids[i];
				delete bullets[j];
				asteroids.erase(asteroids.begin() + i);
				bullets.erase(bullets.begin() + j);
				i--;
				j--;
			}
		}
	}

	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->shouldBeRemoved(App::getDisplayWidth(), App::getDisplayHeight())) {
			bullets.erase(bullets.begin() + i);
			i--;
		}
	}

	
	if (barrier.isActive()) {
		if (!Object::colissionObjectObject(barrier, *player))
			barrier.toggle();
		else if (bullets.size() > 0 && Object::colissionObjectObject(barrier, *bullets.back()))
			barrier.toggle();
	}
}