#include "common.h"

App::App() {
    this->renderScreenPtr = &App::renderStartScreen;
}

void App::renderStartScreen() {
	SDL_SetRenderDrawColor(this->renderer, 173, 239, 124, 255);
	SDL_RenderClear(this->renderer);

    //TODO: Render text "Press q to end" to screen with a listener

    //TODO:
    /*
    // This
    currentScreen.logic();
	// go to the game screen on LMB click
	if (app.mouse[LMB] && getScreen().getType() == START_SCREEN) {
		gameScreen.setText("Press q to end");
		changeScreen(gameScreen);
	}


	// end the game temporary by clicking q
	if (app.keyboard[SDL_SCANCODE_Q] && getScreen().getType() == GAME_SCREEN) {
		endScreen.setText("Thanks for playing");
		changeScreen(endScreen);
	}
    */
}

void App::renderGameScreen() {
	SDL_SetRenderDrawColor(this->renderer, 173, 239, 255, 255);
	SDL_RenderClear(this->renderer);

    /*
    Entity player(200, SCREEN_HEIGHT / 2, "img/player.png", "Player");
	gBackgroundTexture.render(0, 0);
	LTexture* currentTex = getTexture();
	currentTex->render(10, 10);
	player.getPos()->setY(SCREEN_HEIGHT/2 - player.getTexture()->getWidth() + 20);
	player.getPos()->setX(450);
	player.render();
    */
}

void App::renderEndScreen() {
    SDL_SetRenderDrawColor(this->renderer, 173, 239, 124, 255);
    SDL_RenderClear(this->renderer);
}

void App::presentScene() {
	SDL_RenderPresent(this->renderer);
}

void App::changeScreen(int screen) {
    switch (screen) {
		case 0:
			this->renderScreenPtr = &App::renderStartScreen;
			this->inputScreenPtr = &App::inputStartScreen;
			break;
		case 1:
			this->renderScreenPtr = &App::renderGameScreen;
			this->inputScreenPtr = &App::inputGameScreen;
			break;
		case 2:
			this->renderScreenPtr = &App::renderEndScreen;
			this->inputScreenPtr = &App::inputEndScreen;
			break;
		default:
			throw std::runtime_error("Invalid screen.\
				Inputs range from 0 to 2 inclusive.\n\
				0: Start Screen\n1: Game Screen\n2: End Screen");
	}
}

void App::free() {}

void App::logic() {
	while (SDL_PollEvent(&this->event)) {
		switch (this->event.type) {
			case SDL_QUIT:
				this->running = false;
			case (SDL_KEYDOWN):
				(app.*(app.inputScreenPtr))(event.key.keysym.sym);
		}
	}
}

void App::inputStartScreen(SDL_Keycode key) {}
void App::inputGameScreen(SDL_Keycode key) {}
void App::inputEndScreen(SDL_Keycode key) {}