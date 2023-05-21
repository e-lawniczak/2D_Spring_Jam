#include "common.h"
#include "init.h"

int initSDL() {
	int rendererFlags;
	rendererFlags = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;
	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Initialize error: %s", SDL_GetError());
		exit(1);
	}


	app.window = SDL_CreateWindow("Chicken RPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);

	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);


	imguiInit();


	if (!app.renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0) {
		printf("IMG initialize error: %s", SDL_GetError());
		exit(1);
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		printf("Couldn't initialize SDL Mixer\n");
		exit(1);
	}
	if (TTF_Init() < 0) {
		printf("Couldn't initialize SDL TTF\n");
		exit(1);
	}

	int vol1 = 70;
	int vol2 = 66;
	Mix_AllocateChannels(8);
	Mix_Volume(CH_ANY, vol1);
	Mix_Volume(CH_PLAYER, vol1);
	Mix_Volume(CH_MENU_SOUND, vol2);
	Mix_Volume(CH_MUSIC, vol2);
	Mix_Volume(CH_AMBIENT, vol2);
	Mix_Volume(CH_BATTLE, 20);
	Mix_VolumeMusic(vol2);

	SDL_ShowCursor(1);
}



void close()
{
	////Free loaded images
	//gFooTexture.free();
	//gBackgroundTexture.free();
	//gStartScreenText.free();
	//Free global font
	TTF_CloseFont(gFont);
	gFont = NULL;

	// Cleanup
	ImGui_ImplSDLRenderer_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	//Destroy window    
	SDL_DestroyRenderer(app.renderer);
	SDL_DestroyWindow(app.window);
	app.renderer = NULL;
	app.window = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}