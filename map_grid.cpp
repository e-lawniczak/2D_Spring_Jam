#include "common.h"


MapGrid::MapGrid()
{
	int start_w = 450, start_h = 310;
	currentX = 0;
	currentY = 0;
	Lists lists;

	std::vector<std::vector<GridTile>> vGrid(GRID_WIDTH, std::vector<GridTile>(GRID_HEIGHT, GridTile()));
	for (int i = 0; i < vGrid.size(); i++)
	{
		for (int j = 0; j < vGrid[i].size(); j++)
		{
			vGrid[i][j].setPos(Point(start_w + (i * GRID_MOVE), start_h + (j * GRID_MOVE)));
			if (i == 1) {
				vGrid[i][j].setType(ENCOUNTER);
				vGrid[i][j].getEvent()->addEnemy(lists.enemyList[0]);

			}
			if (i == 2) {
				vGrid[i][j].setType(ITEM);
				vGrid[i][j].getEvent()->setItem(lists.itemList[0]);
			}
			if (i == 3) {
				vGrid[i][j].setType(BOSS);
				vGrid[i][j].getEvent()->addEnemy(lists.enemyList[0]);
				vGrid[i][j].getEvent()->addEnemy(lists.enemyList[0]);
				vGrid[i][j].getEvent()->setBoss(Unit(lists.enemyList[1]));

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
