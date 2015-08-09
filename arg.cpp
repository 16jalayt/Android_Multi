#include "arg.h"
bool hideconsole = true;

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
            cout << "invalid arg\n" ;
            system("PAUSE");
            exit(1);
        }
    }
else
    {
        hideconsole = true;

    }
}

void checkConsoleClose()
{
    if (hideconsole)
        ShowWindow( GetConsoleWindow(), SW_HIDE );
}
