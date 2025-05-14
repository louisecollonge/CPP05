#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define BOLD_RED    "\033[1;31m"
#define RESET	    "\033[0m"

class Intern
{
	public:
		Intern();
		Intern( const Intern& other );
		~Intern();

		Intern	&operator=( const Intern& other );

		AForm*	makeForm( const std::string &formName, const std::string &target );
		AForm*	makeShrubberyCreationForm( const std::string &target );
		AForm*	makeRobotomyRequestForm( const std::string &target );
		AForm*	makePresidentialPardonForm( const std::string &target );
};
