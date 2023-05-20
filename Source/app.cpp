#include "HEADER.h"

Game::Game() {
    this->renderScreenPtr = &Game::renderStartScreen;
}

void Game::renderStartScreen() {
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

void Game::renderGameScreen() {
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

void Game::renderEndScreen() {
    SDL_SetRenderDrawColor(this->renderer, 173, 239, 124, 255);
    SDL_RenderClear(this->renderer);
}

void Game::presentScene() {
	SDL_RenderPresent(this->renderer);
}

void Game::changeScreen(int screen) {
    switch (screen) {
		case 0:
			this->renderScreenPtr = &Game::renderStartScreen;
			this->inputScreenPtr = &Game::inputStartScreen;
			break;
		case 1:
			this->renderScreenPtr = &Game::renderGameScreen;
			this->inputScreenPtr = &Game::inputGameScreen;
			break;
		case 2:
			this->renderScreenPtr = &Game::renderEndScreen;
			this->inputScreenPtr = &Game::inputEndScreen;
			break;
		default:
			throw std::runtime_error("Invalid screen.\
				Inputs range from 0 to 2 inclusive.\n\
				0: Start Screen\n1: Game Screen\n2: End Screen");
	}
}

void Game::free() {}

void Game::logic() {
	while (SDL_PollEvent(&this->event)) {
		switch (this->event.type) {
			case SDL_QUIT:
				this->running = false;
			case (SDL_KEYDOWN):
				(this->*(this->inputScreenPtr))(event.key.keysym.sym);
		}
	}
}

void Game::inputStartScreen(SDL_Keycode key) {}
void Game::inputGameScreen(SDL_Keycode key) {}
void Game::inputEndScreen(SDL_Keycode key) {}