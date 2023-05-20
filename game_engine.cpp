#include "common.h"

GameEngine::GameEngine()
{
	grid = MapGrid();
	Point pt= grid.getCurrentTile().getPos();
	player = Unit();
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
	handleOverlandMovement();


	GridTile* tile = grid.getCurrentTilePtr();
	if (tile->getType() != EMPTY && !tile->getEvent()->getEventFired()) {
		tile->triggerEvent(tile->getType());
	}
	else if (tile->getEvent()->getEventFired()) {
		player.setMoved(false);
	}
	else if (tile->getType() == EMPTY) {
		player.setMoved(false);
	}
	if (tile->getType() == ENCOUNTER || tile->getType() == BOSS) {
		handleEncounter(tile);
	}

}

void GameEngine::handleOverlandMovement()
{
	int moveX = grid.getCurrentX();
	int moveY = grid.getCurrentY();
	if (app.keyboard[SDL_SCANCODE_RIGHT] && !player.getMoved()) {
		moveX++;
		if (moveX < GRID_WIDTH) {
			std::vector<std::vector<GridTile>> g = grid.getGrid();
			GridTile t = g[moveX][moveY];
			player.getPos()->newPos(t.getPos());
			player.setMoved(true);

		}
	}
	if (app.keyboard[SDL_SCANCODE_LEFT] && !player.getMoved()) {
		moveX--;
		if (moveX >= 0) {
			std::vector<std::vector<GridTile>> g = grid.getGrid();
			GridTile t = g[moveX][moveY];
			player.getPos()->newPos(t.getPos());
			player.setMoved(true);

		}
	}
	if (app.keyboard[SDL_SCANCODE_UP] && !player.getMoved()) {
		moveY--;

		if (moveY >= 0) {
			std::vector<std::vector<GridTile>> g = grid.getGrid();
			GridTile t = g[moveX][moveY];
			player.getPos()->newPos(t.getPos());
			player.setMoved(true);
		}
	}
	if (app.keyboard[SDL_SCANCODE_DOWN] && !player.getMoved()) {
		moveY++;

		if (moveY < GRID_HEIGHT) {
			std::vector<std::vector<GridTile>> g = grid.getGrid();
			GridTile t = g[moveX][moveY];
			player.getPos()->newPos(t.getPos());
			player.setMoved(true);
		}
	}
	if (player.getMoved()) {
		grid.getCurrentTilePtr()->setVisited(true);
		grid.setCurrentX(moveX);
		grid.setCurrentY(moveY);
	}
}

void GameEngine::handleEncounter(GridTile* tile)
{
	gBackgroundTexture.loadFromFile("img/encounter_bg.png");
	std::vector<Unit>* enemies = tile->getEvent()->getEnemy();

	if (app.keyboard[SDL_SCANCODE_H] && !enemies->empty()) {
		enemies->pop_back();
	}

	if (tile->getEvent()->getEventFired()) {
		gBackgroundTexture.loadFromFile("img/overland_map.png");
	}
}
