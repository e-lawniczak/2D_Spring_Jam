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
	void handleOverlandMovement();
	bool getGameFinished();
	void resetFrameCounterEvery(int floor);
	
private:
	void handleEncounter(GridTile* tile);
	void displayPlayerStats();
	MapGrid grid;
	Unit player;
	int timer;
	bool gameFinished;
	std::vector<Unit> currentEnemies;
	Unit currentBoss;
	bool encounterStarted;
	bool eqPtr;

	//player
	int frameCount;
	bool playerAnimationState;
	int spriteDuration;
	
};

#endif 
