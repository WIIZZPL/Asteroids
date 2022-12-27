#include "GameScene.h"
#include "App.h"

GameScene::GameScene(){

}

GameScene::~GameScene(){

}

void GameScene::processInput(ALLEGRO_EVENT& event){

}

void GameScene::update(double t, double dt){

}

void GameScene::render(ALLEGRO_DISPLAY* display, double lag){
	unsigned int displayX = App::getDisplayX(),
		         displayY = App::getDisplayY(),
		         displayWidth = App::getDisplayWidth(),
		         displayHeight = App::getDisplayHeight();

	al_draw_filled_rectangle(displayX, displayY, displayX + displayWidth, displayY + displayHeight, al_map_rgb(0, 0, 0));
}
