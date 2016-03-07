#ifndef USEFULL
#define USEFULL

#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

//#define MANUAL_CREATURE

#ifndef MANUAL_CREATURE
	//#define TEST_PROBA
#endif

#ifndef TEST_PROBA
	#define PRINT_GEN
#endif

double RandFloat(); //!< Give a random float number
double RandFloat(double min, double max); //!< Give a random float number between to values (min and max)
double RandFloat(double max); //!< Give a random float given a max value (max)
double RandomClamped(); //!< Give a random minus a random value
double RandomClamped(double min, double max); //!< Give a random minus a random value between to values
double RandomClamped(double max); //!< Give a random minus a random value given a max values
int sumFrom0ToN(int n); //!< Mathematical sum from 0 to n of given n

#endif
