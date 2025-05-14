#pragma once

#include <iostream>
#include <string>
// #include "GradeTooHighException.hpp"
// #include "GradeTooLowException.hpp"
#include "Bureaucrat.hpp"

class	Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signingGrade;
		const int			_executingGrade;

	public:
		Form( const std::string name, const int signingGrade, const int executingGrade );
		Form( const Form& other );
		~Form();
		Form	&operator=( const Form& other );

		const std::string	getName() const;
		bool				getSigned() const;
		int			getSigningGrade() const;
		int			getExecutingGrade() const;
		void				beSigned( Bureaucrat bureaucrat );
};

std::ostream	&operator<<( std::ostream& out, const Form& form );