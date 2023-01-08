
#include "App.h"

int main(void) {
	App& app = App::getInstance();

	app.run();

	return 0;
}