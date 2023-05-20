#ifndef MAP_HEADERS
#define MAP_HEADERS

static const int GRID_WIDTH = 4;
static const int GRID_HEIGHT = 1;

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
private:
	GridTile grid[GRID_HEIGHT][GRID_WIDTH];
};




#endif 
