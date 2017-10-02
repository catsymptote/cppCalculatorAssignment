#ifndef MATHCALCULATION_H_INCLUDED
#define MATHCALCULATION_H_INCLUDED


#include "globalDef.h"
#include "stringHandler.h"


#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>


double basicOperatorFunction(double num1, char oper, double num2);
std::string ltrCalculationHandler(std::vector<std::string> elements);
double calculationHandler(std::vector<std::string> elements);


#endif // MATHCALCULATION_H_INCLUDED
