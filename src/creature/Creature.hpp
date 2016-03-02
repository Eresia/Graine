#ifndef CREATURE
#define CREATURE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../map/Position.hpp"
#include "../neuronNetwork/NeuronNetwork.hpp"
#include "feature/input/InputFeature.hpp"
#include "feature/output/OutputFeature.hpp"
#include "../exception/BadNumberOfInputException.hpp"
#include "../exception/BadNumberOfOutputException.hpp"

#define BRAIN_INPUT 2
#define BRAIN_OUTPUT 2
#define BRAIN_HIDDEN_LAYER 1
#define BRAIN_NEURON_PER_LAYER 3

class Creature{

	private:
		int id;
		Position position;
		double rotation;
		NeuronNetwork brain;
		vector<InputFeature*> inputFeatures;
		vector<OutputFeature*> outputFeatures;

	public:
		Creature(int id, Position position);
		Creature(int id, Position position, NeuronNetwork brain);
		Creature(Creature& copy);
		void think();
		void doActions();
		void move(int speed);
		void move(double forceLeft, double forceRight);
		void turnLeft();
		void turnRight();

		void addInputFeature(InputFeature* input);
		void addOutputFeature(OutputFeature* output);

		Position& getPosition();
		void setPosition(Position position);
		double getRotation() const;
		void setRotation(double rotation);
		int getId() const;
		NeuronNetwork& getBrain();

		static bool comparePosition(const Creature* c1, const Creature* c2);
};

#endif
