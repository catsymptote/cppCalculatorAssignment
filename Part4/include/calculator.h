#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED



#include <iostream>     // cout, cin++  - Input and output
#include <vector>       // vector       - std::vector<T>
#include <string.h>     // strcpy       - string to double conversion
#include <math.h>       // fmod, pow++  - For maths
#include <algorithm>    // Erase or something
#include <tuple>        // tuple        - For lazy return of 'arrays'
#include <conio.h>      // getch()      - For holding the window open when done



/// Any supported operators (including brackets).
const static char operatorsAndBrackets[] = {
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

/// Supported operators (excluding brackets). Order is important for order of operations!!
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
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',   // Numbers
    '(', ')', '[', ']', '{', '}',                       // Brackets
    '^', '%', '/', '*', '-', '+'                        // Operators
};





/// Interface
void calcInputPrint();
double calcInput();
double calcStr(std::string strInput);
double calcVect(std::vector<std::string> vectInput);
double altCalcVect(std::vector<std::string> vectInput);


/// Input and output
std::string getStringInput();
void vectorPrinter(std::vector<int> vect);
void vectorStrPrinter(std::vector<std::string> vect);
void debugVectorStrPrinter(std::vector<std::string> vect);

/// Legality checker
bool charLegality(std::string str);


/// String handling
std::string removeStringSpaces(std::string str);
bool charIsOper(char inChar);
std::vector<std::string> stringSplitter(std::string inString);
double stringToDouble(std::string str);

// Splitter v. 1
std::vector<int> operatorIndexer(std::string inString);
std::vector<std::string> splitStringByIndexVector(std::string inString, std::vector<int> operIndexes);

// Splitter v. 2
std::vector<std::string> stringToVector(std::string str);


/// Maths
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
