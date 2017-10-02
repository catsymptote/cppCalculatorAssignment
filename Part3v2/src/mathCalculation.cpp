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
    return 0;
}


// This functions calculates based on order of operations.
double calculationHandler(std::vector<std::string> elements)
{
    for (int opIndex = 0; opIndex < sizeof(operators) +1; opIndex++)
    {
        int elemIndex = 0;
        while(elements.size() >= elemIndex +2)
        {
            if(elements[elemIndex +1][0] == operators[opIndex])
            {
                elements[elemIndex] = std::to_string(basicOperatorFunction(stringToDouble(elements[elemIndex]), elements[elemIndex +1][0], stringToDouble(elements[elemIndex +2])));
                elements.erase(elements.begin() + elemIndex +1, elements.begin() + elemIndex +3);
            }
            else
            {
                elemIndex += 2;
            }
        }
    }
    return stringToDouble(elements[0]);
}
