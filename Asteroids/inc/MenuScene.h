#pragma once

#include "Scene.h"

#include <vector>
#include "allegro5/allegro5.h"
#include "Button.h"
//#include "Star.h"

struct ALLEGRO_FONT;

/// <summary>
/// Scena menu. Posiada tytó³ gry oraz dwa przyciski, jeden do rozpoczêcia gry, drugi do wyjœcia.
/// @see Scene
/// </summary>
class MenuScene : public Scene {
private:
	ALLEGRO_FONT* titleFont;
	ALLEGRO_FONT* buttonFont;
	const ALLEGRO_COLOR textColour = al_map_rgb(255, 255, 255);

	Button* startButton;
	Button* quitButton;

	//std::vector<Star> stars;

	std::vector<Vector2D> mouseHits;

public:
	MenuScene();
	~MenuScene();
	void processInput(ALLEGRO_EVENT& event);
	void update(double dt);
	void render(double lag) const;
};

