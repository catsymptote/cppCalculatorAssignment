// Included files
#include "ioHandler.h"
#include "stringHandler.h"
#include "mathCalculation.h"
#include "globalDef.h"


#include <iostream>

// For getch()
#include <conio.h>


int main()
{
    // Get maths from user
    std::cout << "Input maths. Include space or enter between the elements!" << std::endl;
    std::cout << "number1 operator number2> ";

    // Get the user input.
    mathOpStr input = getUserInput();
    mathOp result = stringConverter(input.one, input.three, input.two);

    // Print input and result
    std::cout   << "\n---------------\n"
                << result.num1 << " "
                << result.oper << " "
                << result.num2 << " = "
                << operatorFunction(result.num1, result.num2, result.oper)
                << "\n---------------\n";

    // Holding window open
    std::cout << "Press any key to close ";
    getch();

    return 0;
}
