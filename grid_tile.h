#ifndef GRID_TILE_HEADERS
#define GRID_TILE_HEADERS



class GridTile {
public:
	GridTile();
	~GridTile();
	void free();
	void setPos(Point p);
	void setType(TileType type);
	void triggerEvent(TileType eventType);
	TileType getType();
	Point getPos();
	bool getVisited();
	void setVisited(bool v);
	MapEvent* getEvent();

private:
	Point pos;
	TileType type;
	bool visited;
	MapEvent mEvent;
	// todo: add tile content and event trigger
};





#endif 
