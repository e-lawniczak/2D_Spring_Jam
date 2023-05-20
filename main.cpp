#include "common.h"
#include "init.h"
#include "draw.h"
#include "input.h"
App app;

LTexture gBackgroundTexture;
LTexture gTextTexture;

TTF_Font* gFont;
Screen startScreen(START_SCREEN);
Screen gameScreen(GAME_SCREEN);
Screen endScreen(END_SCREEN);




int main(int argc, char* argv[]) {
	srand(time(NULL));

	memset(&app, 0, sizeof(App));

	initSDL();
	loadImages();
	loadMusic();
	loadFont();
	
	Stage mainStage;
	mainStage.initStage();


	while (1)
	{
		prepareScene(mainStage);

		handleInput();

		mainStage.logic();
		mainStage.draw();

		

		presentScene();

		SDL_Delay(16);
	}

	close();
	return 0;
}



