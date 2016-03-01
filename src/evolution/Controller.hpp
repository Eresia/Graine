#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <string>
#include <vector>
#include "../map/Map.hpp"
#include "../map/mapType/MapObjective.hpp"
#include "../creature/Creature.hpp"
#include "../exception/NotEnoughCreatureException.hpp"

class Controller{

	private:
		Map& map;
		int nbCrea, nbCreaMax;
		int turn, turnMax;
		std::vector<Creature*> creatures;
		int idCounter;

	public:
		Controller(Map& map, int nbCrea, int turnMax);
		void update();

		int getNbCrea() const;
		int getNbCreaMax() const;
		Position& getPositionCrea(int crea);
		int getRotationCrea(int crea) const;
};

#endif
