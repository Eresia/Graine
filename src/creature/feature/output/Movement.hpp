#ifndef MOVEMENT
#define MOVEMENT

#include <iostream>
#include <string>
#include <vector>
#include "OutputFeature.hpp"

class Movement : public OutputFeature{

	private:

	public:
		Movement();
		virtual void update(double value);
};

#endif
