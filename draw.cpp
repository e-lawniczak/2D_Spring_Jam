#include "common.h"

void prepareScene(void)
{
	SDL_SetRenderDrawColor(app.renderer, 173, 239, 124, 255);
	SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
	SDL_RenderPresent(app.renderer);
}