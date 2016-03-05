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

double RandFloat();
double RandFloat(double min, double max);
double RandFloat(double max);
double RandomClamped();
double RandomClamped(double min, double max);
double RandomClamped(double max);
int sumFrom0ToN(int n);

#endif
