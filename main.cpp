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


//void initStage() {
//	LTexture gStartTextTexture;
//	LTexture gEndTextTexture;
//	startScreen.setTex(&gStartTextTexture);
//	startScreen.setText("Press LMB to start");
//	endScreen.setTex(&gEndTextTexture);
//	endScreen.setText("Thanks for playing");
//}

int main(int argc, char* argv[]) {

	memset(&app, 0, sizeof(App));

	initSDL();
	loadImages();
	loadMusic();
	loadFont();
	//initStage();
	
	// why the fuick this doesn't work when put in diffrent function, bruh c++ hard
	LTexture gStartTextTexture;
	LTexture gEndTextTexture;
	startScreen.setText("Press LMB to start");
	Stage mainStage(startScreen);


	while (1)
	{
		prepareScene(mainStage);

		handleInput();

		// display start and end text
		if (mainStage.getScreen().getType() == START_SCREEN || mainStage.getScreen().getType() == END_SCREEN) {
			LTexture* currentTex = mainStage.getScreen().getTexture();
			currentTex->render((SCREEN_WIDTH - currentTex->getWidth()) / 2, (SCREEN_HEIGHT - currentTex->getHeight()) / 2);
		}

		// go to the game screen on LMB click
		if (app.mouse[LMB] && mainStage.getScreen().getType() == START_SCREEN) {
			
			mainStage.changeScreen(gameScreen);
		}


		// end the game temporary by clicking q
		if (app.keyboard[SDL_SCANCODE_Q] && mainStage.getScreen().getType() == GAME_SCREEN) {
			endScreen.setText("Thanks for playing");
			mainStage.changeScreen(endScreen);
		}

		presentScene();

		SDL_Delay(16);
	}

	close();
	return 0;
}



