#ifndef NEURON_NETWORK
#define NEURON_NETWORK

#include <iostream>
#include <string>
#include <vector>
#include "NeuronLayer.hpp"
#include "../exception/BadNumberOfInputException.hpp"

class NeuronNetwork{

	private:
		int nbInput;
		int nbHiddenLayer;
		std::vector<NeuronLayer> layers;

	public:
		NeuronNetwork(int nbInput, int nbOutput, int nbHiddenLayer, int nbNeuronPerLayer);
		std::vector<double> update(std::vector<double>& firstInputs);

};

#endif
