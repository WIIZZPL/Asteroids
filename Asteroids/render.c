#include "render.h"

//

void render(ALLEGRO_DISPLAY* display, const double lag) {
	al_clear_to_color(al_map_rgb(255, 255, 255));

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

	if (displayX > 0) {
		al_draw_filled_rectangle(0, 0, displayX, displayHeight, al_map_rgb(0, 0, 0));
		al_draw_filled_rectangle(displayWidth + displayX, 0, displayWidth + displayX*2, displayHeight, al_map_rgb(0, 0, 0));
	}
	else if (displayY > 0) {
		al_draw_filled_rectangle(0, 0, displayWidth, displayY, al_map_rgb(0, 0, 0));
		al_draw_filled_rectangle(0, displayHeight + displayY, displayWidth, displayHeight + displayY*2, al_map_rgb(0, 0, 0));
	}

	al_flip_display();
}