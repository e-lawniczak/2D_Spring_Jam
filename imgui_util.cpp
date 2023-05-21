#include "common.h"
#include "init.h"

bool encounterGuiPtr;

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
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;
	io.ConfigFlags |= ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();
	ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0x00, 0x00, 0x00, 0xff));
	// Setup Platform/Renderer backends
	ImGui_ImplSDL2_InitForSDLRenderer(app.window, app.renderer);
	ImGui_ImplSDLRenderer_Init(app.renderer);

	ImGuiStyle& style = ImGui::GetStyle();

	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.4f, 0.7f, 0.42f, 0.7f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.27f, 0.75, 0.33f, 0.95f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.09f, 0.5f, 0.22f, 0.95f);
	style.WindowRounding = 0.25;
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
