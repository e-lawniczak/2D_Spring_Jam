#ifndef UNIT_HEADERS
#define UNIT_HEADERS

class Unit :public Entity {
public:
	Entity::Entity;
	Unit();
	explicit Unit(int x, int y, std::string path, std::string name, int hp, int atk, int def, int doge, bool isRanged) ;
	~Unit();
	void free();
	void setHp(int v);
	void setAtk(int v);
	void setDef(int v);
	void setDoge(int v);
	void setIsRanged(int v);
	int getHp(int v);
	int getAtk(int v);
	int getDef(int v);
	int getDoge(int v);
	bool getIsRanged(int v);

	void dealDmg(int dmg);

	void attackUnit(Unit* u);

private:
	int hp;
	int atk;
	int def;
	int doge; //doge value is between 0 and 100
	bool isRanged;
};


#endif 
