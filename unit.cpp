#include "common.h"

Unit::Unit()
{
	hp = 0;
	maxHp = 0;
	atk = 0;
	def = 0;
	doge = 0;
	isRanged = 0;
	isMonster = 1;
	equipment = std::vector<Item>();
	hpBonus = 0;
	maxHpBonus = 0;
	atkBonus = 0;
	defBonus = 0;
	dogeBonus = 0;
}
Unit::Unit(int x, int y, std::string path, std::string name, int hp, int atk, int def, int doge, bool isRanged) : Entity(x, y, path, name)
{
	this->hp = hp;
	this->maxHp = hp;
	this->atk = atk;
	this->def = def;
	this->doge = doge;
	this->isRanged = isRanged;
	isMonster = 1;
	equipment = std::vector<Item>();
	hpBonus = 0;
	maxHpBonus = 0;
	atkBonus = 0;
	defBonus = 0;
	dogeBonus = 0;
}

Unit::~Unit()
{
	free();
}

void Unit::free()
{
}

void Unit::setHp(int v) { hp = v; }
void Unit::setMaxHp(int v) { maxHp = v; }
void Unit::setAtk(int v) { atk = v; }
void Unit::setDef(int v) { def = v; }
void Unit::setDoge(int v) { doge = v; }
void Unit::setIsRanged(int v) { isRanged = v; }
void Unit::setIsMonster(int v) { isMonster = v; }
void Unit::setHpBonus(int v) { hpBonus = v; }
void Unit::setAtkBonus(int v) { atkBonus= v; }
void Unit::setDefBonus(int v) { defBonus= v; }
void Unit::setDogeBonus(int v) { dogeBonus= v; }
int Unit::getHp() { return hp; }
int Unit::getMaxHp() { return maxHp; }
int Unit::getAtk() { return atk; }
int Unit::getDef() { return def; }
int Unit::getDoge() { return doge; }
int Unit::getHpBonus() { return hpBonus; }
int Unit::getAtkBonus() { return atkBonus; }
int Unit::getDefBonus() { return defBonus; }
int Unit::getDogeBonus() { return dogeBonus; }
bool Unit::getIsRanged() { return isRanged; }
bool Unit::getIsMonster() { return isMonster; }

std::vector<Item> Unit::getEq()
{
	return equipment;
}

void Unit::addEq(Item i)
{
	equipment.push_back(i);
}

void Unit::dealDmg(int dmg) {

	if (hp > 0) {
		hp -= dmg;
	}
}

void Unit::basicAttackUnit(Unit* u)
{
	int dmgDone = std::max(atk +  atkBonus - (u->def + u->defBonus), 0);
	if (rand() % 101 > u ->doge) {
		u->dealDmg(dmgDone);
	}

	if (!isRanged) {
		dmgDone = std::max(u->atk + u->atkBonus - (def + defBonus), 0);
		dealDmg(dmgDone);
	}

	if (isRanged && u->isRanged) {
		dmgDone = std::max(atk + atkBonus - (u->def + u->defBonus), 0);
		dealDmg(dmgDone);
	}
}

void Unit::strongAttackUnit(Unit* u)
{
	int mod = +10;
	int accMod = -40;
	int dmgDone = std::max(atk + mod + atkBonus - (u->def + u->defBonus), 0);
	int dogeCheck = std::max((rand() % 101) + accMod, 0);
	if (dogeCheck > (u->doge + u->dogeBonus)) {
		u->dealDmg(dmgDone);
	}

	if (!isRanged) {
		dmgDone = std::max(u->atk + u->atkBonus / 2 - (def + defBonus), 0);
		dealDmg(dmgDone);
	}

	if (isRanged && u->isRanged) {
		dmgDone = std::max(u->atk + u->atkBonus / 2 - (def + defBonus), 0);
		dealDmg(dmgDone);
	}
}
