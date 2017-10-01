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
#include <algorithm>


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

/*
enum operators {
    char add = '+';
    char sub = '-';
    char mul = '*';
    char div = '/';
};
*/

const static char operators[] = {
    '+', '-', '*', '/'
};

//void vectorPrinter(std::vector<int, std::string> vect);
void vectorPrinter(std::vector<int> vect);
void vectorStrPrinter(std::vector<std::string> vect);

threeStrings getInput();
std::string removeStringSpaces(std::string str);
std::vector<std::string> splitStringByIndexVector(std::string inString, std::vector<int> operIndexes);
std::vector<int> operatorIndexer(std::string inString);
std::vector<std::string> stringSplitter(std::string inString);
mathOp stringHandler(std::string inNum1, std::string inNum2, std::string inOper);
double operatorFunction(double num1, double num2, char oper);


int main()
{
    // Get maths from user
    std::cout << "Input maths. Include space or enter between the elements!" << std::endl;
    std::cout << "number1 operator number2> ";

    // Get the user input.
    // Change between 1 and 2 to use the different versions.
    threeStrings input = getInput();

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

// Takes the data into a single string,
// and then uses stringSplitter() to make it into the three strings.
threeStrings getInput()
{
    std::string inString;
    getline(std::cin, inString);

    // Assuming user has included spaces.
    //std::vector<std::string> results;
    ///std::vector<std::string> stringVector = stringSplitter(inString);

    //std::cout << stringVector.size() << std::endl;
    ///std::cout << "Test" << std::endl;

    // If wrong format (probably that the user has not included spaces).

    //if(stringVector.size() != 3)

    /*
    std::string delimiter1 = "+";
    std::string delimiter2 = "-";
    std::string delimiter3 = "*";
    std::string delimiter4 = "/";
    */
    inString = removeStringSpaces(inString);
    std::cout << "inString:\t" << inString << std::endl;

    std::vector<int> operIndexes = operatorIndexer(inString);
    std::vector<std::string> stringVector = splitStringByIndexVector(inString, operIndexes);
    vectorStrPrinter(stringVector);
    /*
    std::string num1;
    std::string oper;
    std::string num2;

    std::cout << "num1\t" << num1 << std::endl;
    std::cout << "oper\t" << oper << std::endl;
    std::cout << "num2\t" << num2 << std::endl;
    */

    threeStrings input;
    input.one   = stringVector[0];  // num1
    input.two   = stringVector[1];  // oper
    input.three = stringVector[2];  // num2
    return input;
}

std::string removeStringSpaces(std::string input)
{
    //remove_if(str.begin(), str.end(), isspace);   // fak dis thing
    input.erase(std::remove(input.begin(),input.end(),' '),input.end());
    return input;
}

std::vector<std::string> splitStringByIndexVector(std::string inString, std::vector<int> operIndexes)
{
    std::cout << "Test: splitStringByIndexVector (beginning)" << std::endl;

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

    /*
    for (int index = 0; index < operIndexes.size(); index++)
    {
        // Number
        elements.push_back(inString.substr(0, operIndexes[index]));

        // Operator (if not at last element)
        if (index < operIndexes.size() -1)
        {
            elements.push_back(inString.substr(operIndexes[index], 1));
        }
    }
    */

    std::cout << "Test: return elements from splitStringByIndexVector" << std::endl;
    return elements;
}

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

        //std::string num1 = inString.substr(0, inString.find(operators[i]));
        //std::string oper = inString.substr(inString.find(operators[i]), 1);
        //std::string num2 = inString.substr(inString.find(operators[i]) +1, inString.size() - inString.find(operators[i]) +1);
    }
    vectorPrinter(operIndexes);
    std::cout << "Test: operatorIndexes (end)" << std::endl;
    return operIndexes;
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


//template<typename T, typename A>
void vectorPrinter(std::vector<int> vect)
{
    std::cout << "Vector:\t";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << "\t";
    }
    std::cout << std::endl;
}
void vectorStrPrinter(std::vector<std::string> vect)
{
    std::cout << "Vector:\t";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << "<" << vect[i] << ">\t";
    }
    std::cout << std::endl;
}
