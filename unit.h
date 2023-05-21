#ifndef UNIT_HEADERS
#define UNIT_HEADERS

class Unit :public Entity {
public:
	Entity::Entity;
	Unit();
	Unit(int x, int y, std::string path, std::string name, int hp, int atk, int def, int doge, bool isRanged);
	~Unit();
	void free();
	void setHp(int v);
	void setMaxHp(int v);
	void setAtk(int v);
	void setDef(int v);
	void setDoge(int v);
	void setIsRanged(int v);
	void setIsMonster(int v);
	void setHpBonus(int v);
	void setAtkBonus(int v);
	void setDefBonus(int v);
	void setDogeBonus(int v);
	int getHp();
	int getMaxHp();
	int getAtk();
	int getDef();
	int getDoge();
	bool getIsRanged();
	bool getIsMonster();
	int getHpBonus();
	int getAtkBonus();
	int getDefBonus();
	int getDogeBonus();
	std::vector<Item> getEq();
	void addEq(Item i);

	void dealDmg(int dmg);

	void basicAttackUnit(Unit* u);
	void strongAttackUnit(Unit* u);

private:
	int hp;
	int maxHp;
	int atk;
	int def;
	int doge; //doge value is between 0 and 100
	bool isRanged;
	bool isMonster;
	std::vector<Item> equipment;
	int hpBonus;
	int maxHpBonus;
	int atkBonus;
	int defBonus;
	int dogeBonus;
};


#endif 
