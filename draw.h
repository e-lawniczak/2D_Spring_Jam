#ifndef DRAW_HEADERS
#define DRAW_HEADERS

void prepareScene(Screens screen);
void presentScene(void);

/**
 * @brief This is the drawing function for the ImGui overlay, so for like GUI components
 * 
 * @param screen What screen it is (Start, game, end...)
 */
void renderImGuiOverlay(Screens screen);

#endif 
