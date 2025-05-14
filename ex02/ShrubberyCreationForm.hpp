#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		
	public:
		ShrubberyCreationForm( const std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm& other );

		void				execute( const Bureaucrat& bureaucrat );
		virtual AForm*		clone();
};
