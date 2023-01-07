#include "App.h"

App* App::instance;
unsigned int App::displayWidth = 1280;
unsigned int App::displayHeight = 720;

App::App(){
	try {
		if (!al_init()) throw "Allegro init";
		if (!al_init_primitives_addon()) throw "Allegro primitives addon";
		if (!al_install_audio()) "audio";
		if (!al_install_keyboard()) "keyboard";
		if (!al_install_mouse()) "mouse";

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

	FPSi = 0;

	totalTime = 0;
	lastFrameTime = al_current_time();
	deltaFrameTime = 0;
	accumulatedTime = 0;

	running = false;
	currentScene = sceneIDs::GAME;
	nextScene = sceneIDs::GAME;

	scene = new GameScene(displayWidth, displayHeight);
}

App& App::getInstance(){
	if (!instance) instance = new App();
	return *instance;
}

App::~App(){
	al_destroy_event_queue(eventQueue);
	al_uninstall_audio();
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_destroy_display(display);
	delete scene;
}

void App::run() {
	running = true;

	while (running){
		deltaFrameTime = al_current_time() - lastFrameTime;
		lastFrameTime += deltaFrameTime;
		accumulatedTime += deltaFrameTime;

		sceneSwitch();

		processInput();

		while (accumulatedTime >= SPT) {
			update(SPT);
			accumulatedTime -= SPT;
			totalTime += SPT;
		}

		render(accumulatedTime);
	}
}

void App::setNextScene(sceneIDs nextScene){
	this->nextScene = nextScene;
}

void App::stop() {
	running = false;
}

unsigned int App::getDisplayWidth() {
	return App::displayWidth;
}

unsigned int App::getDisplayHeight() {
	return App::displayHeight;
}

void App::sceneSwitch() {
	if (currentScene != nextScene) {

		switch(nextScene){
		case sceneIDs::GAME:
			scene = new GameScene(displayWidth, displayHeight);
		default:
			exit(555);
		}

		currentScene = nextScene;
	}
}

void App::processInput() {
	ALLEGRO_EVENT event;
	while (al_get_next_event(eventQueue, &event)) {

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			stop();
		}

		scene->processInput(event);
	}
}

void App::update(double dt) {
	scene->update(dt);
}

void App::render(double lag) {
	al_clear_to_color(al_map_rgb(255, 0, 255));

	scene->render(lag);

	al_flip_display();

	FPS[FPSi] = 1 / deltaFrameTime;
	FPSi = (FPSi + 1) % FPSn;
	double MFPS = 0;
	for (int i = 0; i < FPSn; i++) MFPS += FPS[i];
	MFPS /= FPSn;
	char title[22];
	snprintf(title, 22, "Asteroids FPS:%4.2lf", MFPS);
	al_set_window_title(display, title);
}