#ifndef COMMON_HEADERS
#define COMMON_HEADERS
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <cstdio>
#include<vector>
#include<SDL.h>
#include<SDL_image.h>
#include <string>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

#include "imgui.h"
#include "imgui_impl_sdlrenderer.h"
#include "imgui_impl_sdl2.h"
#include "imgui_internal.h"
#include "imgui_util.h"


#include "structs.h"
#include "defs.h"
#include "point.h"
#include "texture.h"
#include "load_media.h"
#include "item.h"
#include "entity.h"
#include "unit.h"
#include "map_event.h"
#include "grid_tile.h"
#include"static_lists.h"
#include "map_grid.h"
#include "game_engine.h"

extern App app;
extern LTexture gBackgroundTexture;
extern LTexture gEndScreenTexture;
extern LTexture enemy1tex;
extern LTexture enemy2tex;
extern LTexture gTextTexture;
extern TTF_Font* gFont;


#endif 
