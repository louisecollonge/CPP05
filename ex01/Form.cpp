#include "Form.hpp"

Form::Form( const std::string name, const int signingGrade, const int executingGrade ) :
	_name (name) ,
	_signed (false),
	_signingGrade (signingGrade),
	_executingGrade (executingGrade)
{
	if (_signingGrade < 1 || _executingGrade < 1)
		throw GradeTooHighException();
	if (_signingGrade > 150 || _executingGrade > 150)
		throw GradeTooLowException();
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

const std::string	Form::getName() const { return _name; }
bool				Form::getSigned() const { return _signed; }
int					Form::getSigningGrade() const { return _signingGrade; }
int					Form::getExecutingGrade() const { return _executingGrade; }

void	Form::beSigned( Bureaucrat bureaucrat ) {
	if (bureaucrat.getGrade() > _signingGrade)
		throw GradeTooLowException();
	else
		_signed = true;
}

std::ostream	&operator<<( std::ostream& out, const Form& form ) {
	out << "Name: " << form.getName() << std::endl
		<< "Boolean: " << form.getSigned() << std::endl
		<< "Signing grade: " << form.getSigningGrade() << std::endl
		<< "Executing grade: " << form.getExecutingGrade() << std::endl;
	return out;
}
