#include "Usefull.hpp"

double RandFloat() {
	return (rand())/(RAND_MAX+1.0);
}

double RandFloat(double max) {
	return RandFloat()*max;
}

double RandomClamped(){
	return RandFloat() - RandFloat();
}
