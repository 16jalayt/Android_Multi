#include "main.h"
#include "arg.h"

int tut_var_setup_page = 0;
int tut_var_trouble_page = 0;
int previousScrolbarValue = 0;
bool exitProgram = false;
bool confError = false;
sf::Thread crashThread(&fatalError);
bool killProgram = false;

bool refCodeText1Visible = false;

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

//Code reference
    Panel::Ptr refCodePanel(gui);
    loadPanel(refCodePanel, 750, 500, 0, 0, 200, 200, 200, true);

    Scrollbar::Ptr refCodeScroll(gui);
    //                Bar name name,     Panel name      sizex,sizey,amount,low ,High,start hidden
    loadScrollBar(refCodeScroll, refCodePanel, 50, 500,     30, 500, 500, true);

    Button::Ptr refCodeBack(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(refCodeBack, 200, 50, 300, 520, "Back", 25, 321, true);

    sf::Text refCodeText1;
    refCodeText1.setFont(font);
    refCodeText1.setString("This will guide you through the connection of \nthe Samantha module to the WiFi.");
    refCodeText1.setCharacterSize(20);
    refCodeText1.setColor(Color::White);
    refCodeText1.setPosition(Vector2f(15, 30));
    //loadText()



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

//Troubleshoot connect menu
    Button::Ptr troubleConCom(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(troubleConCom, 320, 100, 240, 175, "To Computer", 35, 202, true);

    //Button::Ptr troubleConP2P(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    //loadButton(troubleConP2P, 320, 100, 240, 320, "Won't move", 35, 63, true);

    Button::Ptr troubleConBack(gui);
    //         button name, sizex,sizey,posx,posy,button text ,textsize,callbackid,start hidden
    loadButton(troubleConBack, 320, 100, 240, 470, "Back", 35, 201, true);

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
    conComLabel2->setText("Is a good battery in, the brick and the\nmain switch is turned on.");
    conComLabel2->setSize(32, 32);
    conComLabel2->setTextColor(sf::Color::Black);




    isLoading = false;
    if (isLoading == false)
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
                troubleConBack->show();
                troubleConCom->show();
                troubleConnect->hide();
                troubleMove->hide();
                troubleBackMain->hide();
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
                refCodePanel->show();
                refCodeScroll->show();
                refCodeBack->show();
                //refCodeText1->show();
                //window.draw(refCodeText1);
                refCodeText1Visible = true;
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

//Ref sub
            case 321://Back Clicked
                refCodePanel->hide();
                refCodeScroll->hide();
                refCodeBack->hide();
                //refCodeText1->hide();
                refCodeText1Visible = false;
                refCode->show();
                refHardware->show();
                refPrinting->show();
                refBack->show();
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

//Troubleshoot connect menu
            case 201://Back clicked
                troubleConBack->hide();
                troubleConCom->hide();
                troubleConnect->show();
                troubleMove->show();
                troubleBackMain->show();
                break;

            case 202://Computer clicked
                troubleConComPanel->show();
                troubleConComScroll->show();
                troubleConComBack->show();
                troubleConnect->hide();
                troubleMove->hide();
                troubleConBack->hide();
                break;

            //case 221://Back clicked
                //troubleConBack->hide();
                //troubleConCom->hide();
                //troubleConnect->show();
                //troubleMove->show();
                //troubleBackMain->show();
                //break;

//troubleshoot connect computer panel
            case 221://back clicked
                troubleConComPanel->hide();
                troubleConComScroll->hide();
                troubleConComBack->hide();
                troubleConBack->show();
                troubleConCom->show();


            }
            //check for exit status, because return dosn't work in a switch statement.
            //for an if statement with one line, you dont need parenthesis. :P
            if (exitProgram == true)
                return 0;

        }

        window.clear(sf::Color(0, 250, 0));

        gui.draw();
//text must be rendered here.
        if(refCodeText1Visible == true)
            window.draw(refCodeText1);


        window.display();


    }
}

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
        crashThread.launch();
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

void loadLabel(Label::Ptr labelname, int posX, int posY, string text, int textSize, int colR, int colG, int colB, bool hide)
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
    scrollname->setPosition(panelname->getPosition() + sf::Vector2f(panelname->getSize().x, 0));
    scrollname->setArrowScrollAmount(30);
    scrollname->setLowValue(500); // Viewable area (height of the panel)
    scrollname->setMaximum(500); // Total area (height of the 5 images)
	scrollname->bindCallbackEx(std::bind(scrollPanel, panelname, std::placeholders::_1), tgui::Scrollbar::ValueChanged);
    if (hide == true)
        scrollname->hide();
}

void fatalError()
{
        isLoading = false;
        killLoad();
        //loadingTextThread.terminate();
        Sleep(300);
        //IRL you should try to avoid system. It is resource intensive.
        //system("CLS");
        //replacement pasts in 100 \n which means new line
        cout << string( 100, '\n' );
        if (confError == true)
        {
         cout << "\nBlack.conf not found! Please re-download.\n";
         //confError == false;
        }
        else
        {
        cout << "\nGeneric Fatal Error\n";
        }
        //system("PAUSE");
        cout << "Press Enter to continue...";
        //paste in some more new lines to compensate and boost the text up on screen
        cout << string( 10, '\n' );
        cin.get();

        //exitProgram = true;
        //abort();
        return;

        //window.close();
}
