#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

class Karen
{
private:
    typedef void    (Karen::*fptr)(void);

	void    debug( void );
	void    info( void );
	void    warning( void );
    void    error( void );
public:
    Karen();

    fptr debugPtr;
    fptr infoPtr;
    fptr warningPtr;
    fptr errorPtr;

    void complain( std::string level );
};


#endif