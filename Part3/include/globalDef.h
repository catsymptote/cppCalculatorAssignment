#ifndef GLOBALDEF_H_INCLUDED
#define GLOBALDEF_H_INCLUDED


#include <string>


// Just three strings. Because reasons.
struct mathOpStr {
    std::string one;
    std::string two;
    std::string three;
};

// Object of the two numbers and their operator.
struct mathOp {
    double  num1;
    char    oper;
    double  num2;
};

// Supported operators. Order is important for order of operations!!
const static char operators[] = {
    '^',    // 1
    '/',    // 2
    '%',    // 3
    '*',    // 4
    '-',    // 5
    '+'     // 6
};


#endif // GLOBALDEF_H_INCLUDED
