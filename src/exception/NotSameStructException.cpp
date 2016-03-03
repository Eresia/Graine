#include "NotSameStructException.hpp"
/**
* @exception <NotSameStructException> {Exception thrown when the structure
of the father is not the same as the structure of the mother NeuralNetwork when
trying to generate a new NeuralNetwork}
*/
NotSameStructException::NotSameStructException(string const& message) throw(){
	this->message = message;
}

const char* NotSameStructException::what() const throw(){
	return message.c_str();
}

NotSameStructException::~NotSameStructException() throw(){

}
