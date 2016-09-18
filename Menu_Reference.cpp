#include "Menu_Reference.h"


namespace Ref {

   static Button::Ptr m_refCode;
   static Button::Ptr m_refHardware;
   static Button::Ptr m_refPrinting;
   static Button::Ptr m_refBack;

   static Panel::Ptr m_refCodePanel;
   static Button::Ptr m_refCodeBack;
   static Scrollbar::Ptr m_refCodeScroll;
   static Label::Ptr m_refCodeText;

   static Panel::Ptr m_refHardPanel;
   static Button::Ptr m_refHardBack;
   static Scrollbar::Ptr m_refHardScroll;
   static Label::Ptr m_refHardText;

void menuInit(Gui& gui)
{
    //Reference menu
    Button::Ptr refCode(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(refCode, 320, 100, 240, 35, "Code", 35, 71, true);

    Button::Ptr refHardware(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(refHardware, 320, 100, 240, 175, "Hardware", 35, 72, true);

    Button::Ptr refPrinting(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(refPrinting, 320, 100, 240, 320, "3D Printing", 35, 73, true);

    Button::Ptr refBack(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(refBack, 320, 100, 240, 470, "Back", 35, 74, true);

    m_refCode = refCode;
	m_refHardware = refHardware;
	m_refPrinting = refPrinting;
	m_refBack = refBack;

//Code reference
    Panel::Ptr refCodePanel(gui);
    loadPanel(refCodePanel, 750, 500, 0, 0, 200, 200, 200, true);

    Button::Ptr refCodeBack(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(refCodeBack, 200, 50, 300, 520, "Back", 25, 321, true);

    Label::Ptr refCodeText(*refCodePanel);
    loadLabel(refCodeText, 15, 30, 20, 1, 1, 1, true, "this is a long test that has\n completely arbitrary text\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol");

    tgui::Scrollbar::Ptr refCodeScroll(gui);
    refCodeScroll->load("data/Black.conf");
    refCodeScroll->setSize(30, 500);
    refCodeScroll->setPosition(refCodePanel->getPosition() + sf::Vector2f(refCodePanel->getSize().x, 0));
    refCodeScroll->setArrowScrollAmount(30);
    refCodeScroll->setLowValue(100); // Viewable area (height of the panel)
    refCodeScroll->setMaximum(500); // Total area (height of the 5 images)
    refCodeScroll->bindCallbackEx(std::bind(scrollPanel, refCodePanel, std::placeholders::_1), tgui::Scrollbar::ValueChanged);
    refCodeScroll->hide();

    m_refCodePanel = refCodePanel;
	m_refCodeBack = refCodeBack;
	m_refCodeScroll = refCodeScroll;
	m_refCodeText = refCodeText;

//Hardware reference
    Panel::Ptr refHardPanel(gui);
    loadPanel(refHardPanel, 750, 500, 0, 0, 200, 200, 200, true);

    Button::Ptr refHardBack(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(refHardBack, 200, 50, 300, 520, "Back", 25, 331, true);

    Label::Ptr refHardText(*refHardPanel);
    loadLabel(refHardText, 15, 30, 20, 1, 1, 1, true, "this is not a long test that has\n completely arbitrary text\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol\nlol");

    tgui::Scrollbar::Ptr refHardScroll(gui);
    refHardScroll->load("data/Black.conf");
    refHardScroll->setSize(30, 500);
    refHardScroll->setPosition(refHardPanel->getPosition() + sf::Vector2f(refHardPanel->getSize().x, 0));
    refHardScroll->setArrowScrollAmount(30);
    refHardScroll->setLowValue(100); // Viewable area (height of the panel)
    refHardScroll->setMaximum(500); // Total area (height of the 5 images)
    refHardScroll->bindCallbackEx(std::bind(scrollPanel, refHardPanel, std::placeholders::_1), tgui::Scrollbar::ValueChanged);
    refHardScroll->hide();

    m_refHardPanel = refHardPanel;
	m_refHardBack = refHardBack;
	m_refHardScroll = refHardScroll;
	m_refHardText = refHardText;
}

Button::Ptr getRefCode( void )
{
	return m_refCode;
}

Button::Ptr getRefHardware( void )
{
	return m_refHardware;
}

Button::Ptr getRefPrinting( void )
{
	return m_refPrinting;
}

Button::Ptr getRefBack( void )
{
	return m_refBack;
}

//code
Panel::Ptr getRefCodePanel( void )
{
	return m_refCodePanel;
}

Button::Ptr getRefCodeBack( void )
{
	return m_refCodeBack;
}

Scrollbar::Ptr getRefCodeScroll( void )
{
	return m_refCodeScroll;
}

Label::Ptr getRefCodeText( void )
{
	return m_refCodeText;
}

//Hard
Panel::Ptr getRefHardPanel( void )
{
	return m_refHardPanel;
}

Button::Ptr getRefHardBack( void )
{
	return m_refHardBack;
}

Scrollbar::Ptr getRefHardScroll( void )
{
	return m_refHardScroll;
}

Label::Ptr getRefHardText( void )
{
	return m_refHardText;
}


void callbacks(Gui& gui, Callback& callback)
{

            switch (callback.id)
            {
            //Reference

            case 71://Code clicked
                Ref::getRefCodePanel()->show();
                Ref::getRefCodeScroll()->show();
                Ref::getRefCodeBack()->show();
                Ref::getRefCodeText()->show();
                Ref::getRefCode()->hide();
                Ref::getRefHardware()->hide();
                Ref::getRefPrinting()->hide();
                Ref::getRefBack()->hide();
                break;

            case 72://Hardware Clicked
                Ref::getRefHardPanel()->show();
                Ref::getRefHardScroll()->show();
                Ref::getRefHardBack()->show();
                Ref::getRefHardText()->show();
                Ref::getRefCode()->hide();
                Ref::getRefHardware()->hide();
                Ref::getRefPrinting()->hide();
                Ref::getRefBack()->hide();
                break;

            case 73://Printing Clicked
                Ref::getRefCode()->hide();
                Ref::getRefHardware()->hide();
                Ref::getRefPrinting()->hide();
                Ref::getRefBack()->hide();
                break;

            case 74://Back Clicked
                Ref::getRefCode()->hide();
                Ref::getRefHardware()->hide();
                Ref::getRefPrinting()->hide();
                Ref::getRefBack()->hide();
                Main::getMainTroubleshoot()->show();
                Main::getMainReference()->show();
                Main::getMainTutorials()->show();
                Main::getMainExit()->show();
                break;
    //Ref sub
            case 321://Back Clicked
                Ref::getRefCodePanel()->hide();
                Ref::getRefCodeScroll()->hide();
                Ref::getRefCodeBack()->hide();
                //Ref::getRefCodeText()->hide();
                Ref::getRefCode()->show();
                Ref::getRefHardware()->show();
                Ref::getRefPrinting()->show();
                Ref::getRefBack()->show();
                break;

    //Ref sub
            case 331://Back Clicked
                Ref::getRefHardPanel()->hide();
                Ref::getRefHardScroll()->hide();
                Ref::getRefHardBack()->hide();
                Ref::getRefHardText()->hide();
                Ref::getRefCode()->show();
                Ref::getRefHardware()->show();
                Ref::getRefPrinting()->show();
                Ref::getRefBack()->show();
                break;
            }


}
}
