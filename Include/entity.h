#pragma once

class Entity {
	public:
		Entity(int x, int y, Game app, std::string path, std::string name);
		~Entity();
		void free();
		void setTexture(Game app, std::string path);
		void render(Game app);
		Point* getPos();
		SDL_Texture* getTexture();

	private:
		std::string name;
		Point pos;
		SDL_Texture * entityTex = nullptr;
};
