#pragma once

#include <iostream>
#include <string>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Form.hpp"

class	Form;

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
		void				signForm( Form &form ) const;
};

std::ostream	&operator<<( std::ostream& out, const Bureaucrat &bureaucrat );
