#include "common.h"

void prepareScene(Screens screen)
{
	if (screen == GAME_SCREEN) {
		SDL_SetRenderDrawColor(app.renderer, 173, 239, 255, 255);
	}
	else {
		SDL_SetRenderDrawColor(app.renderer, 173, 239, 124, 255);
	}
	SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
	SDL_RenderPresent(app.renderer);
}