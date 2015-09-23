#include "Menu_Tutorials.h"

namespace Tut {

   static Button::Ptr m_tutCode;
   static Button::Ptr m_tutHardware;
   static Button::Ptr m_tutPrinting;
   static Button::Ptr m_tutBack;

void menuInit(Gui& gui)
{
    //Tutorial menu
    Button::Ptr tutCode(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(tutCode, 320, 100, 240, 35, "Code", 35, 81, true);

    Button::Ptr tutHardware(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(tutHardware, 320, 100, 240, 175, "Hardware", 35, 82, true);

    Button::Ptr tutPrinting(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(tutPrinting, 320, 100, 240, 320, "3D Printing", 35, 83, true);

    Button::Ptr tutBack(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(tutBack, 320, 100, 240, 470, "Back", 35, 84, true);

    m_tutCode = tutCode;
	m_tutHardware = tutHardware;
	m_tutPrinting = tutPrinting;
	m_tutBack = tutBack;
}

Button::Ptr getTutCode( void )
{
	return m_tutCode;
}

Button::Ptr getTutHardware( void )
{
	return m_tutHardware;
}

Button::Ptr getTutPrinting( void )
{
	return m_tutPrinting;
}

Button::Ptr getTutBack( void )
{
	return m_tutBack;
}

void callbacks(Gui& gui, Callback& callback)
{

            switch (callback.id)
            {
    //Tutorials
            case 81://Code clicked
                Tut::getTutCode()->hide();
                Tut::getTutHardware()->hide();
                Tut::getTutPrinting()->hide();
                Tut::getTutBack()->hide();
                break;

            case 82://Hardware Clicked
                Tut::getTutCode()->hide();
                Tut::getTutHardware()->hide();
                Tut::getTutPrinting()->hide();
                Tut::getTutBack()->hide();
                break;

            case 83://Printing Clicked
                Tut::getTutCode()->hide();
                Tut::getTutHardware()->hide();
                Tut::getTutPrinting()->hide();
                Tut::getTutBack()->hide();

                break;

            case 84://Back Clicked
                Tut::getTutCode()->hide();
                Tut::getTutHardware()->hide();
                Tut::getTutPrinting()->hide();
                Tut::getTutBack()->hide();
                Main::getMainTroubleshoot()->show();
                Main::getMainReference()->show();
                Main::getMainTutorials()->show();
                Main::getMainExit()->show();
                break;
            }


}
}
