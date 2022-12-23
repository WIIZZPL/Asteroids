#include "App.h"

App* App::instance;

App::App(){
	try {
		if (!al_init()) throw "Allegro init";
		if (!al_init_primitives_addon()) throw "Allegro primitives addon";
		if (!al_install_audio()) "audio";
		if (!al_install_keyboard()) "keyboard";
		if (!al_install_mouse()) "mouse";

		al_set_new_display_flags(ALLEGRO_RESIZABLE);
		display = al_create_display(displayWidth, displayHeight);
		if (!display) throw "display";

		eventQueue = al_create_event_queue();
		if (!eventQueue) throw "event queue";
		al_register_event_source(eventQueue, al_get_display_event_source(display));
		al_register_event_source(eventQueue, al_get_keyboard_event_source());
		al_register_event_source(eventQueue, al_get_mouse_event_source());

		srand(time(NULL));

	}
	catch (const char* s) {
		printf("Exception: %s not initialised", s);
		exit(1);
	}

	displayWidth = 1280;
	displayHeight = 720;
	displayX = 0;
	displayY = 0;
	
	FPSi = 0;

	totalTime = 0;
	lastFrameTime = al_current_time();
	deltaFrameTime = 0;
	accumulatedTime = 0;

	currentScene = -1;
	nextScene = 0;

	scenes = std::vector<Scene>();
}

App* App::getInstance(){
	if (!instance) instance = new App();
	return instance;
}

App::~App(){
	al_destroy_event_queue(eventQueue);
	al_uninstall_audio();
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_destroy_display(display);
}

void App::run() {
	running = true;

	while (running){
		deltaFrameTime = al_current_time() - lastFrameTime;
		lastFrameTime += deltaFrameTime;
		accumulatedTime += deltaFrameTime;

		processInput();

		while (accumulatedTime >= SPT) {
			update(totalTime, SPT);
			accumulatedTime -= SPT;
			totalTime += SPT;
		}

		render(display, accumulatedTime);

		FPS[FPSi] = 1 / deltaFrameTime;
		FPSi = (FPSi + 1) % FPSn;
		double MFPS = 0;
		for (int i = 0; i < FPSn; i++) MFPS += FPS[1];
		MFPS /= FPSn;
		char title[50];
		snprintf(title, 32, "Asteroids FPS:%4.2lf", MFPS);
		al_set_window_title(display, title);
	}
}

void App::stop() {
	running = false;
}

void App::processInput() {

}

void App::update(double t, double dt) {

}

void App::render(ALLEGRO_DISPLAY* display, double lag) {

}