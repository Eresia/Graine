#ifndef NEURON_LAYER
#define NEURON_LAYER

#include <iostream>
#include <string>
#include <vector>
#include "Neuron.hpp"

class NeuronLayer{

	private:
		int nbNeuron;
		std::vector<Neuron> neurons;

	public:
		NeuronLayer(int nbNeuron, int nbInputPerNeuron);
		std::vector<double> stimule(std::vector<double> stim);
};

#endif
