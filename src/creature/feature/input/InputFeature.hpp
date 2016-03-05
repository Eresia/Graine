#ifndef INPUT_FEATURE
#define INPUT_FEATURE

#include <iostream>
#include <string>
#include <vector>
#include "../Feature.hpp"

enum InputId : int {INPUT_OBJ_X, INPUT_OBJ_Y, INPUT_MOVE_X, INPUT_MOVE_Y, INPUT_DIRECTION};

class InputFeature : public Feature{

	private:


	public:
		InputFeature();
		virtual void update() = 0;
};

#endif
