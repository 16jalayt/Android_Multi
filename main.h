#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <stdlib.h>
#include "arg.h"

using namespace std;
using namespace sf;
using namespace tgui;


void loadButton(Button::Ptr buttonname, int sizeX, int sizeY, int posX, int posY, string text, int textSize, int callbackID, bool hide);
void loadPanel(Panel::Ptr panelname, int sizeX, int sizeY, int posX, int posY, int colR, int colG, int colB, bool hide);
void loadLabel(Label::Ptr labelname, int posX, int posY, string text, int textSize, int colR, int colG, int colB, bool hide);
void loadCheckbox(Checkbox::Ptr checkname, int sizeX, int sizeY, int posX, int posY, string text, int textSize, int colR, int colG, int colB, bool hide);
void loadText(sf::Text textname, Font &font, int posX, int posY, string text, int textSize, int colR, int colG, int colB, bool hide);
void loadScrollBar(Scrollbar::Ptr scrollname, Panel::Ptr panelname, int sizeX, int sizeY,int scrollAmount, int lowValue, int maxValue, bool hide);
void fatalError();

#endif // MAIN_H_INCLUDED

