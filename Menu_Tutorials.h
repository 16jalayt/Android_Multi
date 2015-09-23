#ifndef MENU_TUTORIALS_H_INCLUDED
#define MENU_TUTORIALS_H_INCLUDED

#include <TGUI/TGUI.hpp>
#include "ObjectCreateFunc.h"
#include "Menu_Main.h"

using namespace std;
using namespace sf;
using namespace tgui;

namespace Tut
{
    void menuInit( Gui& guiRef );
    void callbacks(Gui& guiRef, Callback& callback);

    Button::Ptr getTutCode( void );
    Button::Ptr getTutHardware( void );
    Button::Ptr getTutPrinting( void );
    Button::Ptr getTutBack( void );
}
#endif // MENU_MAIN_H_INCLUDED
