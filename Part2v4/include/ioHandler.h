#ifndef IOHANDLER_H
#define IOHANDLER_H


#include "globalDef.h"
#include "stringHandler.h"


#include <vector>


mathOpStr getUserInput();
void vectorPrinter(std::vector<int> vect);
void vectorStrPrinter(std::vector<std::string> vect);


class ioHandler
{
    public:
        ioHandler();
        virtual ~ioHandler();



    protected:

    private:
};

#endif // IOHANDLER_H
