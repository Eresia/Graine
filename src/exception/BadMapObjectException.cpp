#include "BadMapObjectException.hpp"
/**
* @exception BadMapObjectException Exception thrown when an object of
the map is not handled properly, not placed as it should be.
*/
BadMapObjectException::BadMapObjectException(string const& message) throw(){
	this->message = message;
}

const char* BadMapObjectException::what() const throw(){
	return message.c_str();
}

BadMapObjectException::~BadMapObjectException() throw(){

}
