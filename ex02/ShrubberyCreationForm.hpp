#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "AForm.hpp"

#define DARK_GREEN		"\033[38;5;22m"
#define RESET			"\033[0m"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		
	public:
		ShrubberyCreationForm( const std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm& other );

		virtual void		execute( const Bureaucrat& bureaucrat );
};

std::ostream	&operator<<( std::ostream& out, const ShrubberyCreationForm& ShrubberyCreationForm );