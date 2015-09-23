#include "ThreadHandling.h"

sf::Thread loadingTextThread(&loading);
bool isLoading = true;
int loadStep = 1;

void initializeThreads()
{
    loadingTextThread.launch();
}

void loading()
{
while (true)
{
    while (isLoading == true)
    {
        //improve handling
        switch (loadStep)
        {
        case 1:
        cout << "\rLoading   ";
        Sleep(500);
        break;

        case 2:
        cout << "\rLoading.  ";
        Sleep(500);
        break;

        case 3:
        cout << "\rLoading.. ";
        Sleep(500);
        break;

        case 4:
        cout << "\rLoading...";
        Sleep(500);
        break;
        }

    loadStep =+ 1;
    }
cout << "\nDone";
}
}

void killLoad()
{
    loadingTextThread.terminate();
}
