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

		virtual void		execute( const Bureaucrat& bureaucrat );
};

std::ostream	&operator<<( std::ostream& out, const RobotomyRequestForm& RobotomyRequestForm );