/**
*	@file Controller.cpp
*	Purpose : Controller of the whole simulation, used to update the map and generate the creatures among other things.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "Controller.hpp"

using namespace std;

Controller::Controller(Map& map, int nbCreaSelectMax, int nbCreaMax, int turnMax) : map(map), nbCreaSelectMax(nbCreaSelectMax), nbCreaMax(nbCreaMax), nbGen(0), turn(0),
									turnMax(turnMax), idCounter(0){

	if(nbCreaSelectMax < MIN_CREA){
		throw NotEnoughCreatureException(to_string(MIN_CREA) + " or more creature expected, " + to_string(nbCreaSelectMax) + " given");
	}

	createCreatures();
	#ifdef PRINT_GEN
		printNbGen();
	#endif
}

void Controller::update(){
	#ifndef MANUAL_CREATURE
		if(turn < turnMax){

			for(int i = 0; i < nbCreaMax; i++){
				creatures[i]->think();
			}
			turn++;
		}
		else{
			int nbCreaUse;
			vector<NeuralNetwork> newBrains;
			selectBest();
			#ifdef USE_PARENT
				nbCreaUse = nbCreaMax-lastBestBrains.size();
			#else
				nbCreaUse = nbCreaMax;
			#endif
			Evolution evolution(lastBestBrains, nbCreaUse);
			newBrains = evolution.evolve();
			createCreatures(newBrains);
			turn = 0;
			nbGen++;
			#ifdef PRINT_GEN
				printNbGen();
			#endif
		}
	#endif
}

void Controller::selectBest(){
	int nbSelect = 0;
	lastBestBrains.clear();
	int result = 0;

	for(int i = 0; i < nbCreaMax; i++){
		double x = (creatures[i]->getPosition().getX()/((double) SIZE_IMAGE_H))  - creatures[i]->getObjective().getX();
		double y = (creatures[i]->getPosition().getY()/((double) SIZE_IMAGE_W))  - creatures[i]->getObjective().getY();
		double dist = sqrt(x*x + y*y);
		result += dist;
	}

	//cout << result/((double) nbCreaMax) << endl;

	partial_sort(creatures.begin(), creatures.begin() + nbCreaSelectMax, creatures.end(), Creature::compareHunger);
	for(int i = 0; i < nbCreaSelectMax; i++){
		if(creatures[i]->getFeelingValue(FEELING_FOOD)){
			nbSelect++;
			lastBestBrains.push_back(creatures[i]->getBrain());
		}
		else{
			break;
		}
	}
	if(nbSelect < 2){
		vector<Creature*> copy;
		for(int i = 0; i < nbCreaMax; i++){
			creatures[i]->getPosition() -= creatures[i]->getObjective();
		}

		partial_sort(creatures.begin(), creatures.begin() + nbCreaSelectMax, creatures.end(), Creature::comparePosition);

		for(int i = 0; i < nbCreaSelectMax; i++){
			creatures[i]->getPosition() += creatures[i]->getObjective();
			lastBestBrains.push_back(creatures[i]->getBrain());
		}
	}
}

bool Controller::doneObjective(){
	#ifdef TEST_PROBA
		#ifdef TOUCH_OBJECTIVE
			return creatureIsTouchingObjective();
		#else
			return (nbGen >= NB_GEN_MAX);
		#endif
	#else
		return creatureIsTouchingObjective();
	#endif
}

bool Controller::creatureIsTouchingObjective(){
	int nb = 0;
	for(int i = 0; i < nbCreaMax; i++){
		int xObj = creatures[i]->getObjective().getX();
		int yObj = creatures[i]->getObjective().getY();
		int x = creatures[i]->getPosition().getX() / SIZE_IMAGE_H;
		int y = creatures[i]->getPosition().getY() / SIZE_IMAGE_W;
		if((x == xObj) && (y == yObj)){
			nb++;
		}
	}
	return (nb>=1);
}

void Controller::createCreatures(){
	MapObjective& mapObj = (MapObjective&) map;

	creatures.clear();
	for(int i = 0; i < nbCreaMax; i++){
		Position pos;
		Creature* crea;
		pos = getSpawn(i);
		crea = new Creature(idCounter, map, pos, mapObj.getObjective());
		addFeatures(crea);
		idCounter++;
		creatures.push_back(crea);
	}
}

void Controller::createCreatures(vector<NeuralNetwork> brains){
	MapObjective& mapObj = (MapObjective&) map;
	int nbCreaUse;
	#ifdef USE_PARENT
		nbCreaUse = nbCreaMax-((int) lastBestBrains.size());
	#else
		nbCreaUse = nbCreaMax;
	#endif
	if((int) brains.size() != nbCreaUse){
		throw NotEnoughCreatureException("Evolution failed, " + to_string(brains.size()) + " brains given, " + to_string(nbCreaMax) + " attempt");
	}

	creatures.clear();
	for(int i = 0; i < nbCreaMax; i++){
		NeuralNetwork* brain;
		#ifdef USE_PARENT
			if(i < (int) lastBestBrains.size()){
				brain = &lastBestBrains[i];
			}
			else{
				brain = &brains[i-lastBestBrains.size()];
			}
		#else
			brain = &brains[i];
		#endif
		Position pos;
		Creature* crea;
		pos = getSpawn(i);

		crea = new Creature(idCounter, map, pos, *brain, mapObj.getObjective());
		addFeatures(crea);
		idCounter++;
		creatures.push_back(crea);
	}

}

void Controller::addFeatures(Creature* creature){
	creature->addFeelingBar(FEELING_FOOD, new FeelingBar(100));
	creature->addInputFeature(INPUT_OBJ_X, new ObjectiveDirection(creature->getObjective().getXRef(), SIZE_IMAGE_H, creature->getPosition().getXRef()));
	creature->addInputFeature(INPUT_OBJ_Y, new ObjectiveDirection(creature->getObjective().getYRef(), SIZE_IMAGE_W, creature->getPosition().getYRef()));
	//creature->addInputFeature(INPUT_MOVE_X, new InputDouble(creature->getPosition().getXRef()));
	//creature->addInputFeature(INPUT_MOVE_Y, new InputDouble(creature->getPosition().getYRef()));
	//creature->addInputFeature(INPUT_DIRECTION, new InputDouble(creature->getRotationRef()));
	creature->addOutputFeature(OUTPUT_MOVEMENT_LEFT, new Movement());
	creature->addOutputFeature(OUTPUT_MOVEMENT_RIGHT, new Movement());
	creature->addOutputFeature(OUTPUT_EAT, new Eat(creature));
}

Position Controller::getSpawn(int number){
	MapObjective& mapObj = (MapObjective&) map;
	double objX = mapObj.getObjective().getX();
	double objY = mapObj.getObjective().getY();
	Position pos;
	double spawnX;
	double spawnY;

	#ifdef SPAWN_RANDOM
		double distance;
		do{
			double diffX, diffY;
			spawnY = RandFloat(NB_CASE_W-1);
			spawnX = RandFloat(NB_CASE_H-1);
			diffX = objX - spawnX;
			diffY = objY - spawnY;
			distance = sqrt(diffX*diffX + diffY*diffY);
		}while(distance < RANDOM_PERIMETER);
		spawnY*=SIZE_IMAGE_W;
		spawnX*=SIZE_IMAGE_H;
	#else
		spawnX = (objX + RANDOM_PERIMETER*sin((double)(number)*(((2*M_PI)/SPAWN_SPREADING))))*SIZE_IMAGE_H;
		spawnY = (objY + RANDOM_PERIMETER*cos((double)(number)*(((2*M_PI)/SPAWN_SPREADING))))*SIZE_IMAGE_W;
	#endif
	pos = Position(spawnX, spawnY);
	return pos;
}

int Controller::getNbCreaMax() const{
	return nbCreaMax;
}

Position& Controller::getPositionCrea(int crea){
	return creatures[crea]->getPosition();
}

int Controller::getRotationCrea(int crea) const{
	return creatures[crea]->getRotation();
}

void Controller::printNbGen(){
	cerr << "Generation " << to_string(nbGen) << endl;
}

int Controller::getNbGen(){
	return nbGen;
}

/*========================================DEBUG METHODS ====================================*/

Controller::Controller(Map& map) : map(map), nbCreaSelectMax(1), nbCreaMax(1){
	MapObjective& mapObj = (MapObjective&) map;
	Position pos;
	pos = Position(0, 0);
	creatures.push_back(new Creature(0, map, pos, mapObj.getObjective()));
}

void Controller::update(double speed){
	creatures[0]->move(speed);
}

void Controller::update(Rotation rotation){
	if(rotation == ROTATE_LEFT){
		creatures[0]->turnLeft();
	}
	else{
		creatures[0]->turnRight();
	}
}
