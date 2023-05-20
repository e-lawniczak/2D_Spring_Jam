#include "common.h"

Entity::Entity(int x, int y, App app, std::string path, std::string name) {
	this->pos = Point(x, y);
	this->name = name;
	this->setTexture(app, path);
	// Pass in the surface here
	if (this->entityTex == NULL) {
		printf("Unable to create texture");
	}
}

void Entity::setTexture(App app, std::string path) {
	static SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	this->entityTex = SDL_CreateTextureFromSurface(app.renderer, loadedSurface);

	if (this->entityTex == NULL) {
		printf("Failed to load entity texture\n");
	}

	SDL_FreeSurface(loadedSurface);
}

void Entity::render(App app) {
	//TODO: Here
}

Point * Entity::getPos() {
	return &pos;
}

SDL_Texture * Entity::getTexture() {
	return entityTex;
}
