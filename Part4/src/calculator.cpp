#include "calculator.h"


void calcPrint()
{
    // User info.
    std::cout << "Input maths. Include space or enter between the elements!" << std::endl;
    std::cout << "number1 operator number2> ";

    // Convert and calculate.
    std::string strInput = getStringInput();
    strInput = removeStringSpaces(strInput);
    std::vector<int> operIndexes = operatorIndexer(strInput);
    std::vector<std::string> vectInput = splitStringByIndexVector(strInput, operIndexes);
    double result = calculationHandler(vectInput);

    // Print input and result.
    std::cout   << "\n--------------------------------------------------\n";
    //vectorStrPrinter(vectInput);
    std::cout   << "= " << result
                << "\n--------------------------------------------------\n";

    // Holding window open.
    std::cout << "Press any key to close ";
    getch();
    std::cout << "\n" << std::endl;
}


double calcStr(std::string strInput)
{
    strInput = removeStringSpaces(strInput);
    std::vector<int> operIndexes = operatorIndexer(strInput);
    std::vector<std::string> vectInput = splitStringByIndexVector(strInput, operIndexes);
    return calculationHandler(vectInput);
}


double calcVect(std::vector<std::string> vectInput)
{
    return calculationHandler(vectInput);
}


std::string getStringInput()
{
    std::string inString;
    getline(std::cin, inString);
    return inString;
}


// Print out the vectors. What is templates even :P
void vectorIntPrinter(std::vector<int> vect)
{
    std::cout << "Input:\t";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

void vectorStrPrinter(std::vector<std::string> vect)
{
    std::cout << "Input:\t";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << "<" << vect[i] << "> ";
    }
    std::cout << std::endl;
}





// Remove spaces from the string.
std::string removeStringSpaces(std::string str)
{
    // Based on: https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
    str.erase(std::remove(str.begin(),str.end(),' '),str.end());
    return str;
}


// Splits input string into string-vector
std::vector<std::string> splitStringByIndexVector(std::string inString, std::vector<int> operIndexes)
{
    std::vector<std::string> elements;

    int opIndex = 0;
    int strPos = 0;
    int nextOp = 0;
    int prevOp = 0;
    while(opIndex < operIndexes.size() +1)
    {
        nextOp = operIndexes[opIndex];
        /// Error with the string splitter (<num> <op> <num> <op> .. order should not be forces)
        //if(inString[strPos])
        // Number
        elements.push_back(inString.substr( strPos, nextOp - prevOp ));  // 0, nextOp

        // Operator
        if (opIndex < operIndexes.size())
        {
            elements.push_back(inString.substr( nextOp, 1 ));  // 4, 1
        }

        strPos = nextOp +1;
        prevOp = nextOp +1;
        opIndex++;
    }

    return elements;
}


// Find the indexes of the input string.
std::vector<int> operatorIndexer(std::string inString)
{
    std::vector<int> operIndexes;

    for (int strIndex = 0; strIndex < inString.size(); strIndex++)
    {
        for (int opIndex = 0; opIndex < sizeof(operators); opIndex++)
        {
            if(inString[strIndex] == operators[opIndex])
            {
                operIndexes.push_back(strIndex);
            }
        }
    }
    return operIndexes;
}


// Convert a type std::string to a type double.
double stringToDouble(std::string str)
{
    char chr[1024];
    strcpy(chr, str.c_str());
    return atof(chr);
}






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


// Finds if there is an beginning bracket in the string
bool bracketStartStringFinder(std::string str)
{
    for(int strIndex = 0; strIndex < sizeof(str); strIndex++)
    {
        if  (   // If char is a bracket
               str[strIndex] == '('
            || str[strIndex] == '['
            || str[strIndex] == '{'
            )
        {
            return true;
        }
    }
    return false;   // No brackets found in string
}


// Finds if there is an ending bracket in the string
bool bracketStopStringFinder(std::string str)
{
    for(int strIndex = 0; strIndex < sizeof(str); strIndex++)
    {
        if  (   // If char is a bracket
               str[strIndex] == ')'
            || str[strIndex] == ']'
            || str[strIndex] == '}'
            )
        {
            return true;
        }
    }
    return false;   // No brackets found in string
}


// Returns true if the vector of strings has a bracket in it
bool bracketVectFinder(std::vector<std::string> elements)
{
    for(int vectIndex = 0; vectIndex < elements.size(); vectIndex++)
    {
        if(bracketStartStringFinder(elements[vectIndex]) || bracketStopStringFinder(elements[vectIndex]))
        {
            return true;
        }
    }
    return false;   // No brackets found in vector
}


// Find the index of the first outer most brackets
std::tuple<int, int> bracketIndex(std::vector<std::string> elements)
{
    int start = 0;
    int stop = 0;
    int bracCount = 0;
    for(int vectIndex = 0; vectIndex < elements.size(); vectIndex++)
    {
        // If there are brackets in the string
        if(bracketStartStringFinder(elements[vectIndex]))
        {
            if(bracCount == 0)
            {
                start = vectIndex;
            }
            bracCount++;
        }
        // If there are no brackets in the string
        else if(bracketStopStringFinder(elements[vectIndex]))
        {
            if(bracCount == +1)
            {
                stop = vectIndex;
            }
            bracCount--;
        }
    }
    std::tuple<int, int> vectPos (start, stop +1);
    return vectPos;
}


// Get subvector
std::vector<std::string> bracketedSubvectExtractor(std::vector<std::string> elements, int start, int stop)
{
    vectorStrPrinter(elements);
    std::cout << "start: " << start << ", stop: " << stop << std::endl;

    std::vector<std::string> subVect;
    for(int vectIndex = start; vectIndex < stop; vectIndex++)
    {
        std::cout << vectIndex << " : " << elements[vectIndex] << std::endl;
        subVect.push_back(elements[vectIndex]);
    }
    vectorStrPrinter(subVect);
    return subVect;
}


// This functions calculates based on order of operations.
double calculationHandler(std::vector<std::string> elements)
{
    //std::cout << "#Test 1" << std::endl;
    vectorStrPrinter(elements);
    // If vector has brackets
    if(bracketVectFinder(elements))
    {
        std::tuple<int, int> bracPos = bracketIndex(elements);
        //std::vector bracVect = bracketedSubvectExtractor(elements, bracPos[0], bracPos[1]);
        std::cout << "[0]: " << std::get<0>(bracPos) << ", [1]: " << std::get<1>(bracPos) << std::endl;
        std::vector<std::string> bracVect = bracketedSubvectExtractor(elements, std::get<0>(bracPos) +1, std::get<1>(bracPos) -1);
        elements[std::get<0>(bracPos)] = std::to_string(calculationHandler(bracVect));
        std::cout << elements[std::get<0>(bracPos)] << std::endl;
        elements.erase(elements.begin() + std::get<0>(bracPos), elements.begin() + (std::get<1>(bracPos) - std::get<0>(bracPos)) +3);
    }
    //std::cout << "#Test 2" << std::endl;
    vectorStrPrinter(elements);
    for (int opIndex = 0; opIndex < sizeof(operators) +1; opIndex++)
    {
        int elemIndex = 0;
        while(elements.size() >= elemIndex +2)
        {
            // If acceptable operator
            if(elements[elemIndex +1][0] == operators[opIndex])
            {
                // If bracket start
                if(elements[elemIndex][0] == '(' || elements[elemIndex +1][0] == '(' || elements[elemIndex +2][0] == '(')
                {

                }
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
