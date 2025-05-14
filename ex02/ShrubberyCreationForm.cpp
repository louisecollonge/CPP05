#include "ShrubberyCreationForm.hpp"
#define DARK_GREEN		"\033[38;5;22m"
#define RESET			"\033[0m"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : AForm(target + "_shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	std::cerr << "Cannot assign ShrubberyCreationForms" << std::endl;
	(void)other;
	return *this;
}

void	ShrubberyCreationForm::execute( const Bureaucrat& bureaucrat ) {
	if (bureaucrat.getGrade() < this->getExecutingGrade())
		throw GradeTooLowException();
	std::ofstream	file((_target + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cerr << "Error: cannot create file." << std::endl;
		return ;
	}
	file << DARK_GREEN
		 << "            ___"
		 << "         _( .  )_"
		 << "        ( .  .   )"
		 << "      _(  .    .  )_" 
		 << "     ( .     .    . )"
		 << "    (.  \\ \\/ / .   .)"
		 << "     (  .\\   \\_/ / . )"
		 << "      (_. \\     / ._)"
		 << "        ( .|   |. )"
		 << "         (_|   |_)"
		 << "           |   |"
		 << "           |   |"
		 << "_______\\\\\\/    \\///_______"
		 << RESET << std::endl;

	file.close();
}

AForm*	ShrubberyCreationForm::clone() {}

