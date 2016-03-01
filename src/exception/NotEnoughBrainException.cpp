#include "NotEnoughBrainException.hpp"

NotEnoughBrainException::NotEnoughBrainException(string const& message) throw(){
	this->message = message;
}

const char* NotEnoughBrainException::what() const throw(){
	return message.c_str();
}

NotEnoughBrainException::~NotEnoughBrainException() throw(){

}
