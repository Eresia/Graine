#include "Controller.hpp"

using namespace std;

Controller::Controller(Map& map, int nbCrea, int turnMax) : map(map), nbCrea(nbCrea), nbCreaMax(nbCrea*(nbCrea - 1)), nbGen(0), turn(0), turnMax(turnMax), idCounter(0){

	if(nbCrea < MIN_CREA){
		throw NotEnoughCreatureException(to_string(MIN_CREA) + " or more creature expected, " + to_string(nbCrea) + " given");
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
			vector<NeuronNetwork> bestBrains;
			vector<NeuronNetwork> newBrains;
			Evolution* evolution;
			for(int i = 0; i < nbCreaMax; i++){
				creatures[i]->getPosition() -= creatures[i]->getObjective();
			}

			partial_sort(creatures.begin(), creatures.begin() + nbCrea, creatures.end(), Creature::comparePosition);
			for(int i = 0; i < nbCrea; i++){
				bestBrains.push_back(creatures[i]->getBrain());
			}
			evolution = new Evolution(bestBrains);
			newBrains = evolution->evolve();
			createCreatures(newBrains);
			turn = 0;
			nbGen++;
			#ifdef PRINT_GEN
				printNbGen();
			#endif
		}
	#endif
}

bool Controller::doneObjective(){
	bool result = false;
	for(int i = 0; i < nbCreaMax; i++){
		int xObj = creatures[i]->getObjective().getX();
		int yObj = creatures[i]->getObjective().getY();
		int x = creatures[i]->getPosition().getX() / SIZE_IMAGE_H;
		int y = creatures[i]->getPosition().getY() / SIZE_IMAGE_W;
		if((x == xObj) && (y == yObj)){
			result = true;
			break;
		}
	}
	return result;
}

void Controller::createCreatures(){
	MapObjective& mapObj = (MapObjective&) map;

	creatures.clear();
	for(int i = 0; i < nbCreaMax; i++){
		Position pos;
		Creature* crea;
		pos = getSpawn(i);
		crea = new Creature(idCounter, pos, mapObj.getObjective());
		addFeatures(crea);
		idCounter++;
		creatures.push_back(crea);
	}
}

void Controller::createCreatures(vector<NeuronNetwork> brains){
	MapObjective& mapObj = (MapObjective&) map;
	if((int) brains.size() != nbCreaMax){
		throw NotEnoughCreatureException("Evolution failed, " + to_string(brains.size()) + " brains given, " + to_string(nbCreaMax) + " attempt");
	}

	creatures.clear();
	for(int i = 0; i < nbCreaMax; i++){
		Position pos;
		Creature* crea;
		pos = getSpawn(i);

		crea = new Creature(idCounter, pos, brains[i], mapObj.getObjective());
		addFeatures(crea);
		idCounter++;
		creatures.push_back(crea);
	}

}

void Controller::addFeatures(Creature* creature){
	creature->addInputFeature(new ObjectiveDirection(creature->getObjective().getXRef(), SIZE_IMAGE_H, creature->getPosition().getXRef()));
	creature->addInputFeature(new ObjectiveDirection(creature->getObjective().getYRef(), SIZE_IMAGE_W, creature->getPosition().getYRef()));
	creature->addOutputFeature(new Movement());
	creature->addOutputFeature(new Movement());
}

Position Controller::getSpawn(int number){
	MapObjective& mapObj = (MapObjective&) map;
	Position pos;
	double spawnX;
	double spawnY;

	/*do{
		spawnY = rand() % (NB_CASE_W-1);
		spawnX = rand() % (NB_CASE_H-1);
	}while(map.getCaseMaterial(spawnX, spawnY) == FoodMaterial::getInstance());

	pos = Position(spawnX*SIZE_IMAGE_H, spawnY*SIZE_IMAGE_W);*/

	spawnX = (mapObj.getObjective().getX() + 10*sin(number*((M_PI/10) + (M_PI/20))))*SIZE_IMAGE_H;
	spawnY = (mapObj.getObjective().getY() + 10*cos(number*((M_PI/10) + (M_PI/20))))*SIZE_IMAGE_W;
	pos = Position(spawnX, spawnY);
	return pos;
}

int Controller::getNbCrea() const{
	return nbCrea;
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

Controller::Controller(Map& map) : map(map), nbCrea(1), nbCreaMax(1){
	MapObjective& mapObj = (MapObjective&) map;
	Position pos;
	pos = Position(0, 0);
	creatures.push_back(new Creature(0, pos, mapObj.getObjective()));
}

void Controller::update(int speed){
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
