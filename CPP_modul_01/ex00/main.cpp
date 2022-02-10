#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	randomChump("IVAN ");
	delete newZombie("OLEG ");
	return (0);
}