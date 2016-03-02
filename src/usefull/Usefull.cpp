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

int sumFrom0ToN(int n){
	int result = 0;
	for(int i = n-1; i > 0; i--){
		result += i;
	}
	return result;
}
