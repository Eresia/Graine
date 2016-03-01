#include "NotEnoughCreatureException.hpp"

NotEnoughCreatureException::NotEnoughCreatureException(string const& message) throw(){
	this->message = message;
}

const char* NotEnoughCreatureException::what() const throw(){
	return message.c_str();
}

NotEnoughCreatureException::~NotEnoughCreatureException() throw(){

}
