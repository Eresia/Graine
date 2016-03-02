#ifndef OUTPUT_FEATURE
#define OUTPUT_FEATURE

#include <iostream>
#include <string>
#include <vector>
#include "../Feature.hpp"

class OutputFeature : public Feature{

	private:


	public:
		virtual void update(double value) = 0;
};

#endif
