#include "common.h"



MapGrid::MapGrid()
{
	int start_w = 400, start_h = 290;
	currentX = 0;
	currentY = 0;

	std::vector<std::vector<GridTile>> vGrid(GRID_WIDTH, std::vector<GridTile>(GRID_HEIGHT, GridTile()));
	for (int i = 0; i < vGrid.size(); i++)
	{
		for (int j = 0; j < vGrid[i].size(); j++)
		{
			vGrid[i][j].setPos(Point(start_w + (i * 40), start_h + (j * 40)));
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

TileType GridTile::getType()
{
	return type;
}

Point GridTile::getPos()
{
	return pos;
}

int MapGrid::setCurrentX(int v)
{
	return 0;
}

int MapGrid::setCurrentY(int v)
{
	return 0;
}

int MapGrid::getCurrentX()
{
	return 0;
}

int MapGrid::getCurrentY()
{
	return 0;
}
