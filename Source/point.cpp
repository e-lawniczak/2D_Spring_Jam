#include "common.h"

Point::Point() {}
Point::Point(int new_x, int new_y) {
	this->x = new_x;
	this->y = new_y;
}

void Point::add(Point p) {
	this->x += p.x;
    this->y += p.y;
}
void Point::add(int new_x, int new_y) {
	this->x += new_x;
    this->y += new_y;
}

void Point::sub(Point p) {
    this->x -= p.x;
    this->y -= p.y;
}
void Point::sub(int new_x, int new_y) {
    this->x -= new_x;
    this->y -= new_y;
}

int Point::dotProd(Point p) {
	return (this->x * p.x) + (this->y * p.y);
}
int Point::dotProd(int new_x, int new_y) {
	return (this->x * new_x) + (this->y * new_y);
}

float Point::distance() {
	return sqrt((this->x * this->x) + (this->y * this->y));
}