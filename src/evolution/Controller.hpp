#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <string>
#include <vector>
#include "../map/Map.hpp"
#include "../map/mapType/MapObjective.hpp"
#include "../creature/Creature.hpp"
#include "Evolution.hpp"
#include "../exception/NotEnoughCreatureException.hpp"
#include "../exception/NotEnoughBrainException.hpp"

#define MIN_CREA 2

class Controller{

	private:
		Map& map;
		int nbCrea, nbCreaMax;
		int nbGen;
		int turn, turnMax;
		std::vector<Creature*> creatures;
		int idCounter;

		void createCreatures();
		void createCreatures(vector<NeuronNetwork> brains);
		Position getSpawn(int number);
		void printNbGen();

	public:
		Controller(Map& map, int nbCrea, int turnMax);
		void update();
		bool doneObjective();

		int getNbCrea() const;
		int getNbCreaMax() const;
		Position& getPositionCrea(int crea);
		int getRotationCrea(int crea) const;
};

#endif
