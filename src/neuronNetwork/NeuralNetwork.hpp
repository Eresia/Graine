#ifndef NEURON_NETWORK
#define NEURON_NETWORK

#include <iostream>
#include <string>
#include <vector>
#include "NeuronLayer.hpp"
#include "../exception/BadNumberOfInputException.hpp"
#include "../exception/NotSameStructException.hpp"

class NeuralNetwork{

	private:
		int nbInput; //!< Number of input of the NeuralNetwork (implies number of actions)
		int nbOutput; //!< Number of output of the NeuralNetwork (implies number of objectives)
		int nbHiddenLayer; //!< Number of hidden layers of the NeuralNetwork (better computation)
		int nbNeuronPerLayer; //!< Number of Neuron per layer (not larger than twice the size of the input layer for computation purpose)
		std::vector<NeuronLayer> layers; //!< Contains all the Neuronlayer the NeuralNetwork has

	public:
		NeuralNetwork(int nbInput, int nbOutput, int nbHiddenLayer, int nbNeuronPerLayer); //!< Constructor of NeuralNetwork
		NeuralNetwork(NeuralNetwork father, NeuralNetwork mother); //!< Constructor of NeuralNetwork
		std::vector<double> update(std::vector<double>& firstInputs); //!< Function allowing to change (update) inputs value
		static bool asSameStruct(NeuralNetwork& net1, NeuralNetwork& net2); //!< Check if 2 NeuralNetwork have the same structure
		/*int getNbInput() const;
		int getNbOutput() const;
		int getNbHiddenLayer() const;
		int getNeuronPerLayer() const;*/
};

#endif
