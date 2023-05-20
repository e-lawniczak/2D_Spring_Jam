#pragma once
#include "HEADER.h"

class Game {
	public:
		// Function pointer. If we call this function pointer, it will call the function it is pointing to
		// This will take care that all of the right stuff is being drawn.
		// WARNING: PLEASE DO NOT TOUCH THIS. ITS EFFICIENT, ITS FAST, BUT UNSTABLE
		// IF YOU MODIFY ONE THING, IT MAY NO LONGER WORK
		void (Game::*renderScreenPtr)() = nullptr;
		void (Game::*inputScreenPtr)(SDL_Keycode) = nullptr;
		bool running = true;
		Game();
		//- ~Game();
		void changeScreen(int screen);
		void free();
		void logic();
		// Function to render the start screen. ImGui stuff might go here, or general launcher stuff
		void renderStartScreen();
		void inputStartScreen(SDL_Keycode key);
		// Function to render the game screen. The game loop. Do stuff which works
		void renderGameScreen();
		void inputGameScreen(SDL_Keycode key);
		// Function to render the end screen. Death or something i dont know
		void renderEndScreen();
		void inputEndScreen(SDL_Keycode key);

		// I dont know what this does but i trust you
		void presentScene();

		SDL_Window * window = nullptr;
		SDL_Renderer * renderer = nullptr;
	private:
		SDL_Event event;
		//Entity player;

};
