#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
//#include <windows.h>
#include <iostream>
#include "arg.h"
//#include "objects.h"

using namespace std;
using namespace sf;
using namespace tgui;


void loadButton(Button::Ptr buttonname, int sizeX, int sizeY, int posX, int posY, string text, int textSize, int callbackID, bool hide);


/*
void scrollPanel(tgui::Panel::Ptr panel_trouble_sam, const tgui::Callback& callback);
class main
{
  public:
        sf::RenderWindow window;
        Gui gui();
};*/
#endif // MAIN_H_INCLUDED

