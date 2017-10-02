#include "ioHandler.h"


std::string getStringInput()
{
    std::string inString;
    getline(std::cin, inString);
    return inString;
}


// Print out the vectors. What is templates even :P
void vectorIntPrinter(std::vector<int> vect)
{
    std::cout << "Input:\t";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

void vectorStrPrinter(std::vector<std::string> vect)
{
    std::cout << "Input:\t";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}
