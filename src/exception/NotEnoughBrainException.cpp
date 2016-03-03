#include "NotEnoughBrainException.hpp"
/**
* @exception <NotEnoughBrainException> {Exception thrown when there is not enough
brain power(?)}
*/
NotEnoughBrainException::NotEnoughBrainException(string const& message) throw(){
	this->message = message;
}

const char* NotEnoughBrainException::what() const throw(){
	return message.c_str();
}

NotEnoughBrainException::~NotEnoughBrainException() throw(){

}
