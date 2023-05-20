#include "common.h"

#ifndef ENGINE_HEADERS
#define ENGINE_HEADERS
static const int MOVEMENT_DELAY = 32;

class GameEngine {
public:
	GameEngine();
	~GameEngine();
	void free();
	void init();
	void gameLoop();
	
private:
	MapGrid grid;
	Unit player;
	int timer;

	
};

#endif 
