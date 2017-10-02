#ifndef GLOBALDEF_H_INCLUDED
#define GLOBALDEF_H_INCLUDED


#include <string>


// Object of the two numbers and their operator.
struct mathOp {
    double  num1;
    char    oper;
    double  num2;
};


// Supported operators. Order is important for order of operations!!
const static char operators[] = {
    '^',    // 1 - Exponents
    '/',    // 2 - Division
    '%',    // 3 - Modulus
    '*',    // 4 - Multiplication
    '-',    // 5 - Subtraction
    '+'     // 6 - Addition
};


#endif // GLOBALDEF_H_INCLUDED
