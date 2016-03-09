#ifndef CONTROLLER
#define CONTROLLER

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "../map/Map.hpp"
#include "../map/mapType/MapObjective.hpp"
#include "../generation/Generation.hpp"
#include "../creature/Creature.hpp"
#include "../creature/FeelingBar.hpp"
#include "../creature/feature/input/InputFeature.hpp"
#include "../creature/feature/input/ObjectiveDirection.hpp"
#include "../creature/feature/input/InputDouble.hpp"
#include "../creature/feature/output/OutputFeature.hpp"
#include "../creature/feature/output/Movement.hpp"
#include "../creature/feature/output/Eat.hpp"
#include "Evolution.hpp"
#include "../usefull/Usefull.hpp"
#include "../exception/NotEnoughCreatureException.hpp"
#include "../exception/NotEnoughBrainException.hpp"

#define MIN_CREA 2

enum Rotation : bool {ROTATE_LEFT, ROTATE_RIGHT};

class Controller{

	private:
		Map& map;
		int nbCreaSelectMax, nbCreaMax; //!< Maximum number of creature allowed to be generated
		int nbGen; //!< Number of generation the simulation has traveled
		int turn, turnMax;
		std::vector<Creature*> creatures;
		int idCounter;
		std::vector<NeuralNetwork> lastBestBrains;

		void selectBest(); //!< Selecting the best specimens we have to construct
		void createCreatures(); //!< Function of creature's creation
		void createCreatures(vector<NeuralNetwork> brains);  //!< Creature creation but with NeuralNetwork associated
		void addFeatures(Creature* creature); //!< Adding some features to the creature (may be usefull in use with the other part of the projet)
		Position getSpawn(int number); //!< Get the spawning point of each creature
		void printNbGen(); //!< Print the number of generation the simulation has traveled through
		bool creatureIsTouchingObjective();

	public:
		Controller(Map& map, int nbCreaSelectMax, int nbCreaMax, int turnMax);
		void update();
		bool doneObjective();

		int getNbCreaMax() const;
		Position& getPositionCrea(int crea);
		int getRotationCrea(int crea) const;
		int getNbGen();

		//!< Debug methods
		Controller(Map& map);
		void update(double speed);
		void update(Rotation rotation);
};

#endif
