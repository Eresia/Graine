#ifndef EVOLUTION
#define EVOLUTION

#include <iostream>
#include <string>
#include <vector>
#include "../neuronNetwork/NeuronNetwork.hpp"

class Evolution{

	private:
		std::vector<NeuronNetwork> brains;

	public:
		Evolution(std::vector<NeuronNetwork> brains);
		vector<NeuronNetwork> evolve();
};

#endif
