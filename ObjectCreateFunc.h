#ifndef OBJECTCREATEFUNC_H_INCLUDED
#define OBJECTCREATEFUNC_H_INCLUDED

#include <TGUI/TGUI.hpp>

using namespace std;
using namespace sf;
using namespace tgui;

extern bool confError;
extern int previousScrolbarValue;
void scrollPanel(tgui::Panel::Ptr panelname, const tgui::Callback& callback);

void loadButton(Button::Ptr buttonname, int sizeX, int sizeY, int posX, int posY, string text, int textSize, int callbackID, bool hide);
void loadPanel(Panel::Ptr panelname, int sizeX, int sizeY, int posX, int posY, int colR, int colG, int colB, bool hide);
void loadLabel(Label::Ptr labelname, int posX, int posY, int textSize, int colR, int colG, int colB, bool hide, string text);
void loadCheckbox(Checkbox::Ptr checkname, int sizeX, int sizeY, int posX, int posY, string text, int textSize, int colR, int colG, int colB, bool hide);
void loadText(sf::Text textname, Font &font, int posX, int posY, string text, int textSize, int colR, int colG, int colB, bool hide);
void loadScrollBar(Scrollbar::Ptr scrollname, Panel::Ptr panelname, int sizeX, int sizeY,int scrollAmount, int lowValue, int maxValue, bool hide);


#endif // OBJECTCREATEFUNC_H_INCLUDED
