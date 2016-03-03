#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <string>
#include <vector>
#include "../map/Map.hpp"
#include "../map/mapType/MapObjective.hpp"
#include "../creature/Creature.hpp"
#include "../creature/FeelingBar.hpp"
#include "../creature/feature/input/InputFeature.hpp"
#include "../creature/feature/input/ObjectiveDirection.hpp"
#include "../creature/feature/output/OutputFeature.hpp"
#include "../creature/feature/output/Movement.hpp"
#include "../creature/feature/output/Eat.hpp"
#include "Evolution.hpp"
#include "../usefull/Usefull.hpp"
#include "../exception/NotEnoughCreatureException.hpp"
#include "../exception/NotEnoughBrainException.hpp"

#define MIN_CREA 2

#if defined(EGALITARY)
	#define MAX_CREA(X) X*(X-1)
#elif defined(FAVORITISM)
	#define MAX_CREA(X) sumFrom0ToN(X) + X/2
#else
	#define MAX_CREA(X) X*(X-1)
#endif

enum Rotation : bool {ROTATE_LEFT, ROTATE_RIGHT};

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
		void addFeatures(Creature* creature);
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
		int getNbGen();

		//Debug methods
		Controller(Map& map);
		void update(int speed);
		void update(Rotation rotation);
};

#endif
