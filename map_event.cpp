#include "common.h"
#include "sound.h"
MapEvent::MapEvent()
{
	eventFired = false;
	itemEventPtr = true;
	encounterEventPtr = true;
	curioEventPtr = true;
	bossEventPtr = true;
	item = Item();
	enemies = std::vector<Unit>();
	boss = Unit();
	windowWeight = 300;
}

MapEvent::~MapEvent()
{
	free();
}

void MapEvent::free()
{
}

void MapEvent::encounterEvent()
{
	if (Mix_Playing(CH_MUSIC))
		stopChannel(CH_MUSIC);

	if (!Mix_Playing(CH_BATTLE))
		playChannel(SND_BATTLE, CH_BATTLE, 1);

	if (enemies.empty()) {
		
		ImGui::SetNextWindowPos(ImVec2(SCREEN_WIDTH / 2 - (windowWeight/2), 20));
		ImGui::SetNextWindowSize(ImVec2(windowWeight, 80));
		ImGui::Begin("Encounter event", &encounterEventPtr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
		ImGui::Text("You defeated the foe!");
		if (ImGui::Button("Awesome!")) {
			if (Mix_Playing(CH_BATTLE))
				stopChannel(CH_BATTLE);

			if (!Mix_Playing(CH_MUSIC))
				playChannel(SND_MAIN_THEME, CH_MUSIC, 1);
			playSound(SND_CONFIRM, CH_PLAYER);
			eventFired = true;
			encounterEventPtr = false;
		}
		ImGui::End();
	}
}

void MapEvent::bossEvent()
{
	if (Mix_Playing(CH_MUSIC))
		stopChannel(CH_MUSIC);

	if (!Mix_Playing(CH_BATTLE))
		playChannel(SND_BATTLE, CH_BATTLE, 1);
	if (enemies.empty() && boss.getHp() <= 0) {
		ImGui::SetNextWindowPos(ImVec2(SCREEN_WIDTH / 2 - (windowWeight / 2), 20));
		ImGui::SetNextWindowSize(ImVec2(windowWeight, 80));
		ImGui::Begin("Encounter event", &bossEventPtr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
		ImGui::Text("You defeated the BOSS!");

		if (ImGui::Button("Awesome!")) {
			if (Mix_Playing(CH_BATTLE))
				stopChannel(CH_BATTLE);

			if (!Mix_Playing(CH_MUSIC))
				playChannel(SND_MAIN_THEME, CH_MUSIC, 1);
			playSound(SND_CONFIRM, CH_PLAYER);
			eventFired = true;
			bossEventPtr = false;
		}
		ImGui::End();
	}
}

void MapEvent::curioEvent()
{
}

void MapEvent::itemEvent()
{
	ImGui::SetNextWindowPos(ImVec2(SCREEN_WIDTH / 2 - (windowWeight / 4), 20));
	ImGui::SetNextWindowSize(ImVec2(windowWeight / 2, 250));
	ImGui::Begin("Item event", &itemEventPtr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
	ImGui::Text("You found an item!");
	ImGui::Text(item.getName().c_str());
	ImGui::Text("Atk: %d", item.getAtk());
	ImGui::Text("Hp: %d", item.getHp());
	ImGui::Text("Def: %d", item.getDef());
	ImGui::Text("Doge: %d", item.getDoge());

	if (ImGui::Button("Awesome!")) {
		playSound(SND_CONFIRM, CH_PLAYER);
		eventFired = true;
		itemEventPtr = false;
	}
	ImGui::End();
}

void MapEvent::setEventFired(bool v)
{
	eventFired = v;
}

void MapEvent::setItem(Item v)
{
	item = v;
}

void MapEvent::addEnemy(Unit v)
{
	enemies.push_back(v);
}

void MapEvent::setBoss(Unit v)
{
	boss = v;
}

Item* MapEvent::getItem()
{
	return &item;
}

std::vector<Unit>* MapEvent::getEnemy()
{
	return &enemies;
}

Unit* MapEvent::getBoss()
{
	if (boss.getName().length() <= 0 || boss.getHp() <= 0) {
		return nullptr;
	}
	return &boss;
}

bool MapEvent::getEventFired()
{
	return eventFired;
}
