#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	try {
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		else
			_grade = grade;
	} catch (std::exception & e) {
		std::cerr << "Grade error caught in constructor: " << e.what() << std::endl;
		_grade = 150;
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other._name), _grade(other._grade) {}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat& other ) {
	(void)other;
	std::cerr << "Cannot assign Bureaucrats" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string	&Bureaucrat::getName() const { return _name; }

int	Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::incrementGrade( int grade ) {
	try {
		grade--;
		if (grade < 1)
			throw GradeTooHighException();
		else
			_grade = grade;
	} catch (std::exception & e) {
		std::cerr << "Grade error caught in increment function: " << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade( int grade ) {
	try {
		grade++;
		if (grade > 150)
			throw GradeTooLowException();
		else
			_grade = grade;
	} catch (std::exception & e) {
		std::cerr << "Grade error caught in decrement function: " << e.what() << std::endl;
	}
}

std::ostream	&operator<<( std::ostream& out, const Bureaucrat bureaucrat ) {
	out << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< "."
		<< std::endl;
	return out;
}
