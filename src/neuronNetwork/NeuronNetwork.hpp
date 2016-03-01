#ifndef NEURON_NETWORK
#define NEURON_NETWORK

#include <iostream>
#include <string>
#include <vector>
#include "NeuronLayer.hpp"
#include "../exception/BadNumberOfInputException.hpp"
#include "../exception/NotSameStructException.hpp"

class NeuronNetwork{

	private:
		int nbInput;
		int nbOutput;
		int nbHiddenLayer;
		int nbNeuronPerLayer;
		std::vector<NeuronLayer> layers;

	public:
		NeuronNetwork(int nbInput, int nbOutput, int nbHiddenLayer, int nbNeuronPerLayer);
		NeuronNetwork(NeuronNetwork father, NeuronNetwork mother);
		std::vector<double> update(std::vector<double>& firstInputs);
		static bool asSameStruct(NeuronNetwork net1, NeuronNetwork& net2);
		/*int getNbInput() const;
		int getNbOutput() const;
		int getNbHiddenLayer() const;
		int getNeuronPerLayer() const;*/
};

#endif
