#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signingGrade;
		const int			_executingGrade;
		
		Form	&operator=( const Form& other );

	public:
		Form( const std::string name, const int signingGrade, const int executingGrade );
		Form( const Form& other );
		~Form();

		const std::string	getName() const;
		bool				getSigned() const;
		int					getSigningGrade() const;
		int					getExecutingGrade() const;
		void				beSigned( const Bureaucrat &bureaucrat );

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream	&operator<<( std::ostream& out, const Form& form );
