#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include "AForm.hpp"

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
