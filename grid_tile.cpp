#include "common.h"

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
		mEvent.encounterEvent();
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

MapEvent* GridTile::getEvent()
{
	return &mEvent;
}


