/**
*	@file Usefull.cpp
*	Purpose : Some usefull functions returning random floats.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "Usefull.hpp"

double RandFloat() {
	return (rand())/(RAND_MAX+1.0);
}

double RandFloat(double min, double max) {
	return (RandFloat()*(max-min))+min;
}

double RandFloat(double max) {
	return RandFloat()*max;
}

double RandomClamped(){
	return RandFloat() - RandFloat();
}

double RandomClamped(double min, double max){
	return RandFloat(min, max) - RandFloat(min, max);
}

double RandomClamped(double max){
	return RandFloat(max) - RandFloat(max);
}

int sumFrom0ToN(int n){
	int result = 0;
	for(int i = n-1; i > 0; i--){
		result += i;
	}
	return result;
}
