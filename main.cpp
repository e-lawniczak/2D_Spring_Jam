#include "common.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "app.h"
App app;

LTexture gBackgroundTexture;
LTexture gTextTexture;
TTF_Font* gFont;


int main(int argc, char* argv[]) {
	srand(time(NULL));

	memset(&app, 0, sizeof(App));

	initSDL();
	loadImages();
	loadMusic();
	loadFont();
	
	Application application;
	application.init();
	while (1)
	{
		prepareScene(application.getScreen());

		handleInput();

		application.handleScreen();

		presentScene();

		SDL_Delay(16);
	}

	close();
	return 0;
}



