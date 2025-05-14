#include <iostream>
#include <exception>

class	GradeTooLowException : public std::exception
{
	public:
		virtual const char*	what() const throw();
};
