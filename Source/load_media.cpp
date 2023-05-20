#include "common.h"

bool loadImages(std::string path, SDL_Texture ** texture, App * app) {
    //Loading success flag
    bool success = true;

    static SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	*texture = SDL_CreateTextureFromSurface((*app).renderer, loadedSurface);

	if (*texture == NULL) {
		success = false;
	}

	SDL_FreeSurface(loadedSurface);

    return success;
}

bool loadMusic() {
    return true;
}

bool loadFont() {
    bool success = true;

    gFont = TTF_OpenFont("font/arial.ttf", 28);
    if (gFont == NULL) {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }

    return success;
}