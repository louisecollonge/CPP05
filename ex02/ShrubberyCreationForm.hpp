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

		virtual bool		execute( Bureaucrat const & executor ) const;
};

std::ostream	&operator<<( std::ostream& out, const ShrubberyCreationForm& ShrubberyCreationForm );