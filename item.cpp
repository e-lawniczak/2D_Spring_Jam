#include "common.h"


Item::Item()
{
	hpMod = 0;
	atkMod = 0;
	defMod = 0;
	dogeMod = 0;
	type = OTHER;
	used = true;
}
Item::Item(std::string name, int hp, int atk, int def, int doge, ItemType t)
{
	this->name = name;
	hpMod = hp;
	atkMod = atk;
	defMod = def;
	dogeMod = doge;
	type = t;
	used = false;

}

Item::~Item()
{
	free();
}

void Item::free()
{
}

void Item::setHp(int v) { hpMod = v; }
void Item::setAtk(int v) { atkMod = v; }
void Item::setDef(int v) { defMod = v; }
void Item::setDoge(int v) { dogeMod = v; }
void Item::setType(ItemType v) { type = v; }
void Item::setName(std::string v) { name = v; }
void Item::setUsed(bool v) { used = v; }
int Item::getHp() { return hpMod; }
int Item::getAtk() { return atkMod; }
int Item::getDef() { return defMod; }
int Item::getDoge() { return dogeMod; }
int Item::getType() { return type; }
bool Item::getUsed() { return used; }
std::string Item::getName() { return name; }

