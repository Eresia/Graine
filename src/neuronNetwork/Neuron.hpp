#ifndef NEURON
#define NEURON

#include <iostream>
#include <string>
#include <vector>
#include "../usefull/Usefull.hpp"
#include "../exception/BadNumberOfInputException.hpp"

//#define THRESHOLD 1.0

class Neuron{

	private:
		int nbInput;
		vector<double> mult;

		double fonct(double value);

	public:
		Neuron(int nbInput);
		double stimule(std::vector<double> weights);

};

#endif
