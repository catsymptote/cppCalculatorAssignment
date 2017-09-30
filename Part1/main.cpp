#include <iostream>
#include <conio.h> //for getch()


double operatorFunction(double num1, double num2, char oper);


int main()
{
    // Number 1
    std::cout << "Number 1> ";
    double num1;
    std::cin >> num1;

    // Operator
    std::cout << "Operator> ";
    char oper;
    std::cin >> oper;

    // Number 2
    std::cout << "Number 2> ";
    double num2;
    std::cin >> num2;

    // Print solution
    std::cout << "Input:\t" << num1 << " " << oper << " " << num2 << std::endl;
    std::cout << "Result:\t" << operatorFunction(num1, num2, oper) << std::endl;

    // Holding window open
    std::cout << "Press any key to close ";
    getch();

    return 0;
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
            return -1;
    }
}
