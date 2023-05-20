#include "common.h"
#include "init.h"

bool encounterGuiPtr;
static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

ImGuiIO IO;
int imguiInit() {
	// Create window with SDL_Renderer graphics context
	if (app.renderer == nullptr)
	{
		SDL_Log("Error creating SDL_Renderer!");
		return 0;
	}
	//SDL_RendererInfo info;
	//SDL_GetRendererInfo(renderer, &info);
	//SDL_Log("Current SDL_Renderer: %s", info.name);

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	IO = io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();

	// Setup Platform/Renderer backends
	ImGui_ImplSDL2_InitForSDLRenderer(app.window, app.renderer);
	ImGui_ImplSDLRenderer_Init(app.renderer);
}
void imguiFrame() {
	// Start the Dear ImGui frame
	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
}
void imguiRender() {
	
	
	//SDL_RenderPresent(app.renderer);
}
void encounterGui() {
	
	ImGui::Begin("Another Window", &encounterGuiPtr);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
	ImGui::Text("Hello from another window!");
	if (ImGui::Button("Close Me"))
		encounterGuiPtr = false;
	ImGui::End();

	
}