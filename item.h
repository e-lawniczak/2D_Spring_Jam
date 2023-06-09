#ifndef ITEM_HEADERS
#define ITEM_HEADERS

class Item  {
public:
	Item();
	Item(std::string name, int hp, int atk, int def, int doge, ItemType t);
	~Item();
	void free();
	void setName(std::string v);
	void setHp(int v);
	void setAtk(int v);
	void setDef(int v);
	void setDoge(int v);
	void setType(ItemType v);
	void setUsed(bool v);
	std::string getName();
	int getHp();
	int getAtk();
	int getDef();
	int getDoge();
	int getType();
	bool getUsed();


private:
	std::string name;
	int hpMod;
	int atkMod;
	int defMod;
	int dogeMod; //doge value is between 0 and 100
	ItemType type;
	bool used;
};


#endif 
