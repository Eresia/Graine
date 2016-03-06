#ifndef NEURON
#define NEURON

#include <iostream>
#include <string>
#include <vector>
#include "../usefull/Usefull.hpp"
#include "../exception/BadNumberOfInputException.hpp"

//#define THRESHOLD 1.0
#define RATE_CROSS_OVER 20 //Crossover rate, determine the frequency of crossovers
#define RATE_MUTATION 1 //Mutation rate, determine the frequency of mutations

class Neuron{

	private:
		int nbInput; //Number of neurons allocated
		vector<double> mult;

		double sigmoid(double value);

	public:
		Neuron(int nbInput);
		Neuron(int nbInput, Neuron& father, Neuron& mother);
		double crossOver(double used, double notUsed);
		double mutate(double value);
		double stimule(std::vector<double> weights);

};

#endif
