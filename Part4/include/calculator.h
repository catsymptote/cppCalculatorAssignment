#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED



#include <iostream>     // cout, cin++  - Input and output
#include <vector>       // vector       - std::vector<T>
#include <string.h>     // strcpy       - string to double conversion
#include <math.h>       // fmod, pow++  - For maths
#include <algorithm>    // Erase or something
#include <tuple>        // tuple        - For lazy return of 'arrays'
#include <conio.h>      // getch()      - For holding the window open when done
#include <sstream>      // setprecision - For long double to string conversion
#include <iomanip>      // stringstream - For long double to string conversion



/// Any supported operators (including brackets).
const static char operatorsAndBrackets[] = {
    '(', ')',   // 0 - Brackets
    '[', ']',
    '{', '}',
    '^',    // 1 - Exponents
    '/',    // 2 - Division
    '%',    // 3 - Modulus
    '*',    // 4 - Multiplication
    '-',    // 5 - Subtraction
    '+'     // 6 - Addition
};

/// Supported operators (excluding brackets).
/// Order is important for order of operations!!
const static char operators[] = {
    '^',    // 1 - Exponents
    '/',    // 2 - Division
    '%',    // 3 - Modulus
    '*',    // 4 - Multiplication
    '-',    // 5 - Subtraction
    '+'     // 6 - Addition
};


/// Char array of all legal input characters
const static char legalChars[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.',  // Numbers
    '(', ')', '[', ']', '{', '}',                           // Brackets
    '^', '%', '/', '*', '-', '+'                            // Operators
};





/// Interface
void calcInputPrint();
long double calcInput();
long double calcStr(std::string strInput);
long double calcVect(std::vector<std::string> vectInput);
long double altCalcVect(std::vector<std::string> vectInput);


/// Input and output
std::string getStringInput();
void vectorPrinter(std::vector<int> vect);
void vectorStrPrinter(std::vector<std::string> vect);
void debugVectorStrPrinter(std::vector<std::string> vect);

/// Legality checker
bool charLegality(std::string str);
bool bracketLegality(std::string strInput);


/// String handling
std::string removeStringSpaces(std::string str);
bool charIsOper(char inChar);
std::vector<std::string> stringSplitter(std::string inString);
long double stringToDouble(std::string str);
std::vector<std::string> stringToVector(std::string str);


/// Maths
long double basicOperatorFunction(long double num1, char oper, long double num2);
long double calculationHandler(std::vector<std::string> elements);

// For brackets
bool bracketFinder(std::vector<std::string> elements);
bool bracketStartStringFinder(std::string str);
bool bracketStopStringFinder(std::string str);
bool bracketVectFinder(std::vector<std::string> elements);
std::tuple<int, int> bracketIndex(std::vector<std::string> elements);
std::vector<std::string> bracketedSubvectExtractor(std::vector<std::string> elements, int start, int stop);


#endif // CALCULATOR_H_INCLUDED
