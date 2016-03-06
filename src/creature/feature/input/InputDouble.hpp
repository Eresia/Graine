#ifndef INPUT_DOUBLE
#define INPUT_DOUBLE

#include <iostream>
#include <string>
#include <vector>
#include "InputFeature.hpp"

class InputDouble : public InputFeature{

	private:
		double& valueRef;
	public:
		InputDouble(double& value);
		virtual void update();
};

#endif
