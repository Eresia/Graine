#include "WindowNotCreatedException.hpp"

WindowNotCreatedException::WindowNotCreatedException(string const& message) throw(){
	this->message = message;
}

const char* WindowNotCreatedException::what() const throw(){
	return message.c_str();
}

WindowNotCreatedException::~WindowNotCreatedException() throw(){

}
