#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED



#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <tuple>



// For getch()
#include <conio.h>



// Supported operators. Order is important for order of operations!!
const static char operators[] = {
    '(',    // 0 - Brackets
    ')',
    '[',
    ']',
    '{',
    '}',
    '^',    // 1 - Exponents
    '/',    // 2 - Division
    '%',    // 3 - Modulus
    '*',    // 4 - Multiplication
    '-',    // 5 - Subtraction
    '+'     // 6 - Addition
};



// Interface
void calcPrint();
double calcStr(std::string strInput);
double calcVect(std::vector<std::string> vectInput);


// Input and output
std::string getStringInput();
void vectorPrinter(std::vector<int> vect);
void vectorStrPrinter(std::vector<std::string> vect);


// String handling
std::string removeStringSpaces(std::string str);

std::vector<int> operatorIndexer(std::string inString);
std::vector<std::string> splitStringByIndexVector(std::string inString, std::vector<int> operIndexes);
// vs
std::vector<std::string> stringToVector(std::string str);


bool charIsOper(char inChar);
std::vector<std::string> stringSplitter(std::string inString);
double stringToDouble(std::string str);


// Maths
double basicOperatorFunction(double num1, char oper, double num2);
double calculationHandler(std::vector<std::string> elements);

// For brackets
bool bracketFinder(std::vector<std::string> elements);
bool bracketStartStringFinder(std::string str);
bool bracketStopStringFinder(std::string str);
bool bracketVectFinder(std::vector<std::string> elements);
std::tuple<int, int> bracketIndex(std::vector<std::string> elements);
std::vector<std::string> bracketedSubvectExtractor(std::vector<std::string> elements, int start, int stop);


#endif // CALCULATOR_H_INCLUDED
