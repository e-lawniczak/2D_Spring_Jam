#include "common.h"
#include "screen.h"

Screen::Screen()
{
    type = START_SCREEN;
}
Screen::Screen(Screens aType)
{
    type = aType;
    screenTextTexture = &gTextTexture;
}


void Screen::setTex(LTexture* tex) {
    screenTextTexture = tex;
}

Screen::~Screen()
{
    free();
}
void Screen::free()
{
}

void Screen::setText(std::string text)
{
    screenText = text;
    SDL_Color textColor = { 0, 0, 0 };
    if (!screenTextTexture->loadFromRenderedText(text, textColor))
    {
        printf("Failed to render text texture!\n");
    }
}



Screens Screen::getType()
{
    return type;
}

LTexture* Screen::getTexture()
{
    return screenTextTexture;
}

std::string Screen::getText()
{
    return screenText;
}



void Screen::logic()
{
	switch (type) {
	case START_SCREEN:
		handleStartScreen();
		break;
	case END_SCREEN:
		handleEndScreen();
		break;

	default:
		handleGameScreen();
		break;
	}
}

void Screen::draw()
{
	switch (type) {
	case START_SCREEN:
		drawStartScreen();
		break;
	case END_SCREEN:
		drawEndScreen();
		break;

	default:
		drawGameScreen();
		break;
	}
}
void Screen::handleGameScreen()
{
}

void Screen::handleStartScreen()
{
}

void Screen::handleEndScreen()
{
}
void Screen::drawGameScreen()
{
	Entity player(200, SCREEN_HEIGHT / 2, "img/player.png", "Player");
	gBackgroundTexture.render(0, 0);
	LTexture* currentTex = getTexture();
	currentTex->render(10, 10);
	player.getPos()->setY(SCREEN_HEIGHT/2 - player.getTexture()->getWidth() + 20);
	player.getPos()->setX(450);
	player.render();
}

void Screen::drawStartScreen()
{
	LTexture* currentTex = getTexture();
	currentTex->render((SCREEN_WIDTH - currentTex->getWidth()) / 2, (SCREEN_HEIGHT - currentTex->getHeight()) / 2);
}

void Screen::drawEndScreen()
{
	LTexture* currentTex = getTexture();
	currentTex->render((SCREEN_WIDTH - currentTex->getWidth()) / 2, (SCREEN_HEIGHT - currentTex->getHeight()) / 2);
}