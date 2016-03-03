#ifndef CREATURE
#define CREATURE

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include "../map/Map.hpp"
#include "../map/Position.hpp"
#include "../neuronNetwork/NeuronNetwork.hpp"
#include "feature/input/InputFeature.hpp"
#include "feature/output/OutputFeature.hpp"
#include "../map/case/material/FoodMaterial.hpp"
#include "FeelingBar.hpp"
#include "../exception/BadNumberOfInputException.hpp"
#include "../exception/BadNumberOfOutputException.hpp"

#define BRAIN_INPUT 2
#define BRAIN_OUTPUT 3
#define BRAIN_HIDDEN_LAYER 1
#define BRAIN_NEURON_PER_LAYER 6

#define SPEED_MULT 2

class Creature{

	private:
		int id;
		Map& map;
		Position position;
		double rotation;
		NeuronNetwork brain;
		std::map<InputId, InputFeature*> inputFeatures;
		std::map<OutputId, OutputFeature*> outputFeatures;
		std::map<FeelingBarId, FeelingBar*> feelingBars;

		Position objective;

	public:
		Creature(int id, Map& map, Position position);
		Creature(int id, Map& map, Position position, NeuronNetwork brain);
		Creature(int id, Map& map, Position position, Position& objective);
		Creature(int id, Map& map, Position position, NeuronNetwork brain, Position& objective);
		//Creature(Creature& copy);
		void think();
		void eat();
		void doActions();
		void move(int speed);
		void move(double forceLeft, double forceRight);
		void turnLeft();
		void turnRight();

		void addInputFeature(InputId, InputFeature* input);
		void addOutputFeature(OutputId, OutputFeature* output);

		void addFeelingBar(FeelingBarId id, FeelingBar* bar);

		Position& getPosition();
		void setPosition(Position position);
		double getRotation() const;
		void setRotation(double rotation);
		int getId() const;
		NeuronNetwork& getBrain();
		Position& getObjective();
		void setObjective(Position& objective);
		void setObjective(double x, double y);

		static bool comparePosition(const Creature* c1, const Creature* c2);
};

#endif
