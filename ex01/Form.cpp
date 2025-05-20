#include "Form.hpp"

//__________________Canonical Form__________________//

Form::Form( const std::string name, const int signingGrade, const int executingGrade ) :
	_name (name) ,
	_signed (false),
	_signingGrade (signingGrade),
	_executingGrade (executingGrade)
{
	if (_signingGrade < 1 || _executingGrade < 1)
		throw Form::GradeTooHighException();
	if (_signingGrade > 150 || _executingGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form( const Form& other ) :
	_name (other._name),
	_signed (other._signed),
	_signingGrade (other._signingGrade),
	_executingGrade (other._executingGrade) {}

Form::~Form() {}

Form	&Form::operator=( const Form& other ) {
	std::cerr << "Cannot assign Forms" << std::endl;
	(void)other;
	return *this;
}

//______________________Methods_____________________//

const std::string	Form::getName() const { return _name; }
bool				Form::getSigned() const { return _signed; }
int					Form::getSigningGrade() const { return _signingGrade; }
int					Form::getExecutingGrade() const { return _executingGrade; }

void	Form::beSigned( const Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() > _signingGrade)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

std::ostream	&operator<<( std::ostream& out, const Form& form ) {
	out << "Name of the form: " << form.getName() << std::endl
		<< "Is it signed: " << form.getSigned() << std::endl
		<< "Signing grade: " << form.getSigningGrade() << std::endl
		<< "Executing grade: " << form.getExecutingGrade() << std::endl;
	return out;
}

//____________________Exceptions____________________//

const char*	Form::GradeTooHighException::what() const throw() { return "Grade is too high !"; }

const char*	Form::GradeTooLowException::what() const throw() { return "Grade is too low !"; }
