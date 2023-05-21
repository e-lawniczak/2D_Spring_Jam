#include "common.h"
#include <algorithm>
GameEngine::GameEngine()
{
	grid = MapGrid();
	Point pt= grid.getCurrentTile().getPos();
	player = Unit();
	gameFinished = false;
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
	player.setIsMonster(0);
	player.setHp(10);
	player.setAtk(10);

}

void GameEngine::gameLoop()
{
	player.move(grid.getCurrentTile().getPos());
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

	if (tile->getType() == BOSS && tile->getEvent()->getEventFired()) {
		gameFinished = true;
	}

	player.render();

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

bool GameEngine::getGameFinished()
{
	return gameFinished;
}

void GameEngine::handleEncounter(GridTile* tile)
{
	gBackgroundTexture.loadFromFile("img/encounter_bg.png");
	gBackgroundTexture.render(0, 0);
	std::vector<Unit>* enemies = tile->getEvent()->getEnemy();
	Unit* boss = tile->getEvent()->getBoss();
	int n = enemies->size();
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			Unit* u = &enemies->at(i);
			u->move(Point(((SCREEN_WIDTH / 3) * 2), 400 + (i * 100)));
			std::string x = u->getName();
			for (int k = 0; k < strlen(x.c_str()); k++)
				tolower(x[k]);
			std::replace(x.begin(), x.end(), ' ', '_');
			u->setTexture("img/" + (x)+".png");
			u->render();
		}
	}
	if (boss != nullptr) {
		std::string x = boss->getName();
		for (int k = 0; k < strlen(x.c_str()); k++)
			tolower(x[k]);
		std::replace(x.begin(), x.end(), ' ', '_');
		boss->setTexture("img/" + (x)+".png");
		boss->move(Point(((SCREEN_WIDTH / 3) * 2) + 200, 400));
		boss->render();
	}
	player.move(Point((SCREEN_WIDTH / 3), SCREEN_HEIGHT / 2));

	if (app.keyboard[SDL_SCANCODE_H] && !enemies->empty()) {
		enemies->pop_back();
	}
	else if (app.keyboard[SDL_SCANCODE_G] && boss != nullptr) {
		boss = nullptr;
		tile->getEvent()->setBoss(Unit());

	}

	if (tile->getEvent()->getEventFired()) {
		gBackgroundTexture.loadFromFile("img/overland_map.png");
		gBackgroundTexture.render(0, 0);
		player.move(grid.getCurrentTilePtr()->getPos());
	}
}
