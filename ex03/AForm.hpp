#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

#define ORANGE	    "\033[38;5;214m"
#define BLUE	    "\033[34m"
#define BOLD_RED    "\033[1;31m"
#define PINK	 	"\033[0;35m"
#define RESET	    "\033[0m"

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

		virtual bool		execute( Bureaucrat const & executor ) const = 0;

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class	FileNotSignedException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		
};

std::ostream	&operator<<( std::ostream& out, const AForm& Aform );
