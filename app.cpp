#include "common.h"
#include "app.h"

Application::Application()
{
	currentScreen = START_SCREEN;
	screenText = "Press LMB to start";
	textTexture = LTexture();
}

Application::~Application()
{
}

void Application::free()
{
}

void Application::handleScreen()
{
	switch (currentScreen)
	{
	case START_SCREEN:
		handleStart();
		break;
	case GAME_SCREEN:
		handleGame();
		break;
	case END_SCREEN:
		handleEnd();
		break;
	default:
		break;
	}
}

Screens Application::getScreen()
{
	return currentScreen;
}

void Application::init()
{
	setText(screenText);
}
void Application::handleStart()
{
	textTexture.render((SCREEN_WIDTH - textTexture.getWidth()) / 2, (SCREEN_HEIGHT - textTexture.getHeight()) / 2);
	if (app.mouse[LMB] && currentScreen == START_SCREEN) {
		setText("Press q to end");
		currentScreen = GAME_SCREEN;
	}



}

void Application::handleGame()
{
	if (app.keyboard[SDL_SCANCODE_Q] && currentScreen == GAME_SCREEN) {
		setText("Thanks for playing");
		currentScreen = END_SCREEN;
	}


	gBackgroundTexture.render(0, 0);
	textTexture.render(10, 10);
}

void Application::handleEnd()
{
	textTexture.render((SCREEN_WIDTH - textTexture.getWidth()) / 2, (SCREEN_HEIGHT - textTexture.getHeight()) / 2);
}

void Application::setText(std::string text)
{
	screenText = text;
	SDL_Color textColor = { 0, 0, 0 };
	if (!textTexture.loadFromRenderedText(screenText, textColor))
	{
		printf("Failed to render text texture!\n");
	}
}
