#include "common.h"
#include "app.h"
#include "sound.h"

Application::Application()
{
	currentScreen = START_SCREEN;
	screenText = "Press SPACE to start";
	textTexture = LTexture();
	engine = GameEngine();
	endGame = false;
	startPtr = false;

}

Application::~Application()
{
}

void Application::free()
{
}

void Application::handleScreen()
{
	switch (currentScreen)
	{
	case START_SCREEN:
		handleStart();
		break;
	case GAME_SCREEN:
		handleGame();
		break;
	case END_SCREEN:
		handleEnd();
		break;
	default:
		break;
	}
}

Screens Application::getScreen()
{
	return currentScreen;
}

void Application::init()
{
	this->setText(screenText);
}
bool Application::getEndGame()
{
	return endGame;
}
void Application::handleStart()
{
	//textTexture.render((SCREEN_WIDTH - textTexture.getWidth()) / 2, (SCREEN_HEIGHT - textTexture.getHeight()) / 2);
	//if (app.keyboard[SDL_SCANCODE_SPACE] && currentScreen == START_SCREEN) {
	//	playSound(SND_MENU_CLICK, CH_MENU_SOUND);
	//	this->setText("Press q to end");
	//	engine.init();
	//	currentScreen = GAME_SCREEN;
	//}

	ImGui::SetNextWindowPos(ImVec2(SCREEN_WIDTH / 2 - 275, SCREEN_HEIGHT / 2 - 50));
	ImGui::SetNextWindowSize(ImVec2(550, 200));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.0f, 0.0f, 0.0f, 0.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	ImGui::Begin("Start!", &startPtr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
	std::string text = "Welcome to the Chicken Adventure!!!";
	std::string text2 = "Lead the chicken to victory, defeat the evil fox and his pack of snakes once and for all!\n\n\n";
	auto windowWidth = ImGui::GetWindowSize().x;
	auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

	ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
	ImGui::Text(text.c_str());
	ImGui::Text(text2.c_str());
	ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
	if (ImGui::Button("Start playing!")) {
		playSound(SND_MENU_CLICK, CH_MENU_SOUND);
		engine.init();
		currentScreen = GAME_SCREEN;
		startPtr = false;
	}
	ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
	if (ImGui::Button("Quit!?")) {
		playSound(SND_MENU_CLICK, CH_MENU_SOUND);
		startPtr = false;
		endGame = true;
	}
	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
	ImGui::End();


}

void Application::handleGame()
{
	if (engine.getGameFinished() && currentScreen == GAME_SCREEN) {
		setText("Thanks for playing");
		currentScreen = END_SCREEN;
	}

	gBackgroundTexture.render(0, 0);
	//textTexture.render(10, 10);
	engine.gameLoop();
}

void Application::handleEnd()
{
	gEndScreenTexture.render((SCREEN_WIDTH / 2) - gEndScreenTexture.getWidth() / 2, 0);
	textTexture.setColor((Uint8)(255), (Uint8)(255), (Uint8)(255));
	textTexture.render((SCREEN_WIDTH - textTexture.getWidth()) / 2, (SCREEN_HEIGHT - textTexture.getHeight()) / 2);
	if (app.keyboard[SDL_SCANCODE_SPACE] && currentScreen == END_SCREEN) {
		endGame = true;
	}
	ImGui::SetNextWindowPos(ImVec2(SCREEN_WIDTH / 2 - 170 , SCREEN_HEIGHT  - 270));
	ImGui::SetNextWindowSize(ImVec2(550, 200));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.0f, 0.0f, 0.0f, 0.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	ImGui::Begin("End!", &startPtr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
	std::string text = "Welcome to the Chicken Adventure!!!";
	auto windowWidth = ImGui::GetWindowSize().x;
	auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

	ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
	if (ImGui::Button("Quit")) {
		playSound(SND_MENU_CLICK, CH_MENU_SOUND);
		startPtr = false;
		endGame = true;
	}
	ImGui::PopStyleVar();
	ImGui::PopStyleColor();
	ImGui::End();
}

void Application::setText(std::string text)
{
	this->screenText = text;
	SDL_Color textColor = { 0, 0, 0 };
	if (!this->textTexture.loadFromRenderedText(screenText, textColor))
	{
		printf("Failed to render text texture!\n");
	}
}
