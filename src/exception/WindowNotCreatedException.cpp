#include "WindowNotCreatedException.hpp"
/**
* @exception <WindowNotCreatedException> {Exception thrown when something
like input devices, images or library fail to load}
*/
WindowNotCreatedException::WindowNotCreatedException(string const& message) throw(){
	this->message = message;
}

const char* WindowNotCreatedException::what() const throw(){
	return message.c_str();
}

WindowNotCreatedException::~WindowNotCreatedException() throw(){

}
