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
	ENCOUNTER_SCREEN,
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

enum ItemType {
	HEAD,
	BODY,
	ARMS,
	LEGS,
	WEAPON,
	OTHER
};

enum
{
	CH_ANY = -1,
	CH_PLAYER,
	CH_MENU_SOUND,
	CH_MUSIC,
	CH_AMBIENT,
	CH_BATTLE
};

enum
{
	
	SND_MAIN_THEME,
	SND_AMBIENT,
	SND_MENU_CLICK,
	SND_CONFIRM,
	SND_BATTLE,
	SND_HIT,
	SND_MAX
};



#endif 
