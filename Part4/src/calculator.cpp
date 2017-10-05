#include "calculator.h"


void calcPrint()
{
    // User info.
    std::cout << "Input maths. Include space or enter between the elements!" << std::endl;
    std::cout << "number1 operator number2> ";

    // Convert and calculate.
    std::string strInput = getStringInput();
    strInput = removeStringSpaces(strInput);
    //std::vector<int> operIndexes = operatorIndexer(strInput);
    //std::vector<std::string> vectInput = splitStringByIndexVector(strInput, operIndexes);
    std::vector<std::string> altVectInput = stringToVector(strInput);
    double result = calculationHandler(altVectInput);

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


/// Alternative to splitStringByIndexVector() and operatorIndexer().
std::vector<std::string> stringToVector(std::string str)
{
    //std::cout << "#Test str: " << str << std::endl;
    //std::cout << "#Test str size: " << str.size() << std::endl;

    /// 2/3
    ///  2   /   3
    /// <n> <o> <n>

    /// 2*(4-5)+1
    ///  2   *   (   4   -   5   )   +   1
    /// <n> <o> <o> <n> <o> <n> <o> <o> <n>

    std::vector<std::string> elements;

    int flag = -1;
    /// Loop through chars in string.

    for(int strIndex = 0; strIndex < str.size() +1; strIndex++)
    {
        /// Loop through operator characters.
        //for(int opIndex = 0; opIndex < sizeof(operators); opIndex++)
        {
            /// If char in string is an operator character.
            if(charIsOper(str[strIndex]))
            {
                elements.push_back(str.substr(flag +1, strIndex-flag -1));  // Add number
                elements.push_back(str.substr(strIndex, 1));                // Add operator

                /// If next char is also an operator.
                if(charIsOper(str[strIndex +1]))
                {
                    elements.push_back(str.substr(strIndex +1, 1));    // Add operator
                    strIndex++;
                }
                else
                {

                }
                //std::cout << "#Test IF: " << str[strIndex] << std::endl;

                //std::cout << elements[elements.size() -1] << std::endl;
                //strIndex++;
                flag = strIndex;
            }
            /// Else char is not an operator
            else
            {
                // Do nothing?
                //std::cout << "#Test ELSE: " << str[strIndex] << std::endl;
            }
        }
    }
    /// Add last number to element.
    elements.push_back(str.substr(flag +1, sizeof(str)));
    std::cout << "#Test function complete" << std::endl;
    vectorStrPrinter(elements);
    return elements;
}




// Splits input string into string-vector
std::vector<std::string> splitStringByIndexVector(std::string inString, std::vector<int> operIndexes)
{
    std::vector<std::string> elements;

    int opIndex = 0;    // Index for the operIndexes list.
    int strPos = 0;     // Position in the inString.
    int nextOp = 0;     // The next (current) operator position in inString.
    int prevOp = 0;     // The previous operator position in inString.
    while(opIndex < operIndexes.size() +0)
    {
        nextOp = operIndexes[opIndex];
        //std::cout << "Start nextOp: " << nextOp << std::endl;
        /// Error with the string splitter (<num> <op> <num> <op> .. order should not be forces)
        /// 2*(4-5)+1 = -1
        ///   2     *    (    4     -    5     )    +    1
        /// <num> <op> <op> <num> <op> <num> <op> <op> <num>

        //if(inString[strPos])
        //std::cout << "nextOp: " << nextOp << ", prevOp: " << prevOp << std::endl;

        // If first is a charater (implying there are two chars in a row
        //if(isChar(inString[nextOp -1]) && isChar(inString[nextOp]))
        //if(nextOp - prevOp < 2)
        if(charIsOper(inString[nextOp -1]))
        {
            //std::cout << "#Test a1" << std::endl;
            // Do stuff
            elements.push_back(inString.substr( nextOp, 1 ));
            //std::cout << "#Test a2" << std::endl;
            //opIndex++;
            //vectorStrPrinter(elements);
        }
        else
        {
            //std::cout << "#Test b1" << std::endl;
            // Number
            elements.push_back(inString.substr(strPos, nextOp - prevOp));  // 0, nextOp
            //std::cout << "#Test b2" << std::endl;
            // Operator
            if (opIndex < operIndexes.size())
            {
                //std::cout << "#Test b3" << std::endl;
                elements.push_back(inString.substr( nextOp, 1 ));  // 4, 1
            }
            //vectorStrPrinter(elements);
        }

        // If last element in the list
        if(opIndex > operIndexes.size() -2)
        {
            //std::cout << "#Test c1" << std::endl;
            elements.push_back(inString.substr(strPos +1, sizeof(inString) -0));  // 0, nextOp
            std::cout << "inString substr: " << inString.substr(strPos +1, sizeof(inString) -0) << std::endl;
            std::cout << "Last element in elements: " << elements[elements.size() -1] << std::endl;
            //std::cout << "#Test c2" << std::endl;
        }

        //std::cout << "End of loop" << std::endl;

        strPos = nextOp +1;
        prevOp = nextOp +1;
        opIndex++;
    }
    //std::cout << "Loop finished" << std::endl;
    //vectorStrPrinter(elements);

    return elements;
}


// Check if char is an operator
bool charIsOper(char inChar)
{
    for (int opIndex = 0; opIndex < sizeof(operators); opIndex++)
    {
        if(inChar == operators[opIndex])
        {
            return true;
        }
    }
    return false;
}


// Find the indexes of the input string.
std::vector<int> operatorIndexer(std::string inString)
{
    std::vector<int> operIndexes;

    for (int strIndex = 0; strIndex < inString.size(); strIndex++)
    {
        if(charIsOper(inString[strIndex]))
        {
            operIndexes.push_back(strIndex);
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
    std::cout << "basicOpFunc: " << num1 << " " << oper << " " << num2 << std::endl;
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
    std::cout << "bracketedSubvectExtractor end: ";
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
        std::cout << "Brackets found" << std::endl;
        std::tuple<int, int> bracPos = bracketIndex(elements);
        //std::vector bracVect = bracketedSubvectExtractor(elements, bracPos[0], bracPos[1]);
        std::cout << "[0]: " << std::get<0>(bracPos) << ", [1]: " << std::get<1>(bracPos) << std::endl;
        std::vector<std::string> bracVect = bracketedSubvectExtractor(elements, std::get<0>(bracPos) +1, std::get<1>(bracPos) -1);
        elements[std::get<0>(bracPos)] = std::to_string(calculationHandler(bracVect));
        std::cout << "return from brackets: " << elements[std::get<0>(bracPos)] << std::endl;
        elements.erase(elements.begin() + std::get<0>(bracPos) +1, elements.begin() + (std::get<1>(bracPos) - std::get<0>(bracPos)) +4);
        vectorStrPrinter(elements);
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
                //if(elements[elemIndex][0] == '(' || elements[elemIndex +1][0] == '(' || elements[elemIndex +2][0] == '(')
                {

                }
                std::cout << "if char in while: ";
                vectorStrPrinter(elements);
                std::cout << elements[elemIndex +2] << std::endl;
                std::cout << "inputs: " << stringToDouble(elements[elemIndex]) << " " << elements[elemIndex +1][0] << " " << stringToDouble(elements[elemIndex +2]) << std::endl;
                elements[elemIndex] = std::to_string(basicOperatorFunction(stringToDouble(elements[elemIndex]), elements[elemIndex +1][0], stringToDouble(elements[elemIndex +2])));
                elements.erase(elements.begin() + elemIndex +1, elements.begin() + elemIndex +3);
                std::cout << "result: " << elements[elemIndex] << std::endl;
            }
            else
            {
                elemIndex += 2;
            }
        }
    }
    return stringToDouble(elements[0]);
}
