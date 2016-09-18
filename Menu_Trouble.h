#ifndef MENU_TROUBLE_H_INCLUDED
#define MENU_TROUBLE_H_INCLUDED

#include <TGUI/TGUI.hpp>
#include "ObjectCreateFunc.h"
#include "Menu_Main.h"

using namespace std;
using namespace sf;
using namespace tgui;

namespace Tro
{
    void menuInit( Gui& guiRef );
    void callbacks(Gui& guiRef, Callback& callback);

    Button::Ptr getTroubleConnect( void );
    Button::Ptr getTroubleMove( void );
    Button::Ptr getTroubleBackMain( void );

    Button::Ptr getTroubleConCom( void );
   Button::Ptr getTroubleConBack( void );
   Button::Ptr getTroubleConP2p( void );

   Panel::Ptr getTroubleConComPanel( void );
   Button::Ptr getTroubleConComBack( void );
   Scrollbar::Ptr getTroubleConComScroll( void );

   Panel::Ptr getTroubleConP2pPanel( void );
   Button::Ptr getTroubleConP2pBack( void );
   Scrollbar::Ptr getTroubleConP2pScroll( void );
}
#endif // MENU_MAIN_H_INCLUDED
