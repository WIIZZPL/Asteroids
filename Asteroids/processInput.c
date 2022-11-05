#include "processInput.h"



ALLEGRO_EVENT_QUEUE* eventQueue;

void processInput_init(ALLEGRO_DISPLAY* display) {
	eventQueue = al_create_event_queue();

	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_mouse_event_source());
}

void processInput() {
	ALLEGRO_EVENT event;
	while (al_get_next_event(eventQueue, &event)) {
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			running = 0;
			continue;
		}
		else if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE) {
			al_acknowledge_resize(event.display.source);
			displayWidth = al_get_display_width(event.display.source);
			displayHeight = al_get_display_height(event.display.source);
			displayX = max(0, (displayWidth - displayHeight * aspectRatio) / 2);
			displayY = max(0, (displayHeight - displayWidth / aspectRatio) / 2);
			displayWidth -= 2 * displayX;
			displayHeight -= 2 * displayY;
		}

		switch (sceneID){
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
	}
}

void processInput_del(ALLEGRO_DISPLAY* display) {
	al_unregister_event_source(eventQueue, al_get_display_event_source(display));
	al_unregister_event_source(eventQueue, al_get_keyboard_event_source());
	al_unregister_event_source(eventQueue, al_get_mouse_event_source());

	al_destroy_event_queue(eventQueue);
}