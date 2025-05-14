#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : 
	_name(other._name), 
	_grade(other._grade) {}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other)
        _grade = other._grade;
	std::cerr << "Cannot assign Bureaucrats" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string	&Bureaucrat::getName() const { return _name; }

int	Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm( AForm &form ) const {
	try {
		form.beSigned(*this);
		std::cout << _name
				  << " signed "
				  << form.getName()
				  << "."
				  << std::endl;
	} catch (std::exception& e) {
		std::cout << _name
				  << " couldn't sign "
				  << form.getName()
				  << " because "
				  << e.what()
				  << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm &form ) const {
	form.execute(*this);
}

std::ostream	&operator<<( std::ostream& out, const Bureaucrat &bureaucrat ) {
	out << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< ".";
	return out;
}
