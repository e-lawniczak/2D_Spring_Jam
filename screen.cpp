#include "common.h"
#include "screen.h"

Screen::Screen()
{
    type = START_SCREEN;
}
Screen::Screen(Screens aType)
{
    type = aType;
    screenTextTexture = NULL;
}

Screen::Screen(Screens aType, std::string text)
{
    type = aType;
    screenText = text;
    LTexture tex;
    screenTextTexture = &tex;
    SDL_Color textColor = { 0, 0, 0 };
    if (!screenTextTexture->loadFromRenderedText(text, textColor))
    {
        printf("Failed to render text texture!\n");
    }
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

void Screen::renderText(int x, int y) {
    
    screenTextTexture->render(x, y);
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

