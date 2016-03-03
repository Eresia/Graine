/**
*	@file NeuronLayer.cpp
*	Purpose : Define the behavior of a NeuronLayer using Neuron.cpp functions.
*
*	@author Eresia
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "NeuronLayer.hpp"

using namespace std;

NeuronLayer::NeuronLayer(int nbNeuron, int nbInputPerNeuron) : nbNeuron(nbNeuron){
	for(int i = 0; i < nbNeuron; i++){
		neurons.push_back(Neuron(nbInputPerNeuron));
	}
}

NeuronLayer::NeuronLayer(int nbNeuron, int nbInputPerNeuron, NeuronLayer& father, NeuronLayer& mother) : nbNeuron(nbNeuron){
	for(int i = 0; i < nbNeuron; i++){
		neurons.push_back(Neuron(nbInputPerNeuron, father.neurons[i], mother.neurons[i]));
	}
}

vector<double> NeuronLayer::stimule(vector<double> stim){
	vector<double> results;
	for(int i = 0; i < nbNeuron; i++){
		results.push_back(neurons[i].stimule(stim));
	}

	return results;
}
