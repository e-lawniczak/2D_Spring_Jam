#include "common.h"

Unit::Unit()
{
	hp = 1;
	atk = 0;
	def = 0;
	doge = 0;
	isRanged = 0;
}
Unit::Unit(int x, int y, std::string path, std::string name, int hp, int atk, int def, int doge, bool isRanged) : Entity(x, y, path, name)
{
	this->hp = hp;
	this->atk = atk;
	this->def = def;
	this->doge = doge;
	this->isRanged = isRanged;
}

Unit::~Unit()
{
	free();
}

void Unit::free()
{
}

void Unit::setHp(int v) { hp = v; }
void Unit::setAtk(int v) { atk = v; }
void Unit::setDef(int v) { def = v; }
void Unit::setDoge(int v) { doge = v; }
void Unit::setIsRanged(int v) { isRanged = v; }
int Unit::getHp(int v) { return hp; }
int Unit::getAtk(int v) { return atk; }
int Unit::getDef(int v) { return def; }
int Unit::getDoge(int v) { return doge	; }
bool Unit::getIsRanged(int v) { return isRanged; }

void Unit::dealDmg(int dmg) {
	if (hp > 0) {
		hp -= dmg;
	}
	if (hp <= 0) {
		std::cout << this->getName() << " is down" << std::endl;
	}
}

void Unit::attackUnit(Unit* u)
{
	int dmgDone = std::max(atk - u->def, 0);
	if (rand() % 101 > u->doge) {
		u->dealDmg(dmgDone);
	}

	if (!isRanged) {
		dmgDone = std::max(u->atk - def, 0);
		dealDmg(dmgDone);
	}

	if (isRanged && u->isRanged) {
		dmgDone = std::max(u->atk - def, 0);
		dealDmg(dmgDone);
	}
}
