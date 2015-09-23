#ifndef MENU_MAIN_H_INCLUDED
#define MENU_MAIN_H_INCLUDED

#include <TGUI/TGUI.hpp>
#include "ObjectCreateFunc.h"
#include "Menu_Trouble.h"
#include "Menu_Reference.h"
#include "Menu_Tutorials.h"

using namespace std;
using namespace sf;
using namespace tgui;

extern bool exitProgram;

namespace Main
{
    void menuInit( Gui& guiRef );
    void callbacks(Gui& guiRef, Callback& callback);

    Button::Ptr getMainTroubleshoot( void );
    Button::Ptr getMainReference( void );
    Button::Ptr getMainTutorials( void );
    Button::Ptr getMainExit( void );
}
#endif // MENU_MAIN_H_INCLUDED
