#ifndef INPUT_FEATURE
#define INPUT_FEATURE

#include <iostream>
#include <string>
#include <vector>
#include "../Feature.hpp"

class InputFeature : public Feature{

	private:


	public:
		virtual void update() = 0;
};

#endif
