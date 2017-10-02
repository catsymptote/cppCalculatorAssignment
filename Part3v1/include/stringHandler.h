#ifndef STRINGHANDLER_H_INCLUDED
#define STRINGHANDLER_H_INCLUDED


#include "globalDef.h"


#include <iostream>
#include <string.h>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>


std::string removeStringSpaces(std::string str);
std::vector<std::string> splitStringByIndexVector(std::string inString, std::vector<int> operIndexes);
std::vector<int> operatorIndexer(std::string inString);
std::vector<std::string> stringSplitter(std::string inString);
mathOp stringConverter(std::string inNum1, std::string inNum2, std::string inOper);
double stringToDouble(std::string str);


#endif // STRINGHANDLER_H_INCLUDED
