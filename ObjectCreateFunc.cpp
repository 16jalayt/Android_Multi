#include "ObjectCreateFunc.h"

bool confError = false;
int previousScrolbarValue = 0;

void scrollPanel(tgui::Panel::Ptr panelname, const tgui::Callback& callback)
{
    int distanceToMove = previousScrolbarValue - callback.value;

    // Move all widgets that are inside the panel
    for (auto& widget : panelname->getWidgets())
        widget->setPosition(widget->getPosition().x, widget->getPosition().y + distanceToMove);

    previousScrolbarValue = callback.value;
}

void loadButton(Button::Ptr buttonname, int sizeX, int sizeY, int posX, int posY, string text, int textSize, int callbackID, bool hide)
{
    if (!buttonname->load("data/Black.conf"))
    {
        confError = true;
        //crashThread.launch();
    }
    //buttonname->load("data/Black.conf");
    buttonname->setSize(sizeX, sizeY);
    buttonname->setPosition(posX, posY);
    buttonname->setText(text);
    buttonname->bindCallback(Button::LeftMouseClicked);
    buttonname->setCallbackId(callbackID);
    buttonname->setTextSize(textSize);
    if (hide == true)
        buttonname->hide();
}

void loadPanel(Panel::Ptr panelname, int sizeX, int sizeY, int posX, int posY, int colR, int colG, int colB, bool hide)
{

    panelname->setSize(sizeX, sizeY);
    panelname->setPosition(posX, posY);
    panelname->setBackgroundColor(sf::Color(colR, colG, colB));
    if (hide == true)
        panelname->hide();
}

void loadLabel(Label::Ptr labelname, int posX, int posY, int textSize, int colR, int colG, int colB, bool hide, string text)
{

    labelname->load("data/Black.conf");
    labelname->setPosition(posX, posY);
    labelname->setText(text);
    labelname->setTextSize(textSize);
    labelname->setTextColor(sf::Color(colR, colG, colB));
    if (hide == true)
        labelname->hide();
}

void loadCheckbox(Checkbox::Ptr checkname, int sizeX, int sizeY, int posX, int posY, string text, int textSize, int colR, int colG, int colB, bool hide)
{
    checkname->load("data/Black.conf");
    checkname->setSize(sizeX, sizeY);
    checkname->setPosition(posX, posY);
    checkname->setText(text);
    checkname->setTextSize(textSize);
    checkname->setTextColor(sf::Color(colR, colG, colB));
    if (hide == true)
        checkname->hide();
}

void loadText(sf::Text textname, Font &font, int posX, int posY, string text, int textSize, int colR, int colG, int colB, bool hide)
{
    textname.setFont(font);
    textname.setPosition(posX, posY);
    textname.setString(text);
    textname.setColor(sf::Color(colR, colG, colB));
    textname.setCharacterSize(textSize);
    //if (hide == true)
        //textname->hide();
}

void loadScrollBar(Scrollbar::Ptr scrollname, Panel::Ptr panelname, int sizeX, int sizeY,int scrollAmount, int lowValue, int maxValue, bool hide)
{
    scrollname->load("data/Black.conf");
    scrollname->setSize(sizeX, sizeY);
    scrollname->setArrowScrollAmount(30);
    scrollname->setLowValue(500); // Viewable area (height of the panel)
    scrollname->setMaximum(500); // Total area (height of the 5 images)
    if (hide == true)
        scrollname->hide();
}
