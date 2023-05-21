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
	deadPtr = false;
	frameCount = 0;
	playerAnimationState = true;
	spriteDuration = 30;
	playerDead = false;
	valueChanged = false;
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
	player.setHp(50);
	player.setAtk(10);
	player.setMaxHp(50);
	frameCount = 0;
	player.move(grid.getCurrentTile().getPos());

}

void GameEngine::resetFrameCounterEvery(int floor) {
	if (frameCount % floor == 0) {
		frameCount = 0;
	}
}

void GameEngine::gameLoop()
{
	//player.move(grid.getCurrentTile().getPos());
	handleOverlandMovement();
	displayPlayerStats();


	GridTile* tile = grid.getCurrentTilePtr();

	if (player.getHp() <= 0) {
		if (!playerDead) {
			playerDead = true;
			encounterStarted = false;
			tile->triggerEvent(tile->getType(), encounterStarted);
			tile->getEvent()->setEventFired(false);
			tile->setVisited(false);
			deadPtr = true;
			currentEnemies = std::vector<Unit>();
			currentBoss = Unit();
			grid.setCurrentX(grid.getPrevX());
			grid.setCurrentY(grid.getPrevY());
			gBackgroundTexture.loadFromFile("img/overland_map.png");
			gBackgroundTexture.render(0, 0);
			tile->triggerEvent(tile->getType(), encounterStarted);
			if (Mix_Playing(CH_BATTLE))
				stopChannel(CH_BATTLE);

			if (!Mix_Playing(CH_MUSIC))
				playChannel(SND_MAIN_THEME, CH_MUSIC, 1);
		}
		ImGui::SetNextWindowPos(ImVec2(SCREEN_WIDTH / 2 - 125, SCREEN_HEIGHT / 3 ));
		ImGui::SetNextWindowSize(ImVec2(250, 200));
		ImGui::Begin("You died!", &deadPtr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
		ImGui::Text("You were felled by a powerful foe!");
		ImGui::Text("But you can't stop here!");
		if (ImGui::Button("Rest and continue!")) {
			player.setHp(player.getMaxHp());
			playSound(SND_CONFIRM, CH_PLAYER);
			playerDead = false;
			deadPtr = false;
		}
		if (ImGui::Button("Quit!?")) {
			playerDead = false;
			gameFinished = true;
			deadPtr = false;
		}
		ImGui::End();
	}
	else {
		if (tile->getType() != EMPTY && !tile->getEvent()->getEventFired()) {

			tile->triggerEvent(tile->getType(), encounterStarted);
		}
		else if (tile->getEvent()->getEventFired()) {
			player.setMoved(false);
		}
		else if (tile->getType() == EMPTY) {
			player.setMoved(false);
		}

		if ((tile->getType() == ENCOUNTER || tile->getType() == BOSS) && !tile->getEvent()->getEventFired()) {
			//encounterStarted = true;
			if (!encounterStarted && !currentEnemies.empty())
				encounterStarted = true;
			handleEncounter(tile);
			if (!tile->getVisited())
				tile->setVisited(true);

		}else if (tile->getEvent()->getEventFired()) {
			gBackgroundTexture.loadFromFile("img/overland_map.png");
			gBackgroundTexture.render(0, 0);
			player.move(grid.getCurrentTilePtr()->getPos());
		}

		if (tile->getType() == ITEM && !tile->getEvent()->getEventFired()) {
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
	}
	if (frameCount % spriteDuration == 0) {
		if (playerAnimationState) {
			player.setTexture("img/player/player01.png");
			playerAnimationState = false;
		}
		else
		{
			player.setTexture("img/player/player02.png");
			playerAnimationState = true;
		}
	}
	resetFrameCounterEvery(spriteDuration * 2);
	frameCount += 1;
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

	std::cout << currentEnemies.size() << "\n";
	if (!currentEnemies.empty()) {
		for (int i = 0; i < n; i++) {
			Unit* u = &currentEnemies.at(i);
			if (u->getHp() <= 0) {
				currentEnemies.erase(currentEnemies.begin() + i);
			}
		}
	}
	//else if (app.keyboard[SDL_SCANCODE_G] && currentBoss.getHp() > 0) {
	//	std::cout << currentBoss.getName() << std::endl;
	//	playSound(SND_HIT, CH_PLAYER);
	//	player.basicAttackUnit(&currentBoss);
	//}

	if (encounterStarted && currentEnemies.empty() && currentBoss.getHp() <= 0) {
		encounterStarted = false;
		//tile->getEvent()->setEventFired(true);
	}

	

	
}

void GameEngine::displayPlayerStats()
{
	static int flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove;
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(250, SCREEN_HEIGHT));
	ImGui::Begin("Chicken!", &eqPtr, flags);
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
		Unit* enemy;
		if (currentEnemies.size() > 0) {
			enemy = &currentEnemies[currentEnemies.size() - 1];
		}
		else {
			enemy = &currentBoss;
		}

		if (ImGui::Button("Normal attack")) {
			player.basicAttackUnit(enemy);


		}
		if (ImGui::Button("Strong attack")) {
			player.strongAttackUnit(enemy);

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
			valueChanged = false;

		}
	}
	if (app.keyboard[SDL_SCANCODE_LEFT] && !player.getMoved()) {
		moveX--;
		if (moveX >= 0) {
			std::vector<std::vector<GridTile>> g = grid.getGrid();
			GridTile t = g[moveX][moveY];
			player.getPos()->newPos(t.getPos());
			player.setMoved(true);
			valueChanged = false;

		}
	}
	if (app.keyboard[SDL_SCANCODE_UP] && !player.getMoved()) {
		moveY--;

		if (moveY >= 0) {
			std::vector<std::vector<GridTile>> g = grid.getGrid();
			GridTile t = g[moveX][moveY];
			player.getPos()->newPos(t.getPos());
			player.setMoved(true);
			valueChanged = false;
		}
	}
	if (app.keyboard[SDL_SCANCODE_DOWN] && !player.getMoved()) {
		moveY++;

		if (moveY < GRID_HEIGHT) {
			std::vector<std::vector<GridTile>> g = grid.getGrid();
			GridTile t = g[moveX][moveY];
			player.getPos()->newPos(t.getPos());
			player.setMoved(true);
			valueChanged = false;
		}
	}
	if (player.getMoved() && !valueChanged) {
		grid.setCurrentX(moveX);
		grid.setCurrentY(moveY);
		valueChanged = true;
	}
}

bool GameEngine::getGameFinished()
{
	return gameFinished;
}

