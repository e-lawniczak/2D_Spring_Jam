#ifndef MAP_HEADERS
#define MAP_HEADERS

static const int GRID_WIDTH = 4;
static const int GRID_HEIGHT = 1;
static const int GRID_MOVE = 120;

class GridTile {
public:
	GridTile();
	~GridTile();
	void free();
	void setPos(Point p);
	void setType(TileType type);
	TileType getType();
	Point getPos();

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
private:
	std::vector<std::vector<GridTile>> grid;
	int currentX;
	int currentY;
};




#endif 
