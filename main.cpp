#include "common.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "app.h"
#include "sound.h"
#include "main.h"


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

	SDL_Surface* iconPtr = IMG_Load("img/game_icon.ico");
	SDL_SetWindowIcon(app.window, iconPtr);
	SDL_FreeSurface(iconPtr);

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
		prepareScene(application.getScreen());
		imguiFrame();
		handleInput();

		application.handleScreen();

		presentScene();
		imguiRender();
		SDL_Delay(16);
	}

	close();
	return 0;
}



