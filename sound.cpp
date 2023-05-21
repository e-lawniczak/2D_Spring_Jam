#include "common.h"
#include "sound.h"

static Mix_Chunk* sounds[SND_MAX];
static Mix_Music* music;

void initSounds(void)
{
	memset(sounds, 0, sizeof(Mix_Chunk*) * SND_MAX);

	music = NULL;


	loadSounds();
	loadMusic("sound/overworld.mp3");
}

static void loadSounds(void)
{
	sounds[SND_AMBIENT] = Mix_LoadWAV("sound/forest_amb.mp3");
	sounds[SND_CONFIRM] = Mix_LoadWAV("sound/confirmation.mp3");
	sounds[SND_MAIN_THEME] = Mix_LoadWAV("sound/overworld.mp3");
	sounds[SND_MENU_CLICK] = Mix_LoadWAV("sound/selection.mp3");
	sounds[SND_BATTLE] = Mix_LoadWAV("sound/battle_theme.mp3");
	sounds[SND_HIT] = Mix_LoadWAV("sound/hit_sound.mp3");
	sounds[SND_DOGE] = Mix_LoadWAV("sound/doge_sound.mp3");
}

void loadMusic(std::string filename)
{
	if (music != NULL)
	{
		Mix_HaltMusic();
		Mix_FreeMusic(music);
		music = NULL;
	}

	music = Mix_LoadMUS(filename.c_str());
}
void playMusic(int loop)
{
	Mix_PlayMusic(music, (loop) ? -1 : 0);
}
void playChannel(int id, int channel, int loop) {
	Mix_PlayChannel(channel, sounds[id], (loop) ? -1 : 0);
}
void stopChannel(int channel) {
	Mix_HaltChannel(channel);
}
void playSound(int id, int channel)
{
	Mix_PlayChannel(channel, sounds[id], 0);
}