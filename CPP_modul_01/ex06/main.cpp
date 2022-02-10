#include "Karen.hpp"

int main(int ac, char **av)
{
    Karen   karen;

    if (ac == 1)
        std::cout << "Error: No Arguments!\n";
    else if (strcmp(av[1], "DEBUG") == 0)
    {
        karen.complain("debug");
        karen.complain("info");
        karen.complain("warning");
        karen.complain("error");
    }
    else if (strcmp(av[1], "INFO") == 0)
    {
        karen.complain("info");
        karen.complain("warning");
        karen.complain("error");
    }
    else if (strcmp(av[1], "WARNING") == 0)
    {
        karen.complain("warning");
        karen.complain("error");
    }
    else if (strcmp(av[1], "ERROR") == 0)
        karen.complain("error");
    else
        std::cout << "Error: Bad Arguments!\n";
    return 0;
}