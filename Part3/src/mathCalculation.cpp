#include "mathCalculation.h"


// Run two numbered calculations with basic operations.
double basicOperatorFunction(double num1, char oper, double num2)
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
        case '^':
            return (pow(num1, num2));
        case '%':
            return (fmod(num1, num2));
        default:
            std::cout   << "Error. Operator " << oper
                        << " not recognized"  << std::endl;
            break;
    }
}


#include <iostream>
#include "ioHandler.h"

// This function calculates from left to right, similarly to a simple calculator.
// This means, it does not follow order of operations.
std::string ltrCalculationHandler(std::vector<std::string> elements)
{
    std::string solution;
    std::string tmp;
    double num1;
    while (elements.size() >= 3)
    {
        mathOp relElem = stringConverter(elements[0], elements[1], elements[2]);
        std::cout << "#tmp:\t" << relElem.num1 << " " << relElem.oper << " " << relElem.num2 << std::endl;
        tmp = elements[0] + " " + elements[1] + " " + elements[2] + " = ";

        elements[0] = std::to_string( basicOperatorFunction(relElem.num1, relElem.oper, relElem.num2) );
        elements.erase(elements.begin() +1, elements.begin() +3);   // Remove 2. and 3. element

        tmp += elements[0] + "\n";
        solution.append(tmp);
    }
    std::cout << "solution: " << solution << std::endl;
    return elements[0];
}


// Recursive
// 13 - 5 * 3
// ["13", "-", "5", "*", "3"]
double calculationHandler(std::vector<std::string> elements)
{
    // "BODMAS" / "PEMDAS"
    // 1. Brackets
    // 2. Exponents and roots
    // 3. Division
    // 4. Multiplication
    // 5. Subtraction
    // 6. Addition

    //std::cout << "#Test1: START" << std::endl;
    //std::cout << "Size = " << elements.size() << std::endl;

    for (int opIndex = 0; opIndex < sizeof(operators) +1; opIndex++)
    {
        //std::cout << "#Test2: FOR" << std::endl;
        int elemIndex = 0;
        while(elements.size() >= elemIndex +2)
        {
            //std::cout << "#Test3: WHILE" << std::endl;
            //std::cout << elements[elemIndex +1] << " : " << operators[opIndex] << std::endl;
            if(elements[elemIndex +1][0] == operators[opIndex])
            {

                //std::cout << "#Test4: IF" << std::endl;
                //std::cout << elements[elemIndex] << " " << elements[elemIndex +1] << " " << elements[elemIndex +2] << std::endl;
                //std::cout << stringToDouble(elements[elemIndex]) << " " << elements[elemIndex +1][0] << " " << stringToDouble(elements[elemIndex +2]) << " = ";
                //std::cout << basicOperatorFunction(stringToDouble(elements[elemIndex]), elements[elemIndex +1][0], stringToDouble(elements[elemIndex, +2]) ) << std::endl;
                elements[elemIndex] = std::to_string( basicOperatorFunction(stringToDouble( elements[elemIndex]), elements[elemIndex +1][0], stringToDouble(elements[elemIndex +2]) ));
                //std::cout << elements[elemIndex] << std::endl;

                //std::cout << elements[elemIndex] << std::endl;
                //vectorStrPrinter(elements);
                elements.erase(elements.begin() + elemIndex +1, elements.begin() + elemIndex +3);
                //vectorStrPrinter(elements);
            }
            else
            {
                elemIndex += 2;
            }
        }
    }
    return stringToDouble(elements[0]);
}
