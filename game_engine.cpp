#include "common.h"

GameEngine::GameEngine()
{
	grid = MapGrid();
	Unit p(PLAYER_START_W, PLAYER_START_H, "img/player.png", "Player", 2, 2, 2, 2, 0);
	player = p;
}

GameEngine::~GameEngine()
{
	free();
}

void GameEngine::free()
{
}

void GameEngine::init()
{
}

void GameEngine::gameLoop()
{
	player.render();
	
	player.handleOverlandMovement(&grid);
	if (app.keyboard[SDL_SCANCODE_0]) {
		player.setMoved(false);
	}
}
