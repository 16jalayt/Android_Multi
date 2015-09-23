#include "Menu_Trouble.h"

namespace Tro {

   static Button::Ptr m_troubleConnect;
   static Button::Ptr m_troubleMove;
   static Button::Ptr m_troubleBackMain;

   static Button::Ptr m_troubleConCom;
   static Button::Ptr m_troubleConP2p;
   static Button::Ptr m_troubleConBack;

   static Panel::Ptr m_troubleConComPanel;
   static Button::Ptr m_troubleConComBack;
   static Scrollbar::Ptr m_troubleConComScroll;

   static Panel::Ptr m_troubleConP2pPanel;
   static Button::Ptr m_troubleConP2pBack;
   static Scrollbar::Ptr m_troubleConP2pScroll;

void menuInit(Gui& gui)
{
//Troubleshoot menu
    Button::Ptr troubleConnect(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(troubleConnect, 320, 100, 240, 175, "Connection", 35, 62, true);

    Button::Ptr troubleMove(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(troubleMove, 320, 100, 240, 320, "Won't move", 35, 63, true);

    Button::Ptr troubleBackMain(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(troubleBackMain, 320, 100, 240, 470, "Back", 35, 64, true);

    m_troubleConnect = troubleConnect;
	m_troubleMove = troubleMove;
	m_troubleBackMain = troubleBackMain;

//Troubleshoot connect menu
    Button::Ptr troubleConCom(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(troubleConCom, 320, 100, 240, 175, "To Computer", 35, 202, true);

    Button::Ptr troubleConP2p(gui);
            //button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(troubleConP2p, 320, 100, 240, 320, "Between Phones", 35, 203, true);

    Button::Ptr troubleConBack(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(troubleConBack, 320, 100, 240, 470, "Back", 35, 201, true);

    m_troubleConCom = troubleConCom;
	m_troubleConBack = troubleConBack;
	m_troubleConP2p = troubleConP2p;

//Troubleshoot Computer Connect List
    Panel::Ptr troubleConComPanel(gui);
    loadPanel(troubleConComPanel, 750, 500, 0, 0, 200, 200, 200, true);

    Scrollbar::Ptr troubleConComScroll(gui);
    //                Bar name name,     Panel name      sizex,sizey,amount,low ,High,start hidden
    loadScrollBar(troubleConComScroll, troubleConComPanel, 50, 500,     30, 500, 500, true);

    Button::Ptr troubleConComBack(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(troubleConComBack, 200, 50, 300, 520, "Back", 25, 221, true);

    tgui::Label::Ptr conComLabel1(*troubleConComPanel);
    conComLabel1->load("data/Black.conf");
    conComLabel1->setText("There is a power problem. Try a fresh battery and checking wires");
    conComLabel1->setTextSize(20);
    conComLabel1->setTextColor(Color::Red);
    conComLabel1->setPosition(Vector2f(20, 15));

	tgui::Checkbox::Ptr conComLabel2(*troubleConComPanel);
    conComLabel2->load("data/Black.conf");
    conComLabel2->setPosition(20, 50);
    conComLabel2->setText("  Is a good battery in, the brick and the\n  main switch is turned on.");
    conComLabel2->setSize(32, 32);
    conComLabel2->setTextColor(sf::Color::Black);


	m_troubleConComPanel = troubleConComPanel;
	m_troubleConComBack = troubleConComBack;
	m_troubleConComScroll = troubleConComScroll;

//Troubleshoot Phone Connect List
Panel::Ptr troubleConP2pPanel(gui);
    loadPanel(troubleConP2pPanel, 750, 500, 0, 0, 200, 200, 200, true);

    Scrollbar::Ptr troubleConP2pScroll(gui);
    //                Bar name name,     Panel name      sizex,sizey,amount,low ,High,start hidden
    loadScrollBar(troubleConP2pScroll, troubleConComPanel, 50, 500,     30, 500, 500, true);

    Button::Ptr troubleConP2pBack(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(troubleConP2pBack, 200, 50, 300, 520, "Back", 25, 231, true);

    tgui::Label::Ptr conP2pLabel1(*troubleConP2pPanel);
    conComLabel1->load("data/Black.conf");
    conComLabel1->setText("There is a power problem. Try a fresh battery and checking wires");
    conComLabel1->setTextSize(20);
    conComLabel1->setTextColor(Color::Red);
    conComLabel1->setPosition(Vector2f(20, 15));

	tgui::Checkbox::Ptr conP2pLabel2(*troubleConP2pPanel);
    conComLabel2->load("data/Black.conf");
    conComLabel2->setPosition(20, 50);
    conComLabel2->setText("  Is a good battery in, the brick and the\n  main switch is turned on.");
    conComLabel2->setSize(32, 32);
    conComLabel2->setTextColor(sf::Color::Black);


	m_troubleConP2pPanel = troubleConP2pPanel;
	m_troubleConP2pBack = troubleConP2pBack;
	m_troubleConP2pScroll = troubleConP2pScroll;
}

Button::Ptr getTroubleConnect( void )
{
	return m_troubleConnect;
}

Button::Ptr getTroubleMove( void )
{
	return m_troubleMove;
}

Button::Ptr getTroubleBackMain( void )
{
	return m_troubleBackMain;
}


Button::Ptr getTroubleConCom( void )
{
	return m_troubleConCom;
}

Button::Ptr getTroubleConBack( void )
{
	return m_troubleConBack;
}

Button::Ptr getTroubleConP2p( void )
{
	return m_troubleConP2p;
}


Panel::Ptr getTroubleConComPanel( void )
{
	return m_troubleConComPanel;
}

Button::Ptr getTroubleConComBack( void )
{
	return m_troubleConComBack;
}

Scrollbar::Ptr getTroubleConComScroll( void )
{
	return m_troubleConComScroll;
}

void callbacks(Gui& gui, Callback& callback)
{
            switch (callback.id)
            {
            //Troubleshoot
            case 62://Connect clicked
                Tro::getTroubleConBack()->show();
                Tro::getTroubleConCom()->show();
                Tro::getTroubleConP2p()->show();
                Tro::getTroubleConnect()->hide();
                Tro::getTroubleMove()->hide();
                Tro::getTroubleBackMain()->hide();
                break;

            case 63://Move clicked
                Tro::getTroubleConnect()->hide();
                Tro::getTroubleMove()->hide();
                Tro::getTroubleBackMain()->hide();
                break;

            case 64://Back clicked
                Tro::getTroubleConnect()->hide();
                Tro::getTroubleMove()->hide();
                Tro::getTroubleBackMain()->hide();
                Main::getMainTroubleshoot()->show();
                Main::getMainReference()->show();
                Main::getMainTutorials()->show();
                Main::getMainExit()->show();
                break;

    //Troubleshoot connect menu
            case 201://Back clicked
                Tro::getTroubleConBack()->hide();
                Tro::getTroubleConCom()->hide();
                Tro::getTroubleConP2p()->hide();
                Tro::getTroubleConnect()->show();
                Tro::getTroubleMove()->show();
                Tro::getTroubleBackMain()->show();

                break;

            case 202://Computer clicked
                Tro::getTroubleConComPanel()->show();
                Tro::getTroubleConComScroll()->show();
                Tro::getTroubleConComBack()->show();
                Tro::getTroubleConnect()->hide();
                Tro::getTroubleMove()->hide();
                Tro::getTroubleConBack()->hide();
                break;

            case 203://p2p clicked
                Tro::getTroubleConComPanel()->show();
                Tro::getTroubleConComScroll()->show();
                Tro::getTroubleConComBack()->show();
                Tro::getTroubleConnect()->hide();
                Tro::getTroubleMove()->hide();
                Tro::getTroubleConBack()->hide();
                Tro::getTroubleConP2p()->hide();
                break;

//troubleshoot connect computer panel
            case 221://back clicked
                Tro::getTroubleConComPanel()->hide();
                Tro::getTroubleConComScroll()->hide();
                Tro::getTroubleConComBack()->hide();
                Tro::getTroubleConBack()->show();
                Tro::getTroubleConCom()->show();

    //troubleshoot connect p2p panel
            case 231://back clicked
                //Tro::getTroubleConP2pPanel()->hide();
                //Tro::getTroubleConP2pScroll()->hide();
                //Tro::getTroubleConP2pBack()->hide();
                Tro::getTroubleConBack()->show();
                Tro::getTroubleConP2p()->show();

            }


}
}
