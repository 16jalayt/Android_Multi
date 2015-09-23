#ifndef MENU_REFERENCE_H_INCLUDED
#define MENU_REFERENCE_H_INCLUDED

#include <TGUI/TGUI.hpp>
#include "ObjectCreateFunc.h"
#include "Menu_Main.h"

using namespace std;
using namespace sf;
using namespace tgui;

namespace Ref
{
    void menuInit( Gui& guiRef );
    void callbacks(Gui& guiRef, Callback& callback);

    Button::Ptr getRefCode( void );
    Button::Ptr getRefHardware( void );
    Button::Ptr getRefPrinting( void );
    Button::Ptr getRefBack( void );

    Panel::Ptr getRefCodePanel( void );
    Button::Ptr getRefCodeBack( void );
    Scrollbar::Ptr getRefCodeScroll( void );
    Label::Ptr getRefCodeText( void );
}
#endif // MENU_MAIN_H_INCLUDED
