#ifndef MAP_EVENT_HEADERS
#define MAP_EVENT_HEADERS

class MapEvent {
public:
	MapEvent();
	~MapEvent();
	void free();
	void encounterEvent(bool &eventPtr);
	void bossEvent(bool& eventPtr);
	void curioEvent();
	void itemEvent();
	void setEventFired(bool v);
	void setItem(Item v);
	void addEnemy(Unit v);
	void setBoss(Unit v);
	Item* getItem();
	std::vector<Unit> getEnemy();
	Unit getBoss();
	bool getEventFired();
	
private:
	bool eventFired;
	bool itemEventPtr;
	bool encounterEventPtr;
	bool curioEventPtr;
	bool bossEventPtr;
	Item item;
	std::vector<Unit> enemies;
	Unit boss;
<<<<<<< Updated upstream
	int windowWeight;
=======

>>>>>>> Stashed changes
};

#endif 
