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
	if (bureaucrat.getGrade() < this->getExecutingGrade())
		throw GradeTooLowException();
	
	
}

AForm*	RobotomyRequestForm::clone() {
	return new RobotomyRequestForm(_target);
}

