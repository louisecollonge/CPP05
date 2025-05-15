#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : AForm(target + "_shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	std::cerr << "Cannot assign ShrubberyCreationForms" << std::endl;
	(void)other;
	return *this;
}

bool	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
	if (this->getSigned() == false) {
		throw FileNotSignedException();
		return false;
	}
	if (executor.getGrade() > this->getExecutingGrade()) {
		throw GradeTooLowException();
		return false;
	}

	std::ofstream	file((_target + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cerr << "Error: cannot create file." << std::endl;
		return false;
	}

	file << "                                v                     \n"
		 << "           ____      v                __              \n"
		 << "         _( .  )_       v v         _(  )_   _        \n"
		 << "   v    ( .  .   )        v        ( .  . )_( )   v   \n"
		 << "  v   _(  .    .  )_             _(  .    .   )     v \n" 
		 << "     ( .     .    . )           ( .    .    .  )      \n"
		 << "    (.  \\ \\/ / .    .)         (.  \\ \\  \\ \\//  .)     \n"
		 << "     (  .\\   \\_/ / . )        (__  .\\ \\_/  / .  )     \n"
		 << "      (_. \\     / ._)            (_. \\    /   _)      \n"
		 << "        ( .|   |. )                (__|  |___)        \n"
		 << "         (_|   |_)                    |  |            \n"
		 << "           |   |                      |  |            \n"
		 << "           |   |             *        |  |            \n"
		 << "_______\\\\\\/     \\///________\\|/___\\\\\\/    \\///________\n"
		 << std::endl;

	file.close();
	return true;
}

std::ostream	&operator<<( std::ostream& out, const ShrubberyCreationForm& ShrubberyCreationForm ) {
	out << "Name of the form: " << ShrubberyCreationForm.getName() << std::endl
		<< "Is it signed: " << ShrubberyCreationForm.getSigned() << std::endl
		<< "Signing grade: " << ShrubberyCreationForm.getSigningGrade() << std::endl
		<< "Executing grade: " << ShrubberyCreationForm.getExecutingGrade() << std::endl;
	return out;
}
