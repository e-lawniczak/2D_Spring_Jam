CC = g++
CFLAGS := -std=c++20 -Wall -Wformat -m64 -O2 -fdiagnostics-color=always

IMGUI_DIR = C:\Users\Administrator\OneDrive\Desktop\CppLibs\ImGui-Master
INCLUDES = -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends -IInclude -IC:\C++\Libs\SDL2-3\include/SDL2 -Dmain=SDL_main

SOURCES := $(wildcard Source/*.*)
SOURCES += $(wildcard Source/ImGui/*.*)

TARGET = main.cpp

EXE = example_sdl2_sdlrenderer
OBJS = $(addprefix Out/, $(addsuffix .o, $(notdir $(basename $(SOURCES)))))
LINKS = -LC:\C++\Libs\SDL2-3\lib
LIBS = -lgdi32 -lopengl32 -limm32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -mwindows -lmingw32

# CFLAGS += $(INCLUDES) $(LINKS) $(LIBS)

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

$(OBJS) : $(SOURCES)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(EXE) $(OBJS)
