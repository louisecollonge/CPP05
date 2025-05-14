#include "GradeTooLowException.hpp"

const char*	GradeTooLowException::what() const throw() {
	return "grade is too low.";
}

