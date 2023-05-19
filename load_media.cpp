#include "common.h"

bool loadImages()
{
    //Loading success flag
    bool success = true;


    //Load background texture
    if (!gBackgroundTexture.loadFromFile("img/background.png"))
    {
        printf("Failed to load background texture image!\n");
        success = false;
    }

    return success;
}

bool loadMusic() {
    return true;
}
bool loadFont() {
    bool success = true;

    gFont = TTF_OpenFont("font/arial.ttf", 28);
    if (gFont == NULL)
    {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }
    else
    {
       
    }

    return success;
}