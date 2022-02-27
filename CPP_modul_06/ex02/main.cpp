#include <iostream>
# define COLOR "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
using namespace std;

class Base
{
public:
	virtual ~Base() {};
};

class A : public Base
{
public:
	virtual ~A() {};
};

class B : public Base
{
public:
	virtual ~B() {};
};

class C : public Base
{
public:
	virtual ~C() {};
};

Base * generate(void)
{
	Base	*base = NULL;
	srand(time(NULL));
	switch (rand() % 3)
	{
	case 0:
		base = new A;
		break;
	case 1:
		base = new B;
		break;
	case 2:
		base = new C;
		break;
	}
	return base;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		cout << YELLOW << "A\n" << COLOR;
	else if (dynamic_cast<B*>(p))
		cout << YELLOW << "B\n" << COLOR;
	else if (dynamic_cast<C*>(p))
		cout << YELLOW << "C\n" << COLOR;
	else
		cout << RED << "Bad cast\n" << COLOR;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		cout << YELLOW << "A\n" << COLOR;
	}
	catch(bad_cast) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		cout << YELLOW << "B\n" << COLOR;
	}
	catch(bad_cast) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		cout << YELLOW << "C\n" << COLOR;
	}
	catch(bad_cast) {}
}

int	main(void)
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}