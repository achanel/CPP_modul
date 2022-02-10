#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
	std::string	weapon;
public:
	Weapon(std::string str);
	const std::string   &getType(void);
    void    setType(std::string str);
	~Weapon();
};


#endif