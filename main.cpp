#include "main.h"

int tut_var_setup_page = 0;
int tut_var_trouble_page = 0;
int previousScrolbarValue = 0;
bool hideconsole = true;
void loadButton(Button::Ptr buttonname, Gui &gui, int sizeX, int sizeY, int posX, int posY, string text, int textSize, int callbackID, bool hide);
/* TO DO
loading screen in console and main window

*/

void scrollPanel(tgui::Panel::Ptr panel_trouble_sam, const tgui::Callback& callback)
{
    int distanceToMove = previousScrolbarValue - callback.value;

    // Move all widgets that are inside the panel
    for (auto& widget : panel_trouble_sam->getWidgets())
        widget->setPosition(widget->getPosition().x, widget->getPosition().y + distanceToMove);

    previousScrolbarValue = callback.value;
}




int main(int argc, char** argv)
{
    cmdparse(argc, argv, hideconsole);
    RenderWindow window(sf::VideoMode(800, 600), "Marion Robotics");
    Gui gui(window);
    gui.setGlobalFont("data/DejaVuSans.ttf");
    Font font;
    font.loadFromFile("data/DejaVuSans.ttf");

    Button::Ptr tut_button_menu_troubleshoot(gui);
    loadButton(tut_button_menu_troubleshoot, gui, 320, 100, 270, 75, "Troubleshooting", 35, 53, false);


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
            return 0;
        }

        window.clear();

        gui.draw();


        window.display();


    }
}

void loadButton(Button::Ptr buttonname, Gui &gui, int sizeX, int sizeY, int posX, int posY, string text, int textSize, int callbackID, bool hide)
{

    buttonname->load("data/Black.conf");
    buttonname->setSize(sizeX, sizeY);
    buttonname->setPosition(posX, posY);
    buttonname->setText(text);
    buttonname->bindCallback(Button::LeftMouseClicked);
    buttonname->setCallbackId(callbackID);
    buttonname->setTextSize(textSize);
}
