#include "Zombie.hpp"

int main(void)
{
    Zombie *pointer = zombieHorde(10, "Zombie ");
    for (int i = 0; i < 10; i++)
        pointer[i].announce();
    delete [] pointer;
}