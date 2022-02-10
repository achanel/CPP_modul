#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0 || N > 2147483647)
    {
        std::cout << "ERROR: Bad number, try again!\n";
        exit(1);
    }
    Zombie* horde = new Zombie[N];
    for(int i = 0; i < N; i++)
    {
        if (i > 0)
            name = "Zombie ";
        name += std::to_string(i + 1);
        horde[i].setName(name);
    }
    return (horde);
}