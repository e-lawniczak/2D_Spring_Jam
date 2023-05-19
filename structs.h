#include "defs.h"
#ifndef STRUCTS_HEADERS
#define STRUCTS_HEADERS

typedef struct
{
	void (*logic)();
	void (*draw)();
} Delegate;

typedef struct
{
	SDL_Renderer* renderer;
	SDL_Window* window;
	Delegate delegate;
	int keyboard[MAX_KEYBOARD_KEYS];
} App;

#endif 
