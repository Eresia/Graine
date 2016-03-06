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
		int nbInput; //!< Number of input of the NeuronNetwork (implies number of actions)
		int nbOutput; //!< Number of output of the NeuronNetwork (implies number of objectives)
		int nbHiddenLayer; //!< Number of hidden layers of the NeuronNetwork (better computation)
		int nbNeuronPerLayer; //!< Number of Neuron per layer (not larger than twice the size of the input layer for computation purpose)
		std::vector<NeuronLayer> layers; //!< Contains all the Neuronlayer the NeuronNetwork has

	public:
		NeuronNetwork(int nbInput, int nbOutput, int nbHiddenLayer, int nbNeuronPerLayer); //!< Constructor of NeuronNetwork
		NeuronNetwork(NeuronNetwork father, NeuronNetwork mother); //!< Constructor of NeuronNetwork
		std::vector<double> update(std::vector<double>& firstInputs); //!< Function allowing to change (update) inputs value
		static bool asSameStruct(NeuronNetwork net1, NeuronNetwork& net2); //!< Check if 2 NeuronNetwork have the same structure
		/*int getNbInput() const;
		int getNbOutput() const;
		int getNbHiddenLayer() const;
		int getNeuronPerLayer() const;*/
};

#endif
