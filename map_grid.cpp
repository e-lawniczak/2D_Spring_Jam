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
				vGrid[i][j].getEvent()->addEnemy(Unit(0,0,"img/enemy1.png", "Sly fox"));

			}
			if (i == 2) {
				vGrid[i][j].setType(ITEM);
				vGrid[i][j].getEvent()->setItem(Item(5,0,5,20,BODY));
			}
			if (i == 3) {
				vGrid[i][j].setType(BOSS);
				vGrid[i][j].getEvent()->addEnemy(Unit(0, 0, "img/enemy1.png", "Sly fox"));
				vGrid[i][j].getEvent()->addEnemy(Unit(0, 0, "img/enemy1.png", "Sly fox"));
				vGrid[i][j].getEvent()->setBoss(Unit(0, 0, "img/enemy2.png", "Blue Snowman"));

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
