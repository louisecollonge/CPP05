#pragma once

#include <iostream>
#include <string>
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

		void				execute( const Bureaucrat& bureaucrat );
		virtual AForm*		clone();
};
