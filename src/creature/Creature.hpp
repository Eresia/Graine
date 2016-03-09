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
#include "../neuronNetwork/NeuralNetwork.hpp"
#include "../generation/Generation.hpp"
#include "feature/input/InputFeature.hpp"
#include "feature/output/OutputFeature.hpp"
#include "../map/case/material/FoodMaterial.hpp"
#include "FeelingBar.hpp"
#include "../exception/BadNumberOfInputException.hpp"
#include "../exception/BadNumberOfOutputException.hpp"

class Creature{

	private:
		int id;
		Map& map;
		Position position;
		double rotation;
		NeuralNetwork brain;
		std::map<InputId, InputFeature*> inputFeatures;
		std::map<OutputId, OutputFeature*> outputFeatures;
		std::map<FeelingBarId, FeelingBar*> feelingBars;

		Position objective;

	public:
		Creature(int id, Map& map, Position position);
		Creature(int id, Map& map, Position position, NeuralNetwork brain);
		Creature(int id, Map& map, Position position, Position& objective);
		Creature(int id, Map& map, Position position, NeuralNetwork brain, Position& objective);
		Creature(Creature& copy);
		void think();
		void eat();
		void doActions();
		void move(double speed);
		void move(double forceLeft, double forceRight);
		void turnLeft();
		void turnRight();

		void addInputFeature(InputId, InputFeature* input);
		void addOutputFeature(OutputId, OutputFeature* output);
		void clearFeatures();

		void addFeelingBar(FeelingBarId id, FeelingBar* bar);
		double getFeelingValue(FeelingBarId id) const;

		Position& getPosition();
		void setPosition(Position position);
		double getRotation() const;
		double& getRotationRef();
		void setRotation(double rotation);
		int getId() const;
		NeuralNetwork& getBrain();
		Position& getObjective();
		void setObjective(Position& objective);
		void setObjective(double x, double y);

		static bool comparePosition(const Creature* c1, const Creature* c2);
		static bool compareHunger(const Creature* c1, const Creature* c2);
};

#endif
