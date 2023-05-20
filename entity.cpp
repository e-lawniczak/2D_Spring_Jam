#include "common.h"
Entity::Entity()
{
	pos = Point(0, 0);
	entityTex = LTexture();
	name = "";
	next = NULL;
	moved = false;
}
Entity::Entity(int x, int y, std::string path, std::string name)
{
	pos = Point(x, y);
	this->name = name;
	entityTex = LTexture();
	if (!entityTex.loadFromFile(path)) {
		printf("Failed to load entity texture\n");
	}
	next = NULL;
	moved = false;
}

Entity::~Entity()
{
	free();
}

void Entity::free()
{
}

void Entity::setTexture(std::string path) {
	if (!entityTex.loadFromFile(path)) {
		printf("Failed to load entity texture\n");
	}
}

void Entity::render()
{
	entityTex.render(pos);
}
void Entity::move(Point p) {
	pos.setX(p.getX());
	pos.setY(p.getY());
}

void Entity::setName(std::string name) {
	this->name = name;
}

void Entity::setMoved(bool v) {
	moved = v;

}
bool Entity::getMoved() {
	return moved;
}


std::string Entity::getName() {
	return name;
}

Point* Entity::getPos()
{
	return &pos;
}

LTexture* Entity::getTexture()
{
	return &entityTex;
}

