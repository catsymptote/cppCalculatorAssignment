#include "ioHandler.h"


ioHandler::ioHandler()
{
    //ctor
}

ioHandler::~ioHandler()
{
    //dtor
}


// Takes the data into a single string,
// and then uses stringSplitter() to make it into the three strings.
mathOpStr getUserInput()
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
