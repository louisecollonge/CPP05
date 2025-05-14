#include "AForm.hpp"

AForm::AForm( const std::string name, const int signingGrade, const int executingGrade ) :
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

AForm::AForm( const AForm& other ) :
	_name (other._name),
	_signed (other._signed),
	_signingGrade (other._signingGrade),
	_executingGrade (other._executingGrade) {}

AForm::~AForm() {}

AForm	&AForm::operator=( const AForm& other ) {
	std::cerr << "Cannot assign AForms" << std::endl;
	(void)other;
	return *this;
}

const std::string	AForm::getName() const { return _name; }
bool				AForm::getSigned() const { return _signed; }
int					AForm::getSigningGrade() const { return _signingGrade; }
int					AForm::getExecutingGrade() const { return _executingGrade; }

void	AForm::beSigned( const Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() > _signingGrade)
		throw GradeTooLowException();
	else
		_signed = true;
}

std::ostream	&operator<<( std::ostream& out, const AForm& AForm ) {
	out << "Name: " << AForm.getName() << std::endl
		<< "Boolean: " << AForm.getSigned() << std::endl
		<< "Signing grade: " << AForm.getSigningGrade() << std::endl
		<< "Executing grade: " << AForm.getExecutingGrade() << std::endl;
	return out;
}
