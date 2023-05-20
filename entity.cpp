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
GridTile Entity::handleOverlandMovement(MapGrid* grid)
{
	int moveX = grid->getCurrentX();
	int moveY = grid->getCurrentY();
	if (app.keyboard[SDL_SCANCODE_RIGHT] && !this->moved) {
		moveX++;
		if (moveX < GRID_WIDTH) {
			std::vector<std::vector<GridTile>> g = grid->getGrid();
			GridTile t = g[moveX][moveY];
			pos.newPos(t.getPos());
			this->moved = true;
		
		}
		std::cout << grid->getCurrentX() << "\n";
		std::cout << grid->getCurrentY() << "\n";

	}
	if (app.keyboard[SDL_SCANCODE_LEFT] && !this->moved) {
		moveX --;
		if (moveX >= 0) {
			std::vector<std::vector<GridTile>> g = grid->getGrid();
			GridTile t = g[moveX][moveY];
			pos.newPos(t.getPos());
			this->moved = true;
		
		}
	}
	if (app.keyboard[SDL_SCANCODE_UP] && !this->moved) {
		moveY--;

		if (moveY >= 0) {
			std::vector<std::vector<GridTile>> g = grid->getGrid();
			GridTile t = g[moveX][moveY];
			pos.newPos(t.getPos());
			this->moved = true;
		}
	}
	if (app.keyboard[SDL_SCANCODE_DOWN] && !this->moved) {
		moveY++;

		if (moveY < GRID_HEIGHT) {
			std::vector<std::vector<GridTile>> g = grid->getGrid();
			GridTile t = g[moveX][moveY];
			pos.newPos(t.getPos());
			this->moved = true;
		}
	}
	if (moved) {
		grid->setCurrentX(moveX);
		grid->setCurrentY(moveY);
	}
	return grid->getCurrentTile();
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

