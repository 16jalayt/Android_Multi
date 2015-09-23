#ifndef ARG_H
#define ARG_H
#define _WIN32_WINNT 0x0502
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <TGUI/TGUI.hpp>
#include "ErrorHandling.h"
#include "ThreadHandling.h"

using namespace std;
using namespace sf;
using namespace tgui;

void cmdparse(int argc, char** argv);
void checkConsoleClose();


//bool isLoading;




#endif
