#ifndef ENTITY_HEADERS
#define ENTITY_HEADERS

class Entity {
	public:
		Entity(int x, int y, App app, std::string path, std::string name);
		~Entity();
		void free();
		void setTexture(App app, std::string path);
		void render(App app);
		Point* getPos();
		SDL_Texture* getTexture();

	private:
		std::string name;
		Point pos;
		SDL_Texture * entityTex = nullptr;
};


#endif
