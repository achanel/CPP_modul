#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	name = "Unknown";
	grade = 150;
	std::cout << "Default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string Name, int Grade)
{
	name = Name;
	grade = Grade;
	std::cout << "Constructor name = " << name << " with grade = " << grade << std::endl;
	if (this->grade > 150)
		throw GradeTooLowException();
	else if (this->grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	this->name = copy.name;
	this->grade = copy.grade;
	std::cout << "Copy constructor called\n";
}

Bureaucrat&  Bureaucrat::operator= (const Bureaucrat &other)
{
	std::cout << "Assignation operator called\n";
	this->grade = other.getGrade();
	return *this;
}

void	Bureaucrat::setGrade(int Grade)
{
	this->grade = Grade;
}

unsigned int	Bureaucrat::getGrade() const
{
	return this->grade;
}

std::string	Bureaucrat::getName() const
{
	return this->name;
}

Bureaucrat &Bureaucrat::operator++()
{
	if (--grade < 1)
		throw GradeTooHighException();
	return *this;
}

Bureaucrat &Bureaucrat::operator--()
{
	if (++grade > 150)
		throw GradeTooLowException();
	return *this;	
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too hight!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::string	Bureaucrat::signForm(bool isSigned, std::string name)
{
	if (isSigned)
		return "Bureaucrat " + this->name + " signed form " + name;
	else
		return "Bureaucrat " + this->name + " can't signed form " + name + " because ";
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called\n";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << "<" << b.getName() << ">, Bureaucrat grade " << b.getGrade();
	return out;
}
