#ifndef IOHANDLER_H_INCLUDED
#define IOHANDLER_H_INCLUDED


#include "globalDef.h"
#include "stringHandler.h"


#include <vector>


mathOpStr getUserInput();
std::string getStringInput();

void vectorPrinter(std::vector<int> vect);
void vectorStrPrinter(std::vector<std::string> vect);


#endif // IOHANDLER_H_INCLUDED
