#ifndef IMGUI_UTIL_HEADERS
#define IMGUI_UTIL_HEADERS
extern bool encounterGuiPtr;
extern ImGuiIO IO;

void encounterGui();
void imguiFrame();
void imguiRender();
int imguiInit();

#endif 
