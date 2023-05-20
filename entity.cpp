#include "common.h"

Entity::Entity()
{
	pos = Point(0,0);
	entityTex = LTexture();
	name = "";
}
Entity::Entity(int x, int y, std::string path, std::string name)
{
	pos = Point(x,y);
	this->name = name;
	entityTex = LTexture();
	if (!entityTex.loadFromFile(path)) {
		printf("Failed to load entity texture\n");
	}
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

