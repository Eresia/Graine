#include "EventListNotCreatedException.hpp"

EventListNotCreatedException::EventListNotCreatedException(string const& message) throw(){
	this->message = message;
}

const char* EventListNotCreatedException::what() const throw(){
	return message.c_str();
}

EventListNotCreatedException::~EventListNotCreatedException() throw(){

}
