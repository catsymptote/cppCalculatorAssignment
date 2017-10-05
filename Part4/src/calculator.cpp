#include "calculator.h"



/// /// "Interface" Functions /// ///

/// Get user input and print result.
void calcInputPrint()
{
    /// Get result.
    double result = calcInput();

    /// Print result.
    std::cout   //<< "\n--------------------------------------------------"
                //<< "--------------------------------------------------\n"
                << "= " << result
                << "\n--------------------------------------------------"
                << "--------------------------------------------------\n";

    /// Holding window open. (useful when not running in a loop)
    //std::cout << "Press any key to close ";
    //getch();
    //std::cout << "\n" << std::endl;
}

/// Get user input and return result.
double calcInput()
{
    /// User input
    std::cout << "> ";
    std::string strInput = getStringInput();

    return calcStr(strInput);
}

/// Get string and return result.
double calcStr(std::string strInput)
{
    /// Remove spaces.
    strInput = removeStringSpaces(strInput);


    /// If illegal
    if(charLegality(strInput))
    {
        std::cout << "----Invalid Input----" << std::endl;
        return -1;
    }
    // testyFunction(strInput)      // check rules, etc.
    // stringFormatter(strInput)    // 2( -> 2*(, and so on


    /// String to vector conversion.
    std::vector<std::string> vectInput = stringToVector(strInput);
    return calcVect(vectInput);
}

/// Get vector and return result.
double calcVect(std::vector<std::string> vectInput)
{
    return calculationHandler(vectInput);
}

/// Return true if string includes illegal characters.
bool charLegality(std::string str)
{
    bool illegal = false;
    for(int strIndex = 0; strIndex < str.length(); strIndex++)
    {
        illegal = true;
        for(int legalCharIndex = 0; legalCharIndex < sizeof(legalChars); legalCharIndex++)
        {
            if(str[strIndex] == legalChars[legalCharIndex])
            {
                illegal = false;
            }
        }
        if(illegal)
        {
            return true;
        }
    }
    return false;
}




/// /// IO Functions /// ///

/// Get input string.
std::string getStringInput()
{
    std::string inString;
    getline(std::cin, inString);
    return inString;
}

/// Print out int vector.
void vectorIntPrinter(std::vector<int> vect)
{
    std::cout << "Input:\t";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

/// Print out string vector.
void vectorStrPrinter(std::vector<std::string> vect)
{
    std::cout << "vector:\t";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

/// Debugging printer for string vector.
void debugVectorStrPrinter(std::vector<std::string> vect)
{
    std::cout << "debug: vector<string>:\t";
    for(int i = 0; i < vect.size(); i++)
    {
        std::cout << "<" << vect[i] << "> ";
    }
    std::cout << std::endl;
}



/// /// String -> Vector Conversion Functions /// ///

/// Remove spaces from the string.
std::string removeStringSpaces(std::string str)
{
    // Based on: https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
    str.erase(std::remove(str.begin(),str.end(),' '),str.end());
    return str;
}


/// Alternative (new) to splitStringByIndexVector() and operatorIndexer().
std::vector<std::string> stringToVector(std::string str)
{
    std::vector<std::string> elements;

    int flag = -1;
    /// Loop through chars in string.
    for(int strIndex = 0; strIndex < str.size() +1; strIndex++)
    {
        /// If char in string is an operator character.
        if(charIsOper(str[strIndex]))
        {
            elements.push_back(str.substr(flag +1, strIndex-flag -1));  /// Add number
            elements.push_back(str.substr(strIndex, 1));                /// Add operator

            /// While next char is also an operator (when multiple operators in a row).
            while(charIsOper(str[strIndex +1]))
            {
                elements.push_back(str.substr(strIndex +1, 1));    /// Add operator
                strIndex++;
            }
            flag = strIndex;
        }
    }
    /// Add last number to element.
    elements.push_back(str.substr(flag +1, str.length()));
    return elements;
}


/// Splits input string into string-vector (old)
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
        if(charIsOper(inString[nextOp -1]))
        {
            /// Operator
            elements.push_back(inString.substr( nextOp, 1 ));
        }
        else
        {
            /// Number
            elements.push_back(inString.substr(strPos, nextOp - prevOp));
            /// Operator
            if (opIndex < operIndexes.size())
            {
                elements.push_back(inString.substr( nextOp, 1 ));
            }
        }

        /// If last element in the list
        if(opIndex > operIndexes.size() -2)
        {
            elements.push_back(inString.substr(strPos +1, sizeof(inString) -0));
        }
        strPos = nextOp +1;
        prevOp = nextOp +1;
        opIndex++;
    }
    return elements;
}

/// Find the indexes of the input string. (old)
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

/// Check if char is an operator
bool charIsOper(char inChar)
{
    for (int opIndex = 0; opIndex < sizeof(operatorsAndBrackets); opIndex++)
    {
        if(inChar == operatorsAndBrackets[opIndex])
        {
            return true;
        }
    }
    return false;
}

/// Convert string to double.
double stringToDouble(std::string str)
{
    char chr[1024];
    strcpy(chr, str.c_str());
    return atof(chr);
}



/// /// Maths Functions /// ///

/// Run two numbered calculations with basic operations.
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
            if(num2 != 0)
            {
                return (num1 / num2);
            }
            else
            {
                std::cout << "\nDividing by 0 is naughty ;P" << std::endl;
                return 0;
            }
        case '%':
            if(num2 != 0)
            {
                return (fmod(num1, num2));
            }
            else
            {
                std::cout << "\nDividing by 0 is naughty ;P" << std::endl;
                return 0;
            }
        case '^':
            if(!(num1 == 0 && num2 == 0))
            {
                return (pow(num1, num2));
            }
            else
            {
                std::cout << "\n0^0 is undefined. Google it." << std::endl;
                return 0;
            }
        default:
            std::cout   << "Error. Operator " << oper
                        << " not recognized"  << std::endl;
            break;
    }
    return 0;
}

/// Finds if there is an beginning bracket in the string
bool bracketStartStringFinder(std::string str)
{
    for(int strIndex = 0; strIndex < str.size(); strIndex++)
    {
        if  (   /// If char is a start bracket
               str[strIndex] == '('
            || str[strIndex] == '['
            || str[strIndex] == '{'
            )
        {
            return true;
        }
    }
    return false;   /// No brackets found in string
}

/// Finds if there is an ending bracket in the string
bool bracketStopStringFinder(std::string str)
{
    for(int strIndex = 0; strIndex < str.size(); strIndex++)
    {
        if  (   /// If char is an end bracket
               str[strIndex] == ')'
            || str[strIndex] == ']'
            || str[strIndex] == '}'
            )
        {
            return true;
        }
    }
    return false;   /// No brackets found in string
}

/// Returns true if the vector of strings has a bracket in it
bool bracketVectFinder(std::vector<std::string> elements)
{
    for(int vectIndex = 0; vectIndex < elements.size(); vectIndex++)
    {
        if(bracketStartStringFinder(elements[vectIndex]) || bracketStopStringFinder(elements[vectIndex]))
        {
            return true;
        }
    }
    return false;   /// No brackets found in vector
}

/// Find the index of the first and its belonging brackets
std::tuple<int, int> bracketIndex(std::vector<std::string> elements)
{
    int start = 0;
    int stop = 0;
    int bracCount = 0;
    for(int vectIndex = 0; vectIndex < elements.size(); vectIndex++)
    {
        /// If there are brackets in the string
        if(bracketStartStringFinder(elements[vectIndex]))
        {
            //std::cout << "#IF" << std::endl;
            if(bracCount == 0)
            {
                start = vectIndex;
            }
            bracCount++;
        }
        /// If there are no brackets in the string
        else if(bracketStopStringFinder(elements[vectIndex]))
        {
            if(bracCount == 1)
            {
                stop = vectIndex;
            }
            bracCount--;
        }
    }
    std::tuple<int, int> vectPos (start, stop +1);
    return vectPos;
}

/// Get subvector
std::vector<std::string> bracketedSubvectExtractor(std::vector<std::string> elements, int start, int stop)
{
    std::vector<std::string> subVect;
    for(int vectIndex = start; vectIndex < stop; vectIndex++)
    {
        subVect.push_back(elements[vectIndex]);
    }
    return subVect;
}

/// This functions calculates based on order of operations, and calculates bracketed parts recursively.
double calculationHandler(std::vector<std::string> elements)
{
    if(bracketVectFinder(elements))
    {
        std::tuple<int, int> bracPos = bracketIndex(elements);
        std::vector<std::string> bracVect = bracketedSubvectExtractor(elements, std::get<0>(bracPos) +1, std::get<1>(bracPos) -1);
        elements[std::get<0>(bracPos)] = std::to_string(calculationHandler(bracVect));
        int start   = std::get<0>(bracPos) +1;
        int stop    = std::get<1>(bracPos);
        elements.erase(elements.begin() + start,     elements.begin() + stop);
    }
    for (int opIndex = 0; opIndex < sizeof(operators) +1; opIndex++)
    {
        int elemIndex = 0;
        while(elements.size() >= elemIndex +2)
        {
            /// If acceptable operator
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
