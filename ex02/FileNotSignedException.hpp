#include <iostream>
#include <exception>

class	FileNotSignedException : public std::exception
{
	public:
		virtual const char*	what() const throw();
};
