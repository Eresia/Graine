/**
*	@file Neuron.cpp
*	Purpose : Define the behavior of a Neuron.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "Neuron.hpp"

using namespace std;

Neuron::Neuron(int nbInput) : nbInput(nbInput){
	for(int i = 0; i < nbInput; i++){
		mult.push_back(RandomClamped());
	}
}

Neuron::Neuron(int nbInput, Neuron& father, Neuron& mother) : nbInput(nbInput){
	Neuron* used;
	Neuron* notUsed;
	int randUse = rand()%2;
	if(randUse == 0){
		used = &father;
		notUsed = &mother;
	}
	else{
		used = &mother;
		notUsed = &father;
	}
	for(int i = 0; i < nbInput; i++){
		double value = crossOver(used->mult[i], notUsed->mult[i]);
		mult.push_back(mutate(value));
	}
}

/**
* crossOver method definition
* @param used
* @param notUsed
* @return a double value
*/
double Neuron::crossOver(double used, double notUsed){
	int random = rand()%100;
	if(random < RATE_CROSS_OVER){
		return notUsed;
	}
	else{
		return used;
	}
}

/**
* Define if a Neuron mutate or not which means the mutate value will change.
* @param value
* @return a double value
*/
double Neuron::mutate(double value){
	int random = rand()%100;
	if(random < RATE_MUTATION){
		return value + RandomClamped();
	}
	else{
		return value;
	}
}

/**
* Stimulation of a Neuron
* @param stim
* @return a complicated value
*/
double Neuron::stimule(vector<double> stim){
	double sumWeight = 0;

	if((int) stim.size() != nbInput){
		throw BadNumberOfInputException("Neuron needs " + to_string(nbInput) + " inputs, " + to_string(stim.size()) + " sent");
	}
	for(int i = 0; i < nbInput; i++){
		sumWeight += stim[i] * mult[i];
	}
	//return sigmoid(sumWeight/nbInput);
	return sumWeight/nbInput;
}

/**
* Sigmoid for the activation function of the neural network
* @param value value for the function
* @return the sigmoid function (actually not the sigmoid but tanh or another function)
*/
double Neuron::sigmoid(double value){
	//return ( 1 / ( 1 + exp(-value / 1)));
	//return ( exp(value) / pow( 1 + exp(-value / 1), 2));
	return ((exp(value) - exp(-value))/2)/((exp(value) + exp(-value))/2);
}
