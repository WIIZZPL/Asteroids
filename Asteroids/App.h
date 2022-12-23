#pragma once

#include <stdio.h>
#include <vector>
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_audio.h"

#include "GameScene.h"

#define FPSn 100
#define SPT (1/120.0)

enum sceneIDs {
	game = 0
};

class App {
private:
	static App* instance;
	App();

	unsigned int displayWidth, displayHeight, displayX, displayY;
	ALLEGRO_DISPLAY* display;
	double FPS[FPSn]{};
	int FPSi;
	double totalTime, lastFrameTime, deltaFrameTime, accumulatedTime;

	bool running;

	unsigned int currentScene, nextScene;
	std::vector<Scene> scenes;

	ALLEGRO_EVENT_QUEUE* eventQueue;

	void processInput();
	void update(double t, double dt);
	void render(ALLEGRO_DISPLAY* dispay, double lag);

public:
	static App* getInstance();
	~App();

	void run();
	void stop();
};