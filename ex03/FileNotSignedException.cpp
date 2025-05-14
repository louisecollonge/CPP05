#include "FileNotSignedException.hpp"

const char*	FileNotSignedException::what() const throw() {
	return "file is not signed.";
}

