#include "common.h"

bool loadImages()
{
    //Loading success flag
    bool success = true;


    //Load background texture
    if (!gBackgroundTexture.loadFromFile("img/overland_map.png"))
    {
        printf("Failed to load background texture image!\n");
        success = false;
    }
    if (!gEndScreenTexture.loadFromFile("img/end_screen.png"))
    {
        printf("Failed to load background texture image!\n");
        success = false;
    }
    if (!enemy1tex.loadFromFile("img/sly_fox.png"))
    {
        printf("Failed to load background texture image!\n");
        success = false;
    }
    if (!enemy2tex.loadFromFile("img/blue_snowman.png"))
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

    gFont = TTF_OpenFont("font/dogica.ttf", 28);
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