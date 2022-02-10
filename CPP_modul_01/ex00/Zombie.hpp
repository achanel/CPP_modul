#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Zombie
{
private:
	std::string	name;
public:
	Zombie	(std::string name);
	void	announce( void );
	~Zombie();
};


#endif