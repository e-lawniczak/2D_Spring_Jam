#include "common.h"
#include <algorithm>
#include "sound.h"
GameEngine::GameEngine()
{
	grid = MapGrid();
	Point pt = grid.getCurrentTile().getPos();
	player = Unit();
	gameFinished = false;
	currentEnemies = std::vector<Unit>();
	currentBoss = Unit();
	encounterStarted = false;
	eqPtr = true;
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
	player.setMaxHp(10);
}

void GameEngine::gameLoop()
{
	player.move(grid.getCurrentTile().getPos());
	handleOverlandMovement();



	GridTile* tile = grid.getCurrentTilePtr();
	//std::cout << encounterStarted << currentEnemies.empty() << tile->getEvent()->getEventFired() << std::endl;
	if (tile->getType() != EMPTY && !tile->getEvent()->getEventFired()) {
	
		tile->triggerEvent(tile->getType(), encounterStarted);
	}
	else if (tile->getEvent()->getEventFired()) {
		player.setMoved(false);
	}
	else if (tile->getType() == EMPTY) {
		player.setMoved(false);
	}

	if (tile->getType() == ENCOUNTER || tile->getType() == BOSS) {
		//encounterStarted = true;
		if (!encounterStarted && !currentEnemies.empty())
			encounterStarted = true;
		handleEncounter(tile);
		if (!tile->getVisited())
			tile->setVisited(true);

	}

	if (tile->getType() == ITEM) {
		Item i = tile->getEvent()->getItem();
		if (!tile->getEvent()->getItem().getUsed()) {
			player.addEq(tile->getEvent()->getItem());
			player.setMaxHp(player.getMaxHp() + i.getHp());
			player.setHp(player.getHp() + i.getHp());
			player.setAtkBonus(player.getAtkBonus() + i.getAtk());
			player.setDefBonus(player.getDefBonus() + i.getDef());
			player.setDogeBonus(player.getDogeBonus() + i.getDoge());
		}
		tile->getEvent()->getItemPtr()->setUsed(true);

	}

	if (tile->getType() == BOSS && tile->getEvent()->getEventFired()) {
		gameFinished = true;
	}

	player.render();

}

void GameEngine::handleEncounter(GridTile* tile)
{
	gBackgroundTexture.loadFromFile("img/encounter_bg.png");
	gBackgroundTexture.render(0, 0);
	if (currentEnemies.empty() && !tile->getVisited()) {
		currentEnemies = tile->getEvent()->getEnemy();
	}
	if (currentBoss.getHp() <= 0 && !tile->getVisited()) {
		currentBoss = tile->getEvent()->getBoss();
	}
	int n = currentEnemies.size();
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			Unit* u = &currentEnemies.at(i);
			u->move(Point(((SCREEN_WIDTH / 3) * 2), 400 + (i * 100)));
			std::string x = u->getName();
			for (int k = 0; k < strlen(x.c_str()); k++)
				tolower(x[k]);
			std::replace(x.begin(), x.end(), ' ', '_');
			u->setTexture("img/" + (x)+".png");
			u->render();
		}
	}
	if (currentBoss.getHp() > 0) {
		std::string x = currentBoss.getName();
		for (int k = 0; k < strlen(x.c_str()); k++)
			tolower(x[k]);
		std::replace(x.begin(), x.end(), ' ', '_');
		currentBoss.setTexture("img/" + (x)+".png");
		currentBoss.move(Point(((SCREEN_WIDTH / 3) * 2) + 200, 400));
		currentBoss.render();
	}
	player.move(Point((SCREEN_WIDTH / 3), SCREEN_HEIGHT / 2));

	if (app.keyboard[SDL_SCANCODE_H] && !currentEnemies.empty()) {
		std::cout << currentEnemies.size() << std::endl;
		playSound(SND_HIT, CH_PLAYER);
		currentEnemies.pop_back();
	}
	else if (app.keyboard[SDL_SCANCODE_G] && currentBoss.getHp() > 0) {
		std::cout << currentBoss.getName() << std::endl;
		playSound(SND_HIT, CH_PLAYER);
		player.basicAttackUnit(&currentBoss);
	}

	if (encounterStarted && currentEnemies.empty() && currentBoss.getHp() <= 0) {
		encounterStarted = false;
		//tile->getEvent()->setEventFired(true);
	}

	if (tile->getEvent()->getEventFired()) {
		gBackgroundTexture.loadFromFile("img/overland_map.png");
		gBackgroundTexture.render(0, 0);
		player.move(grid.getCurrentTilePtr()->getPos());
	}
}

void GameEngine::displayPlayerStats()
{
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(250, SCREEN_HEIGHT));
	ImGui::Begin("Chicken!", &eqPtr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
	ImGui::Text("~~~~~~~~~~~~~~~~~~");
	ImGui::Text("STATS");
	ImGui::Text("Hp: %d/%d", player.getHp(), player.getMaxHp());
	ImGui::Text("Atk: %d + %d", player.getAtk(), player.getAtkBonus());
	ImGui::Text("Def: %d + %d", player.getDef(), player.getDefBonus());
	ImGui::Text("Doge: %d + %d", player.getDoge(), player.getDogeBonus());
	ImGui::Text("~~~~~~~~~~~~~~~~~~");
	ImGui::Text("ITEMS");
	for (Item i : player.getEq()) {
		ImGui::Text("%s\n\tatk: %d, def: %d, \n\tmaxHp: %d, doge: %d", i.getName().c_str(), i.getAtk(), i.getDef(), i.getHp(), i.getDoge());
	}
	if (encounterStarted) {
		ImGui::Text("~~~~~~~~~~~~~~~~~~");
		ImGui::Text("ACTIONS");
		if (ImGui::Button("Normal attack")) {

		}
		if (ImGui::Button("Strong attack")) {

		}
	}

	ImGui::End();

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
		grid.setCurrentX(moveX);
		grid.setCurrentY(moveY);
	}
}

bool GameEngine::getGameFinished()
{
	return gameFinished;
}

