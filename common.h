#ifndef COMMON_HEADERS
#define COMMON_HEADERS
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <cstdio>

#include<SDL.h>
#include<SDL_image.h>
#include <string>
#include<SDL_mixer.h>
#include<SDL_ttf.h>


#include "structs.h"
#include "defs.h"
#include "point.h"
#include "texture.h"
#include "load_media.h"
#include "item.h"
#include "entity.h"
#include "map_grid.h"
#include "unit.h"

extern App app;
extern LTexture gBackgroundTexture;
extern LTexture gTextTexture;
extern TTF_Font* gFont;


#endif 
