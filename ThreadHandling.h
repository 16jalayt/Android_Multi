#ifndef THREADHANDLING_H_INCLUDED
#define THREADHANDLING_H_INCLUDED
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <windows.h>

using namespace std;
using namespace sf;
using namespace tgui;

extern bool isLoading;
extern int loadStep;

void initializeThreads();
void loading();
void killLoad();

#endif // THREADHANDLING_H_INCLUDED
