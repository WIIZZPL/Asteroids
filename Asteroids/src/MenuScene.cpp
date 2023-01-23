#include "MenuScene.h"

#include <allegro5/allegro_ttf.h>

#include "App.h"

#define FONT_FILE_NAME "font.ttf"

MenuScene::MenuScene(){
	titleFont = al_load_font(FONT_FILE_NAME, 100, NULL);
	buttonFont = al_load_font(FONT_FILE_NAME, 50, NULL);
	if (!titleFont || !buttonFont) exit(2);

	unsigned int displayWidth = App::getDisplayWidth(), displayHeight = App::getDisplayHeight();

	startButton = new Button(Vector2D(displayWidth / 2, 2.25f * displayHeight / 4), Vector2D(300, 100), buttonFont, "START");
	quitButton = new Button(Vector2D(displayWidth / 2, 3 * displayHeight / 4), Vector2D(300, 100), buttonFont, "QUIT");
}

MenuScene::~MenuScene(){
	al_destroy_font(titleFont);
	al_destroy_font(buttonFont);
	delete startButton;
	delete quitButton;
}

void MenuScene::processInput(ALLEGRO_EVENT& event){
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		Vector2D mouse(event.mouse.x, event.mouse.y);
		if (Object::colissionObjectPoint(*startButton, mouse)) {
			App::getInstance().setNextScene(sceneIDs::GAME);
		}
		if (Object::colissionObjectPoint(*quitButton, mouse)) {
			App::getInstance().stop();
		}
	}
}

void MenuScene::update(double dt){

}
#include <allegro5/allegro_primitives.h>
void MenuScene::render(double lag) const{
	al_draw_textf(titleFont, textColour, App::getDisplayWidth()/2, App::getDisplayHeight()/4, ALLEGRO_ALIGN_CENTRE, "ASTEROIDS!");
	startButton->render();
	quitButton->render();
	for (auto& i : mouseHits) al_draw_filled_circle(i.x, i.y, 5, al_map_rgb(255, 0, 0));
}
