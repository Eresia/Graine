#include "EventListNotCreatedException.hpp"
/**
* @exception <EventListNotCreatedException> {Exception thrown when the events are not
"queing" properly.}
*/
EventListNotCreatedException::EventListNotCreatedException(string const& message) throw(){
	this->message = message;
}

const char* EventListNotCreatedException::what() const throw(){
	return message.c_str();
}

EventListNotCreatedException::~EventListNotCreatedException() throw(){

}
