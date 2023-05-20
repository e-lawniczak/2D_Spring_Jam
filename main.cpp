#include "common.h"
#include "init.h"

App app;

SDL_Texture gBackgroundTexture;
SDL_Texture gTextTexture;

TTF_Font* gFont;




int main(int argc, char* argv[]) {
	initSDL(&app);
	// loadImages();
	loadMusic();
	loadFont();

	while (app.running) {
		app.logic();
		(app.*(app.renderScreenPtr))();
    }

	close();
	return 0;
}



