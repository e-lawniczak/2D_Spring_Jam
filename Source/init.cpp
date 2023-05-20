#include "HEADER.h"

void initSDL(Game * app) {
	if (SDL_Init(SDL_INIT_EVERYTHING) || !IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) || Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) || (TTF_Init() < 0)) {
		fprintf(stderr, "SDL init error: %s\n", SDL_GetError());
        exit(1);
	}

	int rendererFlags, windowFlags;
	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;

	(*app).window = SDL_CreateWindow("Chicken RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
	(*app).renderer = SDL_CreateRenderer((*app).window, -1, rendererFlags);


	if (!(*app).window) {
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	if (!(*app).renderer) 	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
}



void close() {
	////Free loaded images
	//gFooTexture.free();
	//gBackgroundTexture.free();
	//gStartScreenText.free();
	//Free global font
// 	TTF_CloseFont(gFont);
// 
// 	//Destroy window
// 	SDL_DestroyRenderer(app.renderer);
// 	SDL_DestroyWindow(app.window);
// 
// 	//Quit SDL subsystems
// 	TTF_Quit();
// 	IMG_Quit();
// 	Mix_Quit();
// 	SDL_Quit();
}