#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class	AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat	&operator=( const Bureaucrat& other );

	public:
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat& other );
		~Bureaucrat();

		const std::string	&getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm( AForm &form ) const;
		void				executeForm( AForm const & form ) const;

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream	&operator<<( std::ostream& out, const Bureaucrat &bureaucrat );
