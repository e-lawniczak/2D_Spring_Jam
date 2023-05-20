#include "common.h"

#ifndef APP_HEADERS
#define APP_HEADERS

class Application {
public:
	Application();
	~Application();
	void free();
	void handleScreen();
	Screens getScreen();
	void init();
private:

	void handleStart();
	void handleGame();
	void handleEnd();
	void setText(std::string text);

	Screens currentScreen;
	LTexture textTexture;
	std::string screenText;
};

#endif 
