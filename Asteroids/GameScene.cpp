#include "GameScene.h"

char GameScene::keyboardState[ALLEGRO_KEY_MAX];

GameScene::GameScene(unsigned int displayWidth, unsigned int displayHeight){
	player = new Player(displayWidth, displayHeight);
	backgroundColor = al_map_rgb(20, 33, 61);
}

GameScene::~GameScene(){
	delete player;
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
}

void GameScene::render(double lag){
	al_clear_to_color(backgroundColor);

	player->render(lag);
}
