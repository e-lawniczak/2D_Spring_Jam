#include "common.h"

GameEngine::GameEngine()
{
	grid = MapGrid();
	Point pt= grid.getCurrentTile().getPos();
	player = Unit();
	timer = MOVEMENT_DELAY;
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
	player.setTexture("img/player.png");
	player.setHp(10);
	player.setAtk(10);
	player.move(grid.getCurrentTile().getPos());

}

void GameEngine::gameLoop()
{
	player.render();
	player.handleOverlandMovement(&grid);
	timer--;
	if (!timer) {
		// timer is temporary solution to infinite moving
		player.setMoved(false);
		timer = MOVEMENT_DELAY;
	}
}
