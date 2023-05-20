#include "screen.h"
#ifndef STAGE_HEADERS
#define STAGE_HEADERS



class Stage {
public:
	Stage();
	Stage(Screen initScreen);
	~Stage();
	void changeScreen(Screen screen);
	void free();
	void logic();
	void draw();
	void initStage();
	Screen getScreen();


private:
	Screen currentScreen;
	//Entity player;

};


#endif 
