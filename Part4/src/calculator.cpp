#include "calculator.h"



/// /// "Interface" Functions /// ///

/// Get user input and print result.
void calcInputPrint()
{
    /// Get result.
    long double result = calcInput();

    /// Print result.
    std::cout   << "= " << result
                << "\n--------------------------------------------------\n";

    /// Holding window open (useful when not running in a loop) (Windows builds only?).
    //std::cout << "Press any key to close ";
    //getch();
    //std::cout << "\n" << std::endl;
}

/// Get user input and return result.
long double calcInput()
{
    /// User input
    std::cout << "> ";
    std::string strInput = getStringInput();

    return calcStr(strInput);
}

/// Get string and return result.
long double calcStr(std::string strInput)
{
    /// Remove spaces.
    strInput = removeStringSpaces(strInput);

    /// If illegal
    if(!charLegality(strInput))
    {
        std::cout << "----Invalid Input: Illegal characters used----" << std::endl;
        return -1;
    }
    if(!bracketLegality(strInput))
    {
        std::cout << "----Invalid Input: Illegal use of brackets----" << std::endl;
        return -1;
    }

    /// String to vector conversion.
    std::vector<std::string> vectInput = stringToVector(strInput);
    return calcVect(vectInput);
}

/// Get vector and return result.
long double calcVect(std::vector<std::string> vectInput)
{
    return calculationHandler(vectInput);
}



/// /// Legality Check Functions /// ///

/// Return false if string includes illegal characters.
bool charLegality(std::string str)
{
    bool legal = true;
    for(int strIndex = 0; strIndex < str.length(); strIndex++)
    {
        legal = false;
        for(int legalCharIndex = 0; legalCharIndex < sizeof(legalChars); legalCharIndex++)
        {
            if(str[strIndex] == legalChars[legalCharIndex])
            {
                legal = true;
            }
        }
        if(!legal)
        {
            return false;
        }
    }
    return legal;
}

/// Return false if string includes illegal use of brackets.
bool bracketLegality(std::string str)
{
    /// Check if the string starts or ends with a bracket.
    if(str[0] == '(' || str[0] == '[' || str[0] == '{')
    {
        return false;
    }
    if(str[str.length() -1] == ')' || str[str.length() -1] == ']' || str[str.length() -1] == '}')
    {
        return false;
    }

    /// Test if there are the same amount of start and ending brackets
    int startBracketCounter = 0;
    int endBracketCounter = 0;
    for(int strIndex = 0; strIndex < str.length(); strIndex++)
    {
        if(str[strIndex] == '(' || str[strIndex] == '[' || str[strIndex] == '{')
        {
            startBracketCounter++;
        }
        else if(str[strIndex] == ')' || str[strIndex] == ']' || str[strIndex] == '}')
        {
            endBracketCounter++;
        }
    }
    if(startBracketCounter != endBracketCounter)
    {
        return false;
    }

    /// Test if two brackets after each other (( or ))
    for(int strIndex = 1; strIndex < str.length() -1; strIndex++)
    {
        if(str[strIndex] == '(' || str[strIndex] == '[' || str[strIndex] == '{')
        {
            if(str[strIndex -1] == '(' || str[strIndex -1] == '[' || str[strIndex -1] == '{')
            {
                return false;
            }
        }
        if(str[strIndex] == ')' || str[strIndex] == ']' || str[strIndex] == '}')
        {
            if(str[strIndex +1] == ')' || str[strIndex +1] == ']' || str[strIndex +1] == '}')
            {
                return false;
            }
        }
    }

    return true;    // No rule breaks found.
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
    str.erase(std::remove(str.begin(), str.end(),' '), str.end());
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

/// Convert string to long double.
long double stringToDouble(std::string str)
{
    //char chr[1024];
    //strcpy(chr, str.c_str());
    //return atof(chr);
    return std::stold(str);
}

std::string doubleToString()
{
    return std::to_string(1);
}

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 256)
{
    // Taken from: https://stackoverflow.com/questions/16605967/set-precision-of-stdto-string-when-converting-floating-point-values
    std::ostringstream out;
    out << std::setprecision(n) << a_value;
    return out.str();
}



/// /// Maths Functions /// ///

/// Run two numbered calculations with basic operations.
long double basicOperatorFunction(long double num1, char oper, long double num2)
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
long double calculationHandler(std::vector<std::string> elements)
{
    bool numBeforeBracket, numAfterBracket;
    std::vector<std::string>::iterator it;

    while(bracketVectFinder(elements))
    {
        std::tuple<int, int> bracPos = bracketIndex(elements);
        int start   = std::get<0>(bracPos) +1;
        int stop    = std::get<1>(bracPos) -1;
        std::vector<std::string> bracVect = bracketedSubvectExtractor(elements, start, stop);
        elements[std::get<0>(bracPos)] = std::to_string(calculationHandler(bracVect));

        // Checks whether to add * before and/or after bracket when num()num instead of num*()*num.
        numBeforeBracket   = false;
        numAfterBracket    = false;
        if(!charIsOper(elements[start -2][0]))
        {
            numBeforeBracket = true;
        }
        if(!charIsOper(elements[stop +1][0]))
        {
            numAfterBracket = true;
        }

        // Delets the bracketed part
        elements.erase(elements.begin() + start, elements.begin() + stop +1);

        // Adds the * before/after bracketed part.
        if(numBeforeBracket)
        {
            it = elements.insert(elements.begin() + start -1, "*");
        }
        if(numAfterBracket)
        {
            it = elements.insert(elements.begin() + start +1, "*");
        }
    }

    for (int opIndex = 0; opIndex < sizeof(operators) +1; opIndex++)
    {
        int elemIndex = 0;
        while(elements.size() >= elemIndex +2)
        {
            /// If acceptable operator
            if(elements[elemIndex +1][0] == operators[opIndex])
            {
                std::cout.precision(20);
                elements[elemIndex] = to_string_with_precision(basicOperatorFunction(stringToDouble(elements[elemIndex]), elements[elemIndex +1][0], stringToDouble(elements[elemIndex +2])));
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
