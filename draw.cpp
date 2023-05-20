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
	ImGui::Render();
	//SDL_RenderSetScale(app.renderer, IO.DisplayFramebufferScale.x, IO.DisplayFramebufferScale.y);
	////SDL_SetRenderDrawColor(app.renderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
	//SDL_RenderClear(app.renderer);
	//ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(app.renderer);
}