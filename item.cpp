#include "common.h"


Item::Item()
{
	hpMod = 0;
	atkMod = 0;
	defMod = 0;
	dogeMod = 0;
	type = OTHER;
}
Item::Item(int hp, int atk, int def, int doge, ItemType t)
{

	hpMod =hp ;
	atkMod = atk;
	defMod = def;
	dogeMod = doge;
	type = t;
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
int Item::getHp() { return hpMod; }
int Item::getAtk() { return atkMod; }
int Item::getDef() { return defMod; }
int Item::getDoge() { return dogeMod; }
int Item::getType() { return type; }
