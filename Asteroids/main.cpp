#include "stdio.h"
#include "App.h"

#include "Vector2D.h"

int main(void) {
	App* app = App::getInstance();

	app->run();

	delete app;

	return 0;
}