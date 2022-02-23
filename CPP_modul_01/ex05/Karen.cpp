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
    std::cout << "\033[0;34mDEBUG\033[0m\n";
}

void    Karen::info( void )
{
    std::cout << "\033[0;32mINFO\033[0m\n";
}

void    Karen::warning( void )
{
    std::cout << "\033[1;33mWARNING\033[0m\n";
}

void    Karen::error( void )
{
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
	switch (i)
	{
		case 0:
			(this->*debugPtr)();
			break;
		case 1:
			(this->*infoPtr)();
			break;
		case 2:
			(this->*warningPtr)();
			break;
		case 3:
			(this->*errorPtr)();
			break;
		default:
			std::cout << "Error: Wrong level!\n";
			break;
	}
}