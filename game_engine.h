#include "common.h"

#ifndef ENGINE_HEADERS
#define ENGINE_HEADERS

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

	
};

#endif 
