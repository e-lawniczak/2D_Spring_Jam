#include "common.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int aX, int aY)
{
	x = aX;
	y = aY;
}

Point::~Point()
{
}

void Point::free()
{
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

void Point::setX(int aX)
{
	x = aX;
}

void Point::setY(int aY)
{
	y = aY;
}
void Point::newPos(Point p) {
	x = p.getX();
	y = p.getY();
}