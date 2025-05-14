#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) : AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	if (this != &other)
		_target = other._target;
	return *this;
}

void	RobotomyRequestForm::execute( const Bureaucrat& bureaucrat ) {
	if (this->getSigned() == false)
		throw FileNotSignedException();
	if (bureaucrat.getGrade() > this->getExecutingGrade())
		throw GradeTooLowException();
	
	std::cout << "Dzzzzzzzzzzzzzzzzz !" << std::endl;

	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << _target << ": has been robotomized successfully!" << std::endl;
	else
		std::cout << _target << ": robotomy failed..." << std::endl;

}

std::ostream	&operator<<( std::ostream& out, const RobotomyRequestForm& RobotomyRequestForm ) {
	out << "Name: " << RobotomyRequestForm.getName() << std::endl
		<< "Boolean: " << RobotomyRequestForm.getSigned() << std::endl
		<< "Signing grade: " << RobotomyRequestForm.getSigningGrade() << std::endl
		<< "Executing grade: " << RobotomyRequestForm.getExecutingGrade() << std::endl;
	return out;
}
