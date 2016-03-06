#ifndef NEURON_LAYER
#define NEURON_LAYER

#include <iostream>
#include <string>
#include <vector>
#include "Neuron.hpp"

class NeuronLayer{

	private:
		int nbNeuron; //!< Number of Neuron the NeuronLayer has
		std::vector<Neuron> neurons; //!< Contains all the Neurons of the NeuronLayer

	public:
		NeuronLayer(int nbNeuron, int nbInputPerNeuron); //!< Constructor of NeuronLayer
		NeuronLayer(int nbNeuron, int nbInputPerNeuron, NeuronLayer& father, NeuronLayer& mother); //!< Constructor of NeuronLayer
		std::vector<double> stimule(std::vector<double> stim); 
};

#endif
