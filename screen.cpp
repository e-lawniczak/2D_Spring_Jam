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

