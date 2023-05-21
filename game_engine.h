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
	void invokeTargetPicker(bool isStrong);
	void handleAttack(Unit& u, bool isStrong);
	MapGrid grid;
	Unit player;
	int timer;
	bool gameFinished;
	std::vector<Unit> currentEnemies;
	Unit currentBoss;
	bool encounterStarted;
	bool eqPtr;
	bool deadPtr;
	bool playerDead;
	bool valueChanged;
	//player
	int frameCount;
	bool playerAnimationState;
	int spriteDuration;
	
};

#endif 
