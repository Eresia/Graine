#ifndef NEURON
#define NEURON

#include <iostream>
#include <string>
#include <vector>
#include "../usefull/Usefull.hpp"
#include "../exception/BadNumberOfInputException.hpp"

//#define THRESHOLD 1.0
#define RATE_CROSS_OVER 20
#define RATE_MUTATION 1

class Neuron{

	private:
		int nbInput;
		vector<double> mult;

		double signoid(double value);

	public:
		Neuron(int nbInput);
		Neuron(int nbInput, Neuron& father, Neuron& mother);
		double crossOver(double used, double notUsed);
		double mutate(double value);
		double stimule(std::vector<double> weights);

};

#endif
