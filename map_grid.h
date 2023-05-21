#ifndef MAP_HEADERS
#define MAP_HEADERS

static const int GRID_WIDTH = 4;
static const int GRID_HEIGHT = 1;
static const int GRID_MOVE = 105;


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
	int getPrevX();
	int getPrevY();
	GridTile getCurrentTile();
	GridTile* getCurrentTilePtr();
	GridTile getPrevTile();
	GridTile* getPrevTilePtr();
private:
	std::vector<std::vector<GridTile>> grid;
	int currentX;
	int currentY;
	int prevX;
	int prevY;
};




#endif 
