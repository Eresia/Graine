/**
*	@file NeuralNetwork.cpp
*	Purpose : Define the behavior of a NeuralNetwork using NeuronLayer functions.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "NeuralNetwork.hpp"

using namespace std;

NeuralNetwork::NeuralNetwork(int nbInput, int nbOutput, int nbHiddenLayer, int nbNeuronPerLayer){
	this->nbInput = nbInput;
	this->nbOutput = nbOutput;
	this->nbHiddenLayer = nbHiddenLayer;
	this->nbNeuronPerLayer = nbNeuronPerLayer;
	if(nbHiddenLayer > 0){
		layers.push_back(NeuronLayer(nbNeuronPerLayer, nbInput));
		for(int i = 0; i < nbHiddenLayer - 1; i++){
			layers.push_back(NeuronLayer(nbNeuronPerLayer, nbNeuronPerLayer));
		}
		layers.push_back(NeuronLayer(nbOutput, nbNeuronPerLayer));
	}
	else{
		layers.push_back(NeuronLayer(nbOutput, nbInput));
	}
}

NeuralNetwork::NeuralNetwork(NeuralNetwork father, NeuralNetwork mother){
	if(!asSameStruct(father, mother)){
		throw NotSameStructException("The two networks don't have the same structure");
	}
	nbInput = father.nbInput;
	nbOutput = father.nbOutput;
	nbHiddenLayer = father.nbHiddenLayer;
	nbNeuronPerLayer = father.nbNeuronPerLayer;
	if(nbHiddenLayer > 0){
		layers.push_back(NeuronLayer(nbNeuronPerLayer, nbInput, father.layers[0], mother.layers[0]));
		for(int i = 0; i < nbHiddenLayer - 1; i++){
			layers.push_back(NeuronLayer(nbNeuronPerLayer, nbNeuronPerLayer, father.layers[i+1], mother.layers[i+1]));
		}
		layers.push_back(NeuronLayer(nbOutput, nbNeuronPerLayer, father.layers[nbHiddenLayer], mother.layers[nbHiddenLayer]));
	}
	else{
		layers.push_back(NeuronLayer(nbOutput, nbInput, father.layers[0], mother.layers[0]));
	}
}

vector<double> NeuralNetwork::update(vector<double>& firstInputs){
	vector<double> outputs;
	vector<double> inputs = firstInputs;

	if((int) firstInputs.size() != nbInput){
		throw BadNumberOfInputException("NeuralNetwork need " + to_string(nbInput) + " inputs, " + to_string(firstInputs.size()) + " sent");
	}

	for(int i = 0; i < nbHiddenLayer + 1; i++){
		outputs = layers[i].stimule(inputs);
		inputs = outputs;
	}

	return outputs;
}

bool NeuralNetwork::asSameStruct(NeuralNetwork& net1, NeuralNetwork& net2){
	return((net1.nbInput == net2.nbInput) && (net1.nbOutput == net2.nbOutput) && (net1.nbHiddenLayer == net2.nbHiddenLayer) && (net1.nbNeuronPerLayer == net2.nbNeuronPerLayer));
}
