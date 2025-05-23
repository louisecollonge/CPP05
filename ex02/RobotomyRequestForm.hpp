#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

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