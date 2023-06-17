#pragma once

#define FPSn 120
#define SPT (1/120.0)
#define ASPECT_RATIO ((double)16.0/9.0)

struct ALLEGRO_DISPLAY;
struct ALLEGRO_EVENT_QUEUE;
class Scene;

/// Enumerator ID dostêpnych scen.
enum class sceneIDs {
	INVALID,
	GAME,
	MENU
};

/// Singleton aplikacji.
/// Zarz¹dza oknem, pêtl¹, oraz zmian¹ scen.
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

	App(App const& app) = delete;
	App const& operator=(App const& app) = delete;
	App(App&& app) = delete;
	App const& operator=(App&& app) = delete;

public:
	/// Zwraca referencjê do instancji.
	static App& getInstance();

	/// Zwraca szerokoœæ okna w pikselach.
	static unsigned int getDisplayWidth();
	/// Zwraca wysokoœæ okna w pikselach.
	static unsigned int getDisplayHeight();

	/// Ustala nastêpn¹ scene.
	/// Do zmiany nie zachodzi po zakoñczeniu siê aktualnej pêtli.
	/// @param nextScene id sceny nastêpnej.
	/// @see sceneIDs.
	void setNextScene(sceneIDs nextScene);

	/// Uaktywnia pêtlê singletonu.
	/// Efektem jest otworzenie aplikacji.
	void run();
	/// Zaktrzymuje pêtlê singletonu.
	/// Efektem jest zamkniêcie aplikacji.
	void stop();
};