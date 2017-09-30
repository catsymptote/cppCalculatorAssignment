#include <iostream>
#include <conio.h>  // for getch()
#include <stdlib.h> // for string -> double conversion
#include <cstdlib>
#include <stdio.h>
#include <string.h>


struct mathOp {
    double  num1;
    char    oper;
    double  num2;
};


mathOp stringHandler(std::string inNum1, std::string inNum2, std::string inOper);
double operatorFunction(double num1, double num2, char oper);


int main()
{
    // Get maths from user
    std::cout << "Input maths. Include space or enter between the elements!" << std::endl;
    std::string inNum1, inOper, inNum2;
    std::cout << "number1 operator number2> ";
    std::cin >> inNum1 >> inOper >> inNum2;

    // Print solution
    std::cout << inNum1 << " " << inOper << " " << inNum2 << std::endl;

    mathOp cookie = stringHandler(inNum1, inNum2, inOper);
    std::cout << "Input:\t" << cookie.num1 << " " << cookie.oper << " " << cookie.num2 << std::endl;
    std::cout << "Result:\t" << operatorFunction(cookie.num1, cookie.num2, cookie.oper) << std::endl;

    // Holding window open
    std::cout << "Press any key to close ";
    getch();

    return 0;
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
