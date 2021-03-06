#include "Karen.hpp"

Karen::Karen(void)
{
    this->debugPtr = &Karen::debug;
    this->infoPtr = &Karen::info;
    this->warningPtr = &Karen::warning;
    this->errorPtr = &Karen::error;
}

void    Karen::debug( void )
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "\033[0;34mDEBUG\033[0m\n";
}

void    Karen::info( void )
{
    std::cout << "[ INFO ]\n";
    std::cout << "\033[0;32mINFO\033[0m\n";
}

void    Karen::warning( void )
{
    std::cout << "[ WARNING ]\n";
    std::cout << "\033[1;33mWARNING\033[0m\n";
}

void    Karen::error( void )
{
    std::cout << "[ ERROR ]\n";
    std::cout << "\033[0;31mERROR\033[0m\n";
}

void Karen::complain( std::string level )
{
    std::string lvl[4] = {"debug", "info", "warning", "error"};

    int i = 0;
    while(i < 4)
    {
        if (level == lvl[i])
            break;
        i++;
    }
    if (i == 0)
        (this->*debugPtr)();
    else if (i == 1)
        (this->*infoPtr)();
    else if (i == 2)
        (this->*warningPtr)();
    else if (i == 3)
        (this->*errorPtr)();
    else
        std::cout << "Error: Wrong level!\n";
}