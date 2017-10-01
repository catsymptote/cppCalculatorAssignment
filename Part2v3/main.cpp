#include <iostream>

// For getch()
#include <conio.h>

// For string -> double conversion
#include <string.h>

// For splitting strings
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>


// Just three strings. Because reasons.
struct mathOpStr {
    std::string one;
    std::string two;
    std::string three;
};

// Object of the two numbers and their operator.
struct mathOp {
    double  num1;
    char    oper;
    double  num2;
};

// Supported operators.
const static char operators[] = {
    '+', '-', '*', '/'
};

// Extra print functions (mostly for debugging).
void vectorPrinter(std::vector<int> vect);
void vectorStrPrinter(std::vector<std::string> vect);

mathOpStr getInput();
std::string removeStringSpaces(std::string str);
std::vector<std::string> splitStringByIndexVector(std::string inString, std::vector<int> operIndexes);
std::vector<int> operatorIndexer(std::string inString);
std::vector<std::string> stringSplitter(std::string inString);
mathOp stringHandler(std::string inNum1, std::string inNum2, std::string inOper);
double operatorFunction(double num1, double num2, char oper);


// This is the main function. It is main af.
int main()
{
    // Get maths from user
    std::cout << "Input maths. Include space or enter between the elements!" << std::endl;
    std::cout << "number1 operator number2> ";

    // Get the user input.
    mathOpStr input = getInput();

    // Print solution
    //std::cout << input.one << " " << input.two << " " << input.three << std::endl;

    mathOp cookie = stringHandler(input.one, input.three, input.two);

    // Print input and result
    std::cout   << "\n---------------\n"
                << cookie.num1 << " "
                << cookie.oper << " "
                << cookie.num2 << " = "
                << operatorFunction(cookie.num1, cookie.num2, cookie.oper)
                << "\n---------------\n";

    // Holding window open
    std::cout << "Press any key to close ";
    getch();

    return 0;
}

// Takes the data into a single string,
// and then uses stringSplitter() to make it into the three strings.
mathOpStr getInput()
{
    std::string inString;
    getline(std::cin, inString);

    inString = removeStringSpaces(inString);

    std::vector<int> operIndexes = operatorIndexer(inString);
    std::vector<std::string> stringVector = splitStringByIndexVector(inString, operIndexes);
    vectorStrPrinter(stringVector);

    mathOpStr input;
    input.one   = stringVector[0];  // num1
    input.two   = stringVector[1];  // oper
    input.three = stringVector[2];  // num2
    return input;
}

// Remove spaces from the string.
std::string removeStringSpaces(std::string str)
{
    // Based on: https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
    str.erase(std::remove(str.begin(),str.end(),' '),str.end());
    return str;
}

// Splits input string into string-vector
std::vector<std::string> splitStringByIndexVector(std::string inString, std::vector<int> operIndexes)
{
    std::vector<std::string> elements;

    int opIndex = 0;
    int strPos = 0;
    int nextOp = 0;
    int prevOp = 0;
    while(opIndex < operIndexes.size() +1)
    {
        nextOp = operIndexes[opIndex];

        // Number
        elements.push_back(inString.substr( strPos, nextOp - prevOp ));  // 0, nextOp

        // Operator
        if (opIndex < operIndexes.size())
        {
            elements.push_back(inString.substr( nextOp, 1 ));  // 4, 1
        }

        strPos = nextOp +1;
        prevOp = nextOp +1;
        opIndex++;
    }

    return elements;
}

// Find the indexes of the input string.
std::vector<int> operatorIndexer(std::string inString)
{
    std::vector<int> operIndexes;

    for (int strIndex = 0; strIndex < inString.size(); strIndex++)
    {
        for (int opIndex = 0; opIndex < sizeof(operators); opIndex++)
        {
            if(inString[strIndex] == operators[opIndex])
            {
                operIndexes.push_back(strIndex);
            }
        }
    }
    return operIndexes;
}

// Split strings by spaces, from the interwebs, not currently used.
std::vector<std::string> stringSplitter(std::string inString)
{
    // Based on https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
    std::istringstream iss(inString);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                      std::istream_iterator<std::string>());
    return results;
}

// Make strings into numbers and operator chars.
mathOp stringHandler(std::string inNum1, std::string inNum2, std::string inOper)
{
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

// Run two numbered calculations with basic operations.
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

// Print out the vectors. What is templates even :P
void vectorPrinter(std::vector<int> vect)
{
    return;
    std::cout << "Input:\t";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}
void vectorStrPrinter(std::vector<std::string> vect)
{
    return;
    std::cout << "Input:\t";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}
