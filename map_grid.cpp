#include "common.h"



MapGrid::MapGrid()
{
	int start_w = 450, start_h = 310;
	currentX = 0;
	currentY = 0;

	std::vector<std::vector<GridTile>> vGrid(GRID_WIDTH, std::vector<GridTile>(GRID_HEIGHT, GridTile()));
	for (int i = 0; i < vGrid.size(); i++)
	{
		for (int j = 0; j < vGrid[i].size(); j++)
		{
			vGrid[i][j].setPos(Point(start_w + (i * GRID_MOVE), start_h + (j * GRID_MOVE)));
			if (i == 1) {
				vGrid[i][j].setType(ENCOUNTER);
			}
			if (i == 2) {
				vGrid[i][j].setType(ITEM);
			}
			if (i == 3) {
				vGrid[i][j].setType(BOSS);
			}
		}
	}
	grid = vGrid;
	//grid[h][w].setPos(Point(start_w + (w * 40), start_h + (h * 40)));
}

MapGrid::~MapGrid()
{
	MapGrid::free();
}

void MapGrid::free()
{
}

std::vector<std::vector<GridTile>> MapGrid::getGrid()
{
	return grid;
}

GridTile::GridTile()
{
	visited = false;
	pos = Point(0, 0);
	type = EMPTY;
}

GridTile::~GridTile()
{
	GridTile::free();
}

void GridTile::free()
{
}

void GridTile::setPos(Point p)
{
	pos.setX(p.getX());
	pos.setY(p.getY());
}
void GridTile::setType(TileType type)
{
	this->type = type;
}

void GridTile::triggerEvent(TileType eventType)
{
	
	std::cout << "Event of type:" << eventType << "\n";
	if (eventType == ENCOUNTER) {
		encounterGui();
	}
}

TileType GridTile::getType()
{
	return type;
}

Point GridTile::getPos()
{
	return pos;
}

bool GridTile::getVisited()
{
	return visited;
}

void GridTile::setVisited(bool v)
{
	visited = v;
}

void MapGrid::setCurrentX(int v)
{
	currentX = v;
}

void MapGrid::setCurrentY(int v)
{
	currentY = v;
}

int MapGrid::getCurrentX()
{
	return currentX;
}

int MapGrid::getCurrentY()
{
	return currentY;
}

GridTile MapGrid::getCurrentTile()
{
	return grid[currentX][currentY];
}

GridTile* MapGrid::getCurrentTilePtr()
{
	return &grid[currentX][currentY];
}
