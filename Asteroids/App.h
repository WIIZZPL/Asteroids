#pragma once

#include <stdio.h>
#include <algorithm>
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_audio.h"

#include "GameScene.h"

#define FPSn 120
#define SPT (1/120.0)
#define aspectRatio ((double)16.0/9.0)

enum sceneIDs {
	GAME_SCENE_ID = 0,
	MENU_SCENE_ID,
	GAME_END_SCENE_ID,
	HIGHSCORE_SCENE_ID
};

class App {
private:
	static App* instance;
	App();

	static unsigned int displayWidth, displayHeight, displayX, displayY;
	ALLEGRO_DISPLAY* display;

	double FPS[FPSn]{};
	int FPSi;

	double totalTime, lastFrameTime, deltaFrameTime, accumulatedTime;

	bool running;

	unsigned int currentScene, nextScene;
	Scene* scene;

	ALLEGRO_EVENT_QUEUE* eventQueue;

	void sceneSwitch();
	void processInput();
	void update(double t, double dt);
	void render(ALLEGRO_DISPLAY* dispay, double lag);

public:
	static App* getInstance();
	App(App const& app) = delete;
	App const& operator=(App const& app) = delete;
	App(App&& app) = delete;
	App const& operator=(App&& app) = delete;
	~App();
	
	static unsigned int getDisplayX();
	static unsigned int getDisplayY();
	static unsigned int getDisplayWidth();
	static unsigned int getDisplayHeight();

	void setNextScene(unsigned int nextScene);

	void run();
	void stop();
};