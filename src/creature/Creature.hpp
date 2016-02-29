#ifndef CREATURE
#define CREATURE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../map/Position.hpp"
#include "../neuronNetwork/NeuronNetwork.hpp"
#include "../exception/BadNumberOfInputException.hpp"

class Creature{

	private:
		Position& position;
		double rotation;
		NeuronNetwork brain;

	public:
		Creature(Position& position, double speed);
		void think(double info1, double info2);
		void move(int speed);
		void move(double forceLeft, double forceRight);
		void turnLeft();
		void turnRight();

		Position& getPosition();
		void setPosition(Position& position);
		double getRotation();
		void setRotation(double rotation);
		double getSpeed();
		void setSpeed(double speed);
};

#endif
