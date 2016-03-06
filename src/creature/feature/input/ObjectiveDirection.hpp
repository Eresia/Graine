#ifndef OBJECTIVE_DIRECTION
#define OBJECTIVE_DIRECTION

#include <iostream>
#include <string>
#include <vector>
#include "InputFeature.hpp"

#define MULT_DATA 1.5

class ObjectiveDirection : public InputFeature{

	private:
		double& objective;
		double& creature;
		int mult;

	public:
		ObjectiveDirection(double& objective, int mult, double& creature);
		virtual void update();
};

#endif
