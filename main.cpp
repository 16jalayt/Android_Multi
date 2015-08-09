#include "main.h"

int tut_var_setup_page = 0;
int tut_var_trouble_page = 0;
int previousScrolbarValue = 0;
bool hideconsole = true;
bool exitProgram = false;
/* TO DO
loading screen in console and main window
debug

*/
/*
Callback reference
    5x Main menu
    6x Trouble menu
    7x Reference menu
*/
int main(int argc, char** argv)
{
    cmdparse(argc, argv, hideconsole);
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
            case 51:
                troubleConnect->show();
                troubleMove->show();
                troubleBackMain->show();
                mainTroubleshoot->hide();
                mainReference->hide();
                mainTutorials->hide();
                mainExit->hide();
                break;

            case 52:
                mainTroubleshoot->hide();
                mainReference->hide();
                mainTutorials->hide();
                mainExit->hide();
                break;

            case 53:
                mainTroubleshoot->hide();
                mainReference->hide();
                mainTutorials->hide();
                mainExit->hide();
                break;

            case 54:
                exitProgram = true;
                break;

            case 62:
                //tut_button_menu_samtutorial->show();
                //tut_button_menu_back->show();
                mainTroubleshoot->hide();
                mainReference->hide();
                mainTutorials->hide();
                mainExit->hide();
                break;

            case 63:
                mainTroubleshoot->hide();
                mainReference->hide();
                mainTutorials->hide();
                mainExit->hide();
                break;

            case 64:
                troubleConnect->hide();
                troubleMove->hide();
                troubleBackMain->hide();
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
}
