#include "common.h"
MapEvent::MapEvent()
{
	eventFired = false;
}

MapEvent::~MapEvent()
{
	free();
}

void MapEvent::free()
{
}

void MapEvent::encounterEvent()
{
	ImGui::Begin("Another Window", &encounterGuiPtr);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
	ImGui::Text("Hello from another window!");
	if (ImGui::Button("Close Me")) {
		eventFired = true;
		encounterGuiPtr = false;
	}
	ImGui::End();
}

void MapEvent::bossEvent()
{
}

void MapEvent::curioEvent()
{
}

void MapEvent::itemEvent()
{
}

void MapEvent::setEventFired(bool v)
{
	eventFired = v;
}

bool MapEvent::getEventFired()
{
	return eventFired;
}
