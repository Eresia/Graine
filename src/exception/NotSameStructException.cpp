#include "NotSameStructException.hpp"

NotSameStructException::NotSameStructException(string const& message) throw(){
	this->message = message;
}

const char* NotSameStructException::what() const throw(){
	return message.c_str();
}

NotSameStructException::~NotSameStructException() throw(){

}
