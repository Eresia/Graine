#include "BadMapObjectException.hpp"

BadMapObjectException::BadMapObjectException(string const& message) throw(){
	this->message = message;
}

const char* BadMapObjectException::what() const throw(){
	return message.c_str();
}

BadMapObjectException::~BadMapObjectException() throw(){

}
