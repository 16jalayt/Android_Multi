#ifndef ARG_H
#define ARG_H
#define _WIN32_WINNT 0x0502
#include <windows.h>
#include <iostream>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

void cmdparse(int argc, char** argv);
void checkConsoleClose();
void loading();
void killLoad();

extern bool isLoading;
//bool isLoading;




#endif
