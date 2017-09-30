#include <iostream>

double operatorFunction(double num1, double num2, char oper);


int main()
{
    std::cout << "Number 1> ";
    double num1;   // Number 1
    std::cin >> num1;

    std::cout << "Operator> ";
    char oper;  // Operator
    std::cin >> oper;

    std::cout << "Number 2> ";
    double num2;   // Number 2
    std::cin >> num2;

    std::cout << "Input:\t" << num1 << " " << oper << " " << num2 << std::endl;
    std::cout << "Result:\t" << operatorFunction(num1, num2, oper) << std::endl;

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
