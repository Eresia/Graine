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

double Neuron::crossOver(double used, double notUsed){
	int random = rand()%100;
	if(random < RATE_CROSS_OVER){
		return notUsed;
	}
	else{
		return used;
	}
}

double Neuron::mutate(double value){
	int random = rand()%100;
	if(random < RATE_MUTATION){
		return value + RandomClamped();
	}
	else{
		return value;
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
	return sumWeight/nbInput;
}

double Neuron::fonct(double value){
	return ( 1 / ( 1 + exp(-value / 1)));
}
