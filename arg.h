#ifndef ARG_H
#define ARG_H
#define _WIN32_WINNT 0x0502
#include <windows.h>
#include <iostream>

using namespace std;

void cmdparse(int argc, char** argv);
void checkConsoleClose();


#endif
