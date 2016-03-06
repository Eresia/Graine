#ifndef NEURON
#define NEURON

#include <iostream>
#include <string>
#include <vector>
#include "../usefull/Usefull.hpp"
#include "../exception/BadNumberOfInputException.hpp"

//#define THRESHOLD 1.0
#define RATE_CROSS_OVER 20 //!< Crossover rate, determine the frequency of crossovers
#define RATE_MUTATION 1 //!< Mutation rate, determine the frequency of mutations

class Neuron{

	private:
		int nbInput; //!< Number of neurons allocated
		vector<double> mult;


		double sigmoid(double x);


	public:
		Neuron(int nbInput); //!< Constructor of Neuron
		Neuron(int nbInput, Neuron& father, Neuron& mother); //!< Constructor of Neuron
		double crossOver(double used, double notUsed); //!< Crossover function
		double mutate(double value); //!< Mutation function, these are quite rare
		double stimule(std::vector<double> weights); //!< Stimulation function

};

#endif
