#include "NotEnoughCreatureException.hpp"
/**
* @exception <NotEnoughCreatureException> {Exception thrown when the number of creature
asked to be created at start in inferior to the number of creature required by the program (supposed 1)}
*/
NotEnoughCreatureException::NotEnoughCreatureException(string const& message) throw(){
	this->message = message;
}

const char* NotEnoughCreatureException::what() const throw(){
	return message.c_str();
}

NotEnoughCreatureException::~NotEnoughCreatureException() throw(){

}
