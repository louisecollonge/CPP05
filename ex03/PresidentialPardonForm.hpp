#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include "AForm.hpp"

#define ORANGE	    "\033[38;5;214m"
#define BLUE	    "\033[34m"
#define BOLD_RED    "\033[1;31m"
#define PINK	 	"\033[0;35m"
#define RESET	    "\033[0m"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		virtual ~PresidentialPardonForm();
		
		PresidentialPardonForm	&operator=( const PresidentialPardonForm& other );

		virtual bool		execute( Bureaucrat const & executor ) const;
};

std::ostream	&operator<<( std::ostream& out, const PresidentialPardonForm& PresidentialPardonForm );
