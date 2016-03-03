#include "BadNumberOfInputException.hpp"
/**
* @exception <BadNumberOfInputException> {Exception thrown when the number of
input for a neuron at some point is not the number of inputs provided at start}
*/
BadNumberOfInputException::BadNumberOfInputException(string const& message) throw(){
	this->message = message;
}

const char* BadNumberOfInputException::what() const throw(){
	return message.c_str();
}

BadNumberOfInputException::~BadNumberOfInputException() throw(){

}
