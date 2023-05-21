#include "common.h"

/**
 * @brief Put all the ImGui widgets here
 * 
 * @param screen The type of screen
 */
void renderImGuiOverlay(Screens screen) {
	switch (screen) {
		case START_SCREEN:
			static int flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollWithMouse;
			ImGui::Begin(" ", NULL, flags | ImGuiWindowFlags_NoBackground);
			ImGui::SetWindowPos(ImVec2(0, 0));
			throw std::runtime_error("Replace Win Width and win height with the window sizes");
			ImGui::SetWindowSize(ImVec2(WIN_WIDTH, WIN_HEIGHT));
			ImGui::SetCursorPos(ImVec2(WIN_WIDTH / 2 - 128, WIN_HEIGHT / 2 - 256));
			ImGui::BeginChild(ImGuiID(0x01), ImVec2(256, 512), true, flags);

			// Computes the title
			std::string title = "Welcome to Chicken RPG!\nPress 'SPACE' to start.";
			int titleSize = ImGui::CalcTextSize(title.c_str()).x;
			ImGui::SetCursorPos(ImVec2(256 / 2 - titleSize / 2, 16));
			ImGui::Text(title.c_str());

			ImGui::Separator();

			cursorPos = ImGui::GetCursorPos();
			ImGui::SetCursorPos(ImVec2(256 / 2 - 50, cursorPos.y));
			if (ImGui::Button("Play", ImVec2(100, 20))) {
			}
			cursorPos = ImGui::GetCursorPos();
			ImGui::SetCursorPos(ImVec2(256 / 2 - 50, cursorPos.y));
			if (ImGui::Button("Exit", ImVec2(100, 20))) {
			}
			break:
		case GAME_SCREEN:
			SDL_SetRenderDrawColor(app.renderer, 173, 239, 255, 255);
			SDL_RenderClear(app.renderer);
			break;
		case END_SCREEN:
			SDL_SetRenderDrawColor(app.renderer, 173, 239, 124, 255);
			SDL_RenderClear(app.renderer);
			break;
        default:
			break;
	}
}

/**
 * @brief SDL Stuff, like movement or sprite rendering
 * 
 * @param screen Type of screen
 */
void renderSDL2Overlay(Screens screen) {
	switch (screen) {
		case START_SCREEN:
			SDL_SetRenderDrawColor(app.renderer, 173, 239, 124, 255);
			SDL_RenderClear(app.renderer);
			static SDL_Rect rect = SDL_Rect(WIN_WIDTH / 2 - 128, WIN_HEIGHT / 2 - 256, 256, 512);
			SDL_SetRenderDrawColor(game->renderer, 0x9d, 0xdf, 0x6c, 0xff);
			SDL_RenderFillRect(game->renderer, &rect);
			break:
		case GAME_SCREEN:
			SDL_SetRenderDrawColor(app.renderer, 173, 239, 255, 255);
			SDL_RenderClear(app.renderer);
			break;
		case END_SCREEN:
			SDL_SetRenderDrawColor(app.renderer, 173, 239, 124, 255);
			SDL_RenderClear(app.renderer);
			break;
        default:
			break;
	}
}

void presentScene(Screens screen)
{
	ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

	renderImGuiOverlay(screen)

	ImGui::Render();
	SDL_RenderSetScale(app.renderer, IO.DisplayFramebufferScale.x, IO.DisplayFramebufferScale.y);
	////SDL_SetRenderDrawColor(app.renderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
	//SDL_RenderClear(app.renderer);
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());

	renderSDL2Overlay(screen);

	SDL_RenderPresent(app.renderer);
}