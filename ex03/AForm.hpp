#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "FileNotSignedException.hpp"

class	Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signingGrade;
		const int			_executingGrade;

		AForm	&operator=( const AForm& other );

	public:
		AForm( const std::string name, const int signingGrade, const int executingGrade );
		AForm( const AForm& other );
		virtual ~AForm();

		const std::string	getName() const;
		bool				getSigned() const;
		int					getSigningGrade() const;
		int					getExecutingGrade() const;
		void				beSigned( const Bureaucrat &bureaucrat );

		virtual bool		execute( const Bureaucrat& bureaucrat ) const = 0;
};

std::ostream	&operator<<( std::ostream& out, const AForm& Aform );
