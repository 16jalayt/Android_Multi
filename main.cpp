#include "main.h"

int tut_var_setup_page = 0;
int tut_var_trouble_page = 0;
int previousScrolbarValue = 0;
bool exitProgram = false;
/* TO DO
loading screen in console and main window
debug (logging?)

*/
/*
Callback reference
    5x Main menu
    6x Trouble menu
    7x Reference menu
    8x Tutorial menu
*/
int main(int argc, char** argv)
{
    cmdparse(argc, argv);
    RenderWindow window(sf::VideoMode(800, 600), "Marion Robotics");
    Gui gui(window);
    gui.setGlobalFont("data/DejaVuSans.ttf");
    Font font;
    font.loadFromFile("data/DejaVuSans.ttf");


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
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(mainExit, 320, 100, 240, 470, "Exit", 35, 54, false);

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

    checkConsoleClose();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            gui.handleEvent(event);
        }

        tgui::Callback callback;
        while (gui.pollCallback(callback))
        {
            switch (callback.id)
            {
//Main
            case 51://Troubleshoot clicked
                troubleConnect->show();
                troubleMove->show();
                troubleBackMain->show();
                mainTroubleshoot->hide();
                mainReference->hide();
                mainTutorials->hide();
                mainExit->hide();
                break;

            case 52://Reference Clicked
                refCode->show();
                refHardware->show();
                refPrinting->show();
                refBack->show();
                mainTroubleshoot->hide();
                mainReference->hide();
                mainTutorials->hide();
                mainExit->hide();
                break;

            case 53://Tutorials Clicked
                tutCode->show();
                tutHardware->show();
                tutPrinting->show();
                tutBack->show();
                mainTroubleshoot->hide();
                mainReference->hide();
                mainTutorials->hide();
                mainExit->hide();
                break;

            case 54://Exit Clicked
                exitProgram = true;
                break;

//Troubleshoot
            case 62://Connect clicked
                troubleConnect->show();
                troubleMove->show();
                troubleBackMain->show();
                break;

            case 63://Move clicked
                troubleConnect->hide();
                troubleMove->hide();
                troubleBackMain->hide();
                break;

            case 64://Back clicked
                troubleConnect->hide();
                troubleMove->hide();
                troubleBackMain->hide();
                mainTroubleshoot->show();
                mainReference->show();
                mainTutorials->show();
                mainExit->show();
                break;
//Reference

            case 71://Code clicked
                refCode->hide();
                refHardware->hide();
                refPrinting->hide();
                refBack->hide();
                break;

            case 72://Hardware Clicked
                refCode->hide();
                refHardware->hide();
                refPrinting->hide();
                refBack->hide();
                break;

            case 73://Printing Clicked
                refCode->hide();
                refHardware->hide();
                refPrinting->hide();
                refBack->hide();
                break;

            case 74://Back Clicked
                refCode->hide();
                refHardware->hide();
                refPrinting->hide();
                refBack->hide();
                mainTroubleshoot->show();
                mainReference->show();
                mainTutorials->show();
                mainExit->show();
                break;

//Tutorials
            case 81://Code clicked
                tutCode->hide();
                tutHardware->hide();
                tutPrinting->hide();
                tutBack->hide();
                break;

            case 82://Hardware Clicked
                tutCode->hide();
                tutHardware->hide();
                tutPrinting->hide();
                tutBack->hide();
                break;

            case 83://Printing Clicked
                tutCode->hide();
                tutHardware->hide();
                tutPrinting->hide();
                tutBack->hide();

                break;

            case 84://Back Clicked
                tutCode->hide();
                tutHardware->hide();
                tutPrinting->hide();
                tutBack->hide();
                mainTroubleshoot->show();
                mainReference->show();
                mainTutorials->show();
                mainExit->show();
                break;

            }
            //check for exit status, because return dosn't work in a switch statement.
            //for an if statement with one line, you dont need parenthesis. :P
            if (exitProgram == true)
                return 0;

        }

        window.clear(sf::Color(0, 250, 0));

        gui.draw();


        window.display();


    }
}

void scrollPanel(tgui::Panel::Ptr panel_trouble_sam, const tgui::Callback& callback)
{
    int distanceToMove = previousScrolbarValue - callback.value;

    // Move all widgets that are inside the panel
    for (auto& widget : panel_trouble_sam->getWidgets())
        widget->setPosition(widget->getPosition().x, widget->getPosition().y + distanceToMove);

    previousScrolbarValue = callback.value;
}

void loadButton(Button::Ptr buttonname, int sizeX, int sizeY, int posX, int posY, string text, int textSize, int callbackID, bool hide)
{

    buttonname->load("data/Black.conf");
    buttonname->setSize(sizeX, sizeY);
    buttonname->setPosition(posX, posY);
    buttonname->setText(text);
    buttonname->bindCallback(Button::LeftMouseClicked);
    buttonname->setCallbackId(callbackID);
    buttonname->setTextSize(textSize);
    if (hide == true)
        buttonname->hide();
}
