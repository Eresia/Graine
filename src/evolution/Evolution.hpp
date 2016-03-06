#ifndef EVOLUTION
#define EVOLUTION

#include <iostream>
#include <string>
#include <vector>
#include "../neuronNetwork/NeuronNetwork.hpp"

#define EGALITARY
//#define FAVORITISM

class Evolution{

	private:
		std::vector<NeuronNetwork> brains;
		int nbCreaMax; //!< Maximum number of creatures allowed 

		vector<NeuronNetwork> egalitary(); //!< USED Algorithm of selection for each generation
		vector<NeuronNetwork> favoritism(); //!< NOTUSED Algorithm of selection for each generation

	public:
		Evolution(std::vector<NeuronNetwork> brains, int nbCreaMax);
		vector<NeuronNetwork> evolve();
};

#endif
