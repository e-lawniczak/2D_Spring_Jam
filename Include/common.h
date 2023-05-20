#ifndef COMMON_HEADERS
#define COMMON_HEADERS

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <ctime>

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>


#include "defs.h"
#include "point.h"
#include "app.h"
#include "load_media.h"
#include "map_grid.h"
#include "entity.h"


extern App app;
extern TTF_Font* gFont;

#endif