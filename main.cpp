#include "common.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "app.h"
#include "sound.h"
App app;

LTexture gBackgroundTexture;
LTexture gEndScreenTexture;
LTexture enemy1tex;
LTexture enemy2tex;
LTexture gTextTexture;
TTF_Font* gFont;


int main(int argc, char* argv[]) {
	srand(time(NULL));

	memset(&app, 0, sizeof(App));

	initSDL();
	loadImages();
	loadMusic();
	loadFont();
	initSounds();
	playChannel(SND_AMBIENT, CH_AMBIENT, 1);
	playChannel(SND_MAIN_THEME, CH_MUSIC, 1);
	Application application;
	application.init();
	while (1)
	{
		imguiFrame();
		handleInput();

		application.handleScreen();

		presentScene(application.getScreen());
		imguiRender();
		SDL_Delay(16);
	}

	close();
	return 0;
}



