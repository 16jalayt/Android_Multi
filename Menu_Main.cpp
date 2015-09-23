#include "Menu_Main.h"

bool exitProgram = false;

namespace Main {

   static Button::Ptr m_mainTroubleshoot;
   static Button::Ptr m_mainReference;
   static Button::Ptr m_mainTutorials;
   static Button::Ptr m_mainExit;

void menuInit(Gui& gui)
{
//Main menu
    Button::Ptr mainTroubleshoot(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(mainTroubleshoot, 320, 100, 240, 35, "Troubleshooting", 35, 51, false);

    Button::Ptr mainReference(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(mainReference, 320, 100, 240, 175, "Reference", 35, 52, false);

    Button::Ptr mainTutorials(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(mainTutorials, 320, 100, 240, 320, "Tutorials", 35, 53, false);

    Button::Ptr mainExit(gui);
    //         button name,loading sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(mainExit, 320, 100, 240, 470, "Exit", 35, 54, false);

    m_mainTroubleshoot = mainTroubleshoot;
	m_mainReference = mainReference;
	m_mainTutorials = mainTutorials;
	m_mainExit = mainExit;
}

Button::Ptr getMainTroubleshoot( void )
{
	return m_mainTroubleshoot;
}

Button::Ptr getMainReference( void )
{
	return m_mainReference;
}

Button::Ptr getMainTutorials( void )
{
	return m_mainTutorials;
}

Button::Ptr getMainExit( void )
{
	return m_mainExit;
}


void callbacks(Gui& gui, Callback& callback)
{
            switch (callback.id)
            {
//Main
            case 51://Troubleshoot clicked
                Tro::getTroubleConnect()->show();
                Tro::getTroubleMove()->show();
                Tro::getTroubleBackMain()->show();
                Main::getMainTroubleshoot()->hide();
                Main::getMainReference()->hide();
                Main::getMainTutorials()->hide();
                Main::getMainExit()->hide();
                break;

            case 52://Reference Clicked
                Ref::getRefCode()->show();
                Ref::getRefHardware()->show();
                Ref::getRefPrinting()->show();
                Ref::getRefBack()->show();
                Main::getMainTroubleshoot()->hide();
                Main::getMainReference()->hide();
                Main::getMainTutorials()->hide();
                Main::getMainExit()->hide();
                break;

            case 53://Tutorials Clicked
                Tut::getTutCode()->show();
                Tut::getTutHardware()->show();
                Tut::getTutPrinting()->show();
                Tut::getTutBack()->show();
                Main::getMainTroubleshoot()->hide();
                Main::getMainReference()->hide();
                Main::getMainTutorials()->hide();
                Main::getMainExit()->hide();
                break;

            case 54://Exit Clicked
                exitProgram = true;
                break;


/*







*/
            }


}
}
