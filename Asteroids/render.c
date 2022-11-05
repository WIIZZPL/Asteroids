#include "render.h"

//

void render(ALLEGRO_DISPLAY* display, const double lag) {
	al_clear_to_color(al_map_rgb(0, 0, 0));

	switch (sceneID)
	{
	case 0: //menu
		break;
	case 1: //gra
		break;
	case 2: //help
		break;
	case 3: //highscores
		break;
	case 4: //options
		break;
	default:
		break;
	}

	al_flip_display();
}