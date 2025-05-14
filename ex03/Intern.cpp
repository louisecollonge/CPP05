#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern( const Intern& other ) { (void)other; } //!

Intern::~Intern() {}

Intern	&Intern::operator=( const Intern& other ) { //!
	(void)other;
	return *this;
}

AForm*	Intern::makeShrubberyCreationForm( const std::string &target ) { return new ShrubberyCreationForm(target); }
AForm*	Intern::makeRobotomyRequestForm( const std::string &target ) { return new RobotomyRequestForm(target); }
AForm*	Intern::makePresidentialPardonForm( const std::string &target ) { return new PresidentialPardonForm(target); }

AForm*	Intern::makeForm( const std::string &formName, const std::string &target ) 
{
	AForm*	(Intern::*functions[])(const std::string &target) = {	&Intern::makeShrubberyCreationForm,
																	&Intern::makeRobotomyRequestForm,
																	&Intern::makePresidentialPardonForm };
	std::string	names[] = { "ShrubberyCreationForm",
							"RobotomyRequestForm",
							"PresidentialPardonForm" };
	AForm*	newForm = NULL;

	for (int i = 0; i < 3; i++) {
		if (names[i] == formName)
			newForm = (this->*functions[i])(target);
	}

	if (newForm != NULL)
		std::cout << "Interne creates " << formName << "." << std::endl;
	else
		std::cout << BOLD_RED << "Error: intern cannot create " << formName << " because it does not exist." << RESET << std::endl;
	return newForm;
}

