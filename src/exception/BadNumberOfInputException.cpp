#include "BadNumberOfInputException.hpp"

BadNumberOfInputException::BadNumberOfInputException(string const& message) throw(){
	this->message = message;
}

const char* BadNumberOfInputException::what() const throw(){
	return message.c_str();
}

BadNumberOfInputException::~BadNumberOfInputException() throw(){

}
