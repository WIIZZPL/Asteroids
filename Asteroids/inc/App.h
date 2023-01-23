#pragma once

#define FPSn 120
#define SPT (1/120.0)
#define ASPECT_RATIO ((double)16.0/9.0)

struct ALLEGRO_DISPLAY;
struct ALLEGRO_EVENT_QUEUE;
class Scene;

enum class sceneIDs {
	INVALID,
	GAME,
	MENU,
	GAME_END,
	HIGHSCORE
};

class App {
private:
	static App instance;
	App();
	~App();

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
	void render(double lag) const;
	void fpsIndicator();

public:
	static App& getInstance();
	App(App const& app) = delete;
	App const& operator=(App const& app) = delete;
	App(App&& app) = delete;
	App const& operator=(App&& app) = delete;

	static unsigned int getDisplayWidth();
	static unsigned int getDisplayHeight();

	void setNextScene(sceneIDs nextScene);

	void run();
	void stop();
};