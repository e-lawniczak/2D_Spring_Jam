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
	std::vector<std::vector<GridTile>> getGrid();
	int setCurrentX(int v);
	int setCurrentY(int v);
	int getCurrentX();
	int getCurrentY();
private:
	std::vector<std::vector<GridTile>> grid;
	int currentX;
	int currentY;
};




#endif 
