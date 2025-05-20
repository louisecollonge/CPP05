#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) : AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	if (this != &other)
		_target = other._target;
	return *this;
}

bool	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	try {
		if (this->getSigned() == false)
			throw AForm::FileNotSignedException();
		if (executor.getGrade() > this->getExecutingGrade())
			throw Bureaucrat::GradeTooLowException();
		else {
			std::cout << _target
					<< " has been pardoned by Zaphod Beeblebrox."
					<< std::endl;
			return true;
		}
	} catch (const AForm::FileNotSignedException &e) {
		std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
	}
	return false;
}

std::ostream	&operator<<( std::ostream& out, const PresidentialPardonForm& PresidentialPardonForm ) {
	out << "Name of the file: " << PresidentialPardonForm.getName() << std::endl
		<< "Is it signed: " << PresidentialPardonForm.getSigned() << std::endl
		<< "Signing grade: " << PresidentialPardonForm.getSigningGrade() << std::endl
		<< "Executing grade: " << PresidentialPardonForm.getExecutingGrade() << std::endl;
	return out;
}
