#include <SFML/Graphics.hpp>
#include <iostream>
#include "arg.h"
#include "Menu_Main.h"

/* TO DO
loading screen in console and main window
debug (logging?)
Screen Lables?
figure out the loading thread
*/
/*
Callback reference
    5x Main menu
    6x Trouble menu
    7x Reference menu
    8x Tutorial menu
    2xx Trouble sub menus
    3xx Reference sub menus
    4xx Tutorials sub menus
*/
int main(int argc, char** argv)
{
    cmdparse(argc, argv);
    RenderWindow window(sf::VideoMode(800, 600), "Marion Robotics");
    Gui gui(window);
    gui.setGlobalFont("data/DejaVuSans.ttf");
    Font font;
    font.loadFromFile("data/DejaVuSans.ttf");

    Main::menuInit(gui);
    Ref::menuInit(gui);
    Tro::menuInit(gui);
    Tut::menuInit(gui);

    isLoading = false;

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
            Main::callbacks(gui, callback);
            Ref::callbacks(gui, callback);
            Tro::callbacks(gui, callback);
            Tut::callbacks(gui, callback);
        }
            //check for exit status, because return dosn't work in a switch statement.
            //for an if statement with one line, you dont need parenthesis. :P
            if (exitProgram == true)
                return 0;
            if (isLoading == false)
                checkConsoleClose();


        window.clear(sf::Color(0, 250, 0));

        gui.draw();


        window.display();


    }
}




