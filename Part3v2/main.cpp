#include "ioHandler.h"
#include "stringHandler.h"
#include "mathCalculation.h"
#include "globalDef.h"


#include <iostream>
#include <vector>
#include <string.h>

// For getch()
#include <conio.h>


int main()
{
    // User info.
    std::cout << "Input maths. Include space or enter between the elements!" << std::endl;
    std::cout << "number1 operator number2> ";


    // Convert and calculate.
    std::string strInput = getStringInput();
    strInput = removeStringSpaces(strInput);
    std::vector<int> operIndexes = operatorIndexer(strInput);
    std::vector<std::string> vectInput = splitStringByIndexVector(strInput, operIndexes);
    double result = calculationHandler(vectInput);


    // Print input and result.
    std::cout   << "\n---------------\n";
    vectorStrPrinter(vectInput);
    std::cout   << "= " << result
                << "\n---------------\n";

    // Holding window open.
    std::cout << "Press any key to close ";
    getch();

    return 0;
}
