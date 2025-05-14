#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) : AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	if (this != &other)
		_target = other._target;
	return *this;
}

void	PresidentialPardonForm::execute( const Bureaucrat& bureaucrat ) {
	if (this->getSigned() == false)
		throw FileNotSignedException();
	if (bureaucrat.getGrade() > this->getExecutingGrade())
		throw GradeTooLowException();
	
	std::cout << _target
			  << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;

}

std::ostream	&operator<<( std::ostream& out, const PresidentialPardonForm& PresidentialPardonForm ) {
	out << "Name: " << PresidentialPardonForm.getName() << std::endl
		<< "Boolean: " << PresidentialPardonForm.getSigned() << std::endl
		<< "Signing grade: " << PresidentialPardonForm.getSigningGrade() << std::endl
		<< "Executing grade: " << PresidentialPardonForm.getExecutingGrade() << std::endl;
	return out;
}
