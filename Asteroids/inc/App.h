#pragma once

#include <stdio.h>
#include <algorithm>
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_audio.h"

#include "GameScene.h"

#define FPSn 120
#define SPT (1/120.0)
#define ASPECT_RATIO ((double)16.0/9.0)

enum class sceneIDs {
	GAME = 0,
	MENU,
	GAME_END,
	HIGHSCORE
};

class App {
private:
	static App* instance;
	App();

	static unsigned int displayWidth, displayHeight;
	ALLEGRO_DISPLAY* display;

	double FPS[FPSn]{};
	int FPSi;

	double totalTime, lastFrameTime, deltaFrameTime, accumulatedTime;

	bool running;

	sceneIDs currentScene, nextScene;
	Scene* scene;

	ALLEGRO_EVENT_QUEUE* eventQueue;

	void sceneSwitch();
	void processInput();
	void update(double dt);
	void render(double lag);

public:
	static App& getInstance();
	App(App const& app) = delete;
	App const& operator=(App const& app) = delete;
	App(App&& app) = delete;
	App const& operator=(App&& app) = delete;
	~App();

	static unsigned int getDisplayWidth();
	static unsigned int getDisplayHeight();

	void setNextScene(sceneIDs nextScene);

	void run();
	void stop();
};