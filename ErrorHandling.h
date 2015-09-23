#ifndef ERRORHANDLING_H_INCLUDED
#define ERRORHANDLING_H_INCLUDED
#include <TGUI/TGUI.hpp>
#include "ObjectCreateFunc.h"
#include "ThreadHandling.h"
#include <windows.h>

void fatalError();
extern bool killProgram;

#endif // ERRORHANDLING_H_INCLUDED
