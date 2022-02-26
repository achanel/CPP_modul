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
void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << name << " sign " << form.getName()
			<< COLOR << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << name << " can't sign " << form.getName()
			<< COLOR << " because " << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << name << " execute " << form.getName()
			<< COLOR << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << name << " can't execute " << form.getName()
			<< COLOR << " because " << e.what() << '\n';
	}
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor Bureaucrat called\n";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << " Bureaucrat grade " << b.getGrade();
	return out;
}
