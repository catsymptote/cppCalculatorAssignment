#include "stringHandler.h"

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
mathOp stringConverter(std::string inNum1, std::string inOper, std::string inNum2)
{
    /*
    char chNum1[1024];
    char chNum2[1024];
    strcpy(chNum1, inNum1.c_str());
    strcpy(chNum2, inNum2.c_str());
    */

    // Make struct
    mathOp thingy;
    thingy.num1 = stringToDouble(inNum1);
    thingy.num2 = stringToDouble(inNum2);
    thingy.oper = inOper[0];

    std::cout << "num1 " << thingy.num1 << "\nnum2 " << thingy.num2 << std::endl;
    return thingy;
}

double stringToDouble(std::string str)
{
    char chr[1024];
    strcpy(chr, str.c_str());
    return atof(chr);
}
