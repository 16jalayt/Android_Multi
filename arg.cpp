#include "arg.h"
bool hideconsole = true;
bool isLoading = true;
sf::Thread loadingTextThread(&loading);
int loadStep = 1;

void cmdparse(int argc, char** argv)
{
if (argc != 1)
    {
        string flag1 = argv[1];
        cout << "flags entered: " << flag1 << endl;
        if (flag1.compare("-h") == 0)
        {
            cout << "showing console\n";
            hideconsole = false;
        }
        else
        {
            cout << "invalid arg: " << flag1 << endl ;
            system("PAUSE");
            exit(1);
        }
    }
else
    {
        hideconsole = true;

    }

if (hideconsole == true)
{
    isLoading = true;
    loadingTextThread.launch();
}

}

void loading()
{
    while (isLoading == true)
    {
        //need to speed up
        switch (loadStep)
        {
        case 1:
        cout << "\rLoading   ";
        Sleep(500);
        case 2:
        cout << "\rLoading.  ";
        Sleep(500);
        case 3:
        cout << "\rLoading.. ";
        Sleep(500);
        case 4:
        cout << "\rLoading...";
        Sleep(500);
        }
        loadStep =+ 1;
    }
cout << "\nDone";
loadingTextThread.terminate();
}

void checkConsoleClose()
{
    if (hideconsole)
        ShowWindow( GetConsoleWindow(), SW_HIDE );
}

void killLoad()
{
    loadingTextThread.terminate();
}
