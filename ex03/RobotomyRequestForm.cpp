#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) : AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	if (this != &other)
		_target = other._target;
	return *this;
}

bool	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	try {
		if (this->getSigned() == false)
			throw AForm::FileNotSignedException();
		if (executor.getGrade() > this->getExecutingGrade())
			throw Bureaucrat::GradeTooLowException();
		
		std::cout << "* Dzzzzzzzzzzzzzzzzz ! *" << std::endl;

		std::srand(std::time(NULL));
		if (std::rand() % 2 == 0) {
			std::cout << _target << ": has been robotomized successfully!" << std::endl;
			return true;
		}
		else {
			std::cout << _target << ": robotomy failed..." << std::endl;
			return false;
		}
	} catch (const AForm::FileNotSignedException &e) {
		std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
	}
	return false;
}

std::ostream	&operator<<( std::ostream& out, const RobotomyRequestForm& RobotomyRequestForm ) {
	out << "Name of the form: " << RobotomyRequestForm.getName() << std::endl
		<< "Is it signed: " << RobotomyRequestForm.getSigned() << std::endl
		<< "Signing grade: " << RobotomyRequestForm.getSigningGrade() << std::endl
		<< "Executing grade: " << RobotomyRequestForm.getExecutingGrade() << std::endl;
	return out;
}
