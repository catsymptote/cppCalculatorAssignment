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


// This function calculates from left to right, similarly to a simple calculator.
// This means, it does not follow order of operations.
double ltrCalculationHandler(std::vector<std::string> elements)
{
    std::string solution;
    std::string tmp;
    double num1;
    while (elements.size() >= 3)
    {
        mathOp relElem = stringConverter(elements[0], elements[1], elements[2]);
        tmp = elements[0] + " " + elements[1] + " " + elements[2] + " = ";

        elements[0] = std::to_string( basicOperatorFunction(relElem.num1, relElem.oper, relElem.num2) );
        elements.erase(elements.begin() +1, elements.begin() +3);   // Remove 2. and 3. element

        tmp += elements[0] + "\n";
        solution.append(tmp);
    }
    ///std::cout << "solution: " << solution << std::endl;
    return stringToDouble(elements[0]);
}
