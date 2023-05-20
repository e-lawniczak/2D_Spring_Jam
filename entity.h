#ifndef ENTITY_HEADERS
#define ENTITY_HEADERS

class Entity {
public:
	Entity();
	Entity(int x, int y, std::string path, std::string name);
	~Entity();
	void free();
	void setTexture(std::string path);
	void render();
	void move(Point p);
	void setName(std::string name);
	std::string getName();
	Point* getPos();
	LTexture* getTexture();

private:
	std::string name;
	Point pos;
	LTexture entityTex;
};


#endif 
