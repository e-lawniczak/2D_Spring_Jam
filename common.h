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
#include "texture.h"
#include "stage.h"
#include "screen.h"
#include "load_media.h"


extern App app;
extern LTexture gBackgroundTexture;
extern LTexture gTextTexture;
extern TTF_Font* gFont;
extern Stage mainStage;
extern Screen startScreen;
extern Screen gameScreen;
extern Screen endScreen;

#endif 
