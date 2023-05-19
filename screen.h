#ifndef SCREEN_HEADERS
#define SCREEN_HEADERS

class Screen {
public:
	Screen();
	Screen(Screens aType);
	Screen(Screens aType, std::string text);
	~Screen();
	void free();
	void setText(std::string text);
	void renderText(int x, int y);
	void setTex(LTexture* tex);
	Screens getType();
	LTexture* getTexture();
	std::string getText();


private:
	Screens type;
	std::string screenText;
	LTexture* screenTextTexture;

	//todo: add some gui shit here
};


#endif 
