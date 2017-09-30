#include <iostream>

// For getch()
#include <conio.h>

// For string -> double conversion
#include <stdlib.h>
#include <string.h>

// For splitting strings
#include <vector>
#include <iterator>
#include <sstream>


struct threeStrings {
    std::string one;
    std::string two;
    std::string three;
};

struct mathOp {
    double  num1;
    char    oper;
    double  num2;
};

// Version 1
threeStrings getInputVersion1();

// Version 2
threeStrings getInputVersion2();
std::vector<std::string> stringSplitter(std::string inString);

// Used by both versions
mathOp stringHandler(std::string inNum1, std::string inNum2, std::string inOper);
double operatorFunction(double num1, double num2, char oper);


int main()
{
    // Get maths from user
    std::cout << "Input maths. Include space or enter between the elements!" << std::endl;
    std::cout << "number1 operator number2> ";

    // Get the user input.
    // Change between 1 and 2 to use the different versions.
    threeStrings input = getInputVersion2();


    // Print solution
    std::cout << input.one << " " << input.two << " " << input.three << std::endl;

    mathOp cookie = stringHandler(input.one, input.three, input.two);
    std::cout << "Input:\t" << cookie.num1 << " "
                            << cookie.oper << " "
                            << cookie.num2 << std::endl;
    std::cout << "Result:\t" << operatorFunction(cookie.num1, cookie.num2, cookie.oper) << std::endl;

    // Holding window open
    std::cout << "Press any key to close ";
    getch();

    return 0;
}

// Version one takes the data directly into 3 strings from cin.
threeStrings getInputVersion1()
{
    std::string inNum1, inOper, inNum2;
    std::cin >> inNum1 >> inOper >> inNum2;
    threeStrings input;
    input.one   = inNum1;
    input.two   = inOper;
    input.three = inNum2;
    return input;
}

// Version two takes the data into a single string,
// and then uses stringSplitter() to make it into the three strings.
threeStrings getInputVersion2()
{
    std::string inString;
    getline(std::cin, inString);
    std::vector<std::string> results;

    std::vector<std::string> stringVector = stringSplitter(inString);

    threeStrings input;
    input.one   = stringVector[0];  // num1
    input.two   = stringVector[1];  // oper
    input.three = stringVector[2];  // num2
    return input;
}

std::vector<std::string> stringSplitter(std::string inString)
{
    // Based on https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
    std::istringstream iss(inString);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                      std::istream_iterator<std::string>());
    return results;
}

mathOp stringHandler(std::string inNum1, std::string inNum2, std::string inOper)
{
    // Convert std::string -> char[]
    char chNum1[1024];
    char chNum2[1024];
    strcpy(chNum1, inNum1.c_str());
    strcpy(chNum2, inNum2.c_str());

    // Make struct
    mathOp thingy;
    thingy.num1 = atof(chNum1);
    thingy.num2 = atof(chNum2);
    thingy.oper = inOper[0];

    return thingy;
}

double operatorFunction(double num1, double num2, char oper)
{
    switch (oper)
    {
        case '+':
            return (num1 + num2);
        case '-':
            return (num1 - num2);
        case '*':
            return (num1 * num2);
        case '/':
            return (num1 / num2);
        default:
            std::cout   << "Error. Operator " << oper
                        << " not recognized"  << std::endl;
            return -1;
    }
}
