#ifndef OUTPUT_FEATURE
#define OUTPUT_FEATURE

#include <iostream>
#include <string>
#include <vector>
#include "../Feature.hpp"

enum OutputId : int {OUTPUT_MOVEMENT_LEFT, OUTPUT_MOVEMENT_RIGHT, OUTPUT_EAT};

class OutputFeature : public Feature{

	private:


	public:
		OutputFeature();
		virtual void update(double value) = 0;
};

#endif
