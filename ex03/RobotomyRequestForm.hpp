#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

#define ORANGE	    "\033[38;5;214m"
#define BLUE	    "\033[34m"
#define BOLD_RED    "\033[1;31m"
#define PINK	 	"\033[0;35m"
#define RESET	    "\033[0m"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		virtual ~RobotomyRequestForm();
		
		RobotomyRequestForm	&operator=( const RobotomyRequestForm& other );

		virtual bool		execute( Bureaucrat const & executor ) const;
};

std::ostream	&operator<<( std::ostream& out, const RobotomyRequestForm& RobotomyRequestForm );