#include "ErrorHandling.h"

sf::Thread crashThread(&fatalError);
bool killProgram = false;


void fatalError()
{
        //isLoading = false;
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
