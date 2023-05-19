#include "common.h"
#include "init.h"

App app;
int main(int argc, char* argv[]) {
	std::cout << "Hello world;" << std::endl;
	initSDL();
	//Hacky way to make the window stay
	SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
	return 0;
}