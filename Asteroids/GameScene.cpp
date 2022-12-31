#include "GameScene.h"

char GameScene::keyboardState[ALLEGRO_KEY_MAX];

#define MAX_MASS 1000
#define NEW_ASTEROID_TIMER 3
#define MIN_NO_ASTEROIDS 1

GameScene::GameScene(unsigned int displayWidth, unsigned int displayHeight){
	backgroundColor = al_map_rgb(0, 0, 0);
	player = new Player(displayWidth, displayHeight);
	massAvailable = MAX_MASS;
	asteroid_timer = 3;
}

GameScene::~GameScene(){
	delete player;
	for (auto i : asteroids) delete i;
}

void GameScene::processInput(ALLEGRO_EVENT& event){
	if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
		keyboardState[event.keyboard.keycode] = 3;
	}
	else if (event.type == ALLEGRO_EVENT_KEY_UP) {
		keyboardState[event.keyboard.keycode] = keyboardState[event.keyboard.keycode] ^ 1;
		if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) App::getInstance()->stop();
	}
}

void GameScene::update(double dt){
	player->update(dt, keyboardState, App::getDisplayWidth(), App::getDisplayHeight());
	for (auto& i : asteroids) i->update(dt, App::getDisplayWidth(), App::getDisplayHeight());

	asteroid_timer += dt;
	if (asteroid_timer >= NEW_ASTEROID_TIMER) {
		do {
			Asteroid* newAsteroid = Asteroid::AsteroidFactory(App::getDisplayWidth(), App::getDisplayHeight(), *player, massAvailable);
			if (!newAsteroid) break;
			asteroids.push_back(newAsteroid);
		} while (asteroids.size() < MIN_NO_ASTEROIDS);
	}
}

void GameScene::render(double lag){
	al_clear_to_color(backgroundColor);

	player->render(lag);
	for (auto& i : asteroids) i->render(lag);
}
