#include "defs.h"
#ifndef STRUCTS_HEADERS
#define STRUCTS_HEADERS


typedef struct
{
	SDL_Renderer* renderer;
	SDL_Window* window;
	int keyboard[MAX_KEYBOARD_KEYS];
	int mouse[2];
	ImVec2 cursorPos;
} App;

#endif 
