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
		int id;
		Position position;
		double rotation;
		NeuronNetwork brain;

	public:
		Creature(int id, Position position);
		Creature(int id, Position position, NeuronNetwork brain);
		Creature(Creature& copy);
		void think(double info1, double info2);
		void move(int speed);
		void move(double forceLeft, double forceRight);
		void turnLeft();
		void turnRight();

		Position& getPosition();
		void setPosition(Position position);
		double getRotation() const;
		void setRotation(double rotation);
		int getId() const;

		static bool comparePosition(const Creature* c1, const Creature* c2);
};

#endif
