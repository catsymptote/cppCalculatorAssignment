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

// Supported operators.
const static char operators[] = {
    '+', '-', '*', '/'
};


#endif // GLOBALDEF_H_INCLUDED
