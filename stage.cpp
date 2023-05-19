#include "common.h"


Stage::Stage()
{
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

Screen Stage::getScreen()
{
	return currentScreen;
}

void Stage::changeScreen(Screen screen) {
	currentScreen = screen;
}