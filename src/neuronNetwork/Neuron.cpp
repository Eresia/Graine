#include "Neuron.hpp"

using namespace std;

Neuron::Neuron(int nbInput) : nbInput(nbInput){
	for(int i = 0; i < nbInput; i++){
		mult.push_back(RandFloat(10));
	}
}

double Neuron::stimule(vector<double> stim){
	int sumWeight = 0;

	if((int) stim.size() != nbInput){
		throw BadNumberOfInputException("Neuron need " + to_string(nbInput) + " inputs, " + to_string(stim.size()) + " send");
	}
	for(int i = 0; i < nbInput; i++){
		sumWeight += stim[i] * mult[i];
	}

	return fonct(sumWeight);
}

double Neuron::fonct(double value){
	return ( 1 / ( 1 + exp(-value / 1)));
}
