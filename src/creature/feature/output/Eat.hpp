#ifndef EAT
#define EAT

#include <iostream>
#include <string>
#include <vector>
#include "OutputFeature.hpp"
#include "../../Creature.hpp"

class Eat : public OutputFeature{

	private:
		Creature* creature;

	public:
		Eat(Creature* creature);
		virtual void update(double value);
};

#endif
