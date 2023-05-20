#include "common.h"


Stage::Stage()
{
	currentScreen = startScreen;
}
Stage::Stage(Screen initScreen)
{
	currentScreen = initScreen;
}

Stage::~Stage()
{
	free();
}
void Stage::free()
{
}

void Stage::logic()
{
	currentScreen.logic();
	// go to the game screen on LMB click
	if (app.mouse[LMB] && getScreen().getType() == START_SCREEN) {
		gameScreen.setText("Press q to end");
		changeScreen(gameScreen);
	}


	// end the game temporary by clicking q
	if (app.keyboard[SDL_SCANCODE_Q] && getScreen().getType() == GAME_SCREEN) {
		endScreen.setText("Thanks for playing");
		changeScreen(endScreen);
	}
}

void Stage::draw()
{
	currentScreen.draw();
}

void Stage::initStage()
{
	startScreen.setText("Press LMB to start");
}

Screen Stage::getScreen()
{
	return currentScreen;
}

void Stage::changeScreen(Screen screen) {
	currentScreen = screen;
}