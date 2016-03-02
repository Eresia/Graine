#include "BadNumberOfOutputException.hpp"

BadNumberOfOutputException::BadNumberOfOutputException(string const& message) throw(){
	this->message = message;
}

const char* BadNumberOfOutputException::what() const throw(){
	return message.c_str();
}

BadNumberOfOutputException::~BadNumberOfOutputException() throw(){

}
