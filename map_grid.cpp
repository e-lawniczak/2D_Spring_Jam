#include "common.h"



MapGrid::MapGrid()
{
	int start_w = 400, start_h = 290;
	grid = new GridTile * [GRID_HEIGHT];

	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		grid[i] = new GridTile[GRID_WIDTH];
		for (int j = 0; j < GRID_WIDTH; j++)
		{
			grid[i][j] = GridTile();
			grid[i][j].setPos(Point(start_w + (j * 40), start_h + (i * 40)));
		}
	}
}

MapGrid::~MapGrid()
{
	MapGrid::free();
}

void MapGrid::free()
{
}

GridTile** MapGrid::getGrid()
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
