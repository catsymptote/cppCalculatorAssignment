#include <iostream>
#include <vector>


#include "calculator.h"


int main()
{
    // Test by user input
    calcInputPrint();


    // Test by passing string
    std::string str = "4 + 5 + 11 * 3 + 4 * 4 + 9 / 3 + 4 * 12 - 3 / 4";
    std::cout << "calcStr():\t" << calcStr(str) << std::endl;


    // Test by passing vector<string>
    std::vector<std::string> vect;
    vect.push_back("4");
    vect.push_back("+");
    vect.push_back("5");
    vect.push_back("+");
    vect.push_back("(");
    vect.push_back("7");
    vect.push_back("+");
    vect.push_back("4");
    vect.push_back(")");
    vect.push_back("*");
    vect.push_back("3");
    vect.push_back("+");
    vect.push_back("4");
    vect.push_back("*");
    vect.push_back("4");
    vect.push_back("+");
    vect.push_back("9");
    vect.push_back("/");
    vect.push_back("3");
    vect.push_back("+");
    vect.push_back("4");
    vect.push_back("*");
    vect.push_back("12");
    vect.push_back("-");
    vect.push_back("3");
    vect.push_back("/");
    vect.push_back("4");
    std::cout << "calcVect():\t" << calcVect(vect) << std::endl;

    return 0;
}
