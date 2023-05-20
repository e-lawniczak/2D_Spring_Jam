#ifndef MAP_EVENT_HEADERS
#define MAP_EVENT_HEADERS

class MapEvent {
public:
	MapEvent();
	~MapEvent();
	void free();
	void encounterEvent();
	void bossEvent();
	void curioEvent();
	void itemEvent();
	void setEventFired(bool v);
	bool getEventFired();
	
private:
	bool eventFired;
	
};

#endif 
