#ifndef CREATURE
#define CREATURE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../map/Position.hpp"

class Creature{

	private:
		Position& position;
		double rotation;
		double speed;

	public:
		Creature(Position& position, double speed);
		void move();
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
