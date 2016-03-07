#ifndef OBJECTIVE_DIRECTION
#define OBJECTIVE_DIRECTION

#include <iostream>
#include <string>
#include <vector>
#include "InputFeature.hpp"
#include "../../../generation/Generation.hpp"

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
