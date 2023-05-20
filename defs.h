#ifndef DEFS_HEADERS
#define DEFS_HEADERS

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

#define PLAYER_START_H 310
#define PLAYER_START_W 450

#define MAX_KEYBOARD_KEYS	350
#define FPS 60




enum Screens {
	START_SCREEN,
	GAME_SCREEN,
	END_SCREEN
};

enum MOUSE_BUTTONS {
	LMB,
	RMB
};

enum TileType {
	ITEM,
	ENCOUNTER,
	CURIO,
	BOSS,
	EMPTY
};



#endif 
