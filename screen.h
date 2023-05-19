#ifndef SCREEN_HEADERS
#define SCREEN_HEADERS

class Screen {
public:
	Screen();
	Screen(Screens aType);
	~Screen();
	void free();
	void setText(std::string text);
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
