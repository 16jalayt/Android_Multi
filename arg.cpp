#include "arg.h"
bool hideconsole = true;


void cmdparse(int argc, char** argv)
{
    /*
if (argc != 1)
    {
        string flag1 = argv[1];
        cout << "flags entered: " << flag1 << endl;

        if (flag1.compare("-c") == 0)
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

    }*/

    for (int i = 1; i < argc; i++)
    {

    if (i + 1 <= argc)
        if (argv[i] == "-c")
        {
            cout << "showing console\n";
            hideconsole = false;
        }
        else
        {
            cout << "invalid argument";
        }
    }



if (hideconsole == true)
{
    isLoading = true;
}


void checkConsoleClose()
{
    if (hideconsole)
        ShowWindow( GetConsoleWindow(), SW_HIDE );
}
