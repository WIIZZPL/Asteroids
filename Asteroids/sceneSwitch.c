#include "sceneSwitch.h"

//

void sceneSwitch(int newSceneID) {
	scene_del();
	sceneID = newSceneID;
	scene_init();
}

void scene_init() {
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
}

void scene_del() {
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
}