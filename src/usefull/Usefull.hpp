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
double RandFloat(double max);
double RandomClamped();
int sumFrom0ToN(int n);

#endif
