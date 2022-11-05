#include "stdio.h"
#include "globals.h"
#include "processInput.h"
#include "update.h"
#include "render.h"
#include "sceneSwitch.h"

#include "allegro5/allegro5.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_audio.h"

#define FPSn 100

void init(void) {
	if (!al_init()) exit(1);
	if (!al_init_image_addon()) exit(1);
	if (!al_init_font_addon()) exit(1);
	if (!al_init_ttf_addon()) exit(1);
	if (!al_init_primitives_addon()) exit(1);
	if (!al_install_audio()) exit(1);
	if (!al_install_keyboard()) exit(1);
	if (!al_install_mouse()) exit(1);
}

void del(void) {
	al_uninstall_audio();
	al_uninstall_keyboard();
	al_uninstall_mouse();
}

int main(void) {
	
	init();

	displayWidth = 1280;
	displayHeight = 720;
	displayX = 0;
	displayY = 0;
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	ALLEGRO_DISPLAY* display = al_create_display(displayWidth, displayHeight);
	if (!display) exit(1);



	running = 1;
	sceneID = 0;
	double time = 0;
	const double SPT = 1 / 120.0;
	double FPS[10];
	int FPSi = 0;
	double lastFrameTime = al_current_time(), deltaFrameTime = 0, accumulatedTime = 0;

	processInput_init(display);
	while (running) {
		deltaFrameTime = al_current_time() - lastFrameTime;
		lastFrameTime += deltaFrameTime;
		accumulatedTime += deltaFrameTime;

		processInput();

		while (accumulatedTime >= SPT) {
			update(time, SPT);
			accumulatedTime -= SPT;
			time += SPT;
		}

		render(display, accumulatedTime);

		FPS[FPSi] = 1 / deltaFrameTime;
		FPSi = (FPSi + 1) % FPSn;
		double MFPS = 0;
		for (int i = 0; i < FPSn; i++) MFPS += FPS[1];
		MFPS /= FPSn;
		char title[32];
		snprintf(title, 32, "Asteroids FPS:%4.2lf", MFPS);
		al_set_window_title(display, title);
	}

	processInput_del(display);
	del();
	al_destroy_display(display);
	return 0;
}