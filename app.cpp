#include "common.h"
#include "app.h"
#include "sound.h"

Application::Application()
{
	currentScreen = START_SCREEN;
	screenText = "Press SPACE to start";
	textTexture = LTexture();
	engine = GameEngine();


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
	this->setText(screenText);
}
void Application::handleStart()
{
	textTexture.render((SCREEN_WIDTH - textTexture.getWidth()) / 2, (SCREEN_HEIGHT - textTexture.getHeight()) / 2);
	if (app.keyboard[SDL_SCANCODE_SPACE] && currentScreen == START_SCREEN) {
		playSound(SND_MENU_CLICK, CH_MENU_SOUND);
		this->setText("Press q to end");
		engine.init();
		currentScreen = GAME_SCREEN;
	}


}

void Application::handleGame()
{
	if (engine.getGameFinished() && currentScreen == GAME_SCREEN) {
		setText("Thanks for playing");
		currentScreen = END_SCREEN;
	}

	gBackgroundTexture.render(0, 0);
	//textTexture.render(10, 10);
	engine.gameLoop();
}

void Application::handleEnd()
{
	gEndScreenTexture.render((SCREEN_WIDTH / 2) - gEndScreenTexture.getWidth()/2, 0);
	textTexture.setColor((Uint8)(255), (Uint8)(255), (Uint8)(255));
	textTexture.render((SCREEN_WIDTH - textTexture.getWidth()) / 2, (SCREEN_HEIGHT - textTexture.getHeight()) / 2);
}

void Application::setText(std::string text)
{
	this->screenText = text;
	SDL_Color textColor = { 0, 0, 0 };
	if (!this->textTexture.loadFromRenderedText(screenText, textColor))
	{
		printf("Failed to render text texture!\n");
	}
}
