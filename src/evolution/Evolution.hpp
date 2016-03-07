#ifndef EVOLUTION
#define EVOLUTION

#include <iostream>
#include <string>
#include <vector>
#include "../neuronNetwork/NeuralNetwork.hpp"

#define EGALITARY
//#define FAVORITISM

class Evolution{

	private:
		std::vector<NeuralNetwork> brains;
		int nbCreaMax; //!< Maximum number of creatures allowed

		vector<NeuralNetwork> egalitary(); //!< USED Algorithm of selection for each generation
		vector<NeuralNetwork> favoritism(); //!< NOTUSED Algorithm of selection for each generation

	public:
		Evolution(std::vector<NeuralNetwork> brains, int nbCreaMax);
		vector<NeuralNetwork> evolve();
};

#endif
