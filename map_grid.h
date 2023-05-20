#ifndef MAP_HEADERS
#define MAP_HEADERS

static const int GRID_WIDTH = 4;
static const int GRID_HEIGHT = 1;
static const int GRID_MOVE = 105;

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

private:
	Point pos;
	TileType type;
	bool visited;
	// todo: add tile content and event trigger
};

class MapGrid {
public:
	MapGrid();
	~MapGrid();
	void free();
	std::vector<std::vector<GridTile>> getGrid();
	void setCurrentX(int v);
	void setCurrentY(int v);
	int getCurrentX();
	int getCurrentY();
	GridTile getCurrentTile();
	GridTile* getCurrentTilePtr();
private:
	std::vector<std::vector<GridTile>> grid;
	int currentX;
	int currentY;
};




#endif 
