#include "Controller.hpp"

using namespace std;

Controller::Controller(Map& map, int nbCrea, int turnMax) : map(map), nbCrea(nbCrea), nbCreaMax(nbCrea*(nbCrea - 1)), turn(0), turnMax(turnMax), idCounter(0){

	if(nbCrea < MIN_CREA){
		throw NotEnoughCreatureException(to_string(MIN_CREA) + " or more creature expected, " + to_string(nbCrea) + " given");
	}

	createCreatures();
}

void Controller::update(){
	MapObjective& mapObj = (MapObjective&) map;
	Position obj(mapObj.getObjective().getX()*SIZE_IMAGE_H, mapObj.getObjective().getY()*SIZE_IMAGE_W);
	if(turn < turnMax){

		for(int i = 0; i < nbCreaMax; i++){
			double x = obj.getX() - creatures[i]->getPosition().getX();
			double y = obj.getY() - creatures[i]->getPosition().getY();
			creatures[i]->think(x, y);
		}
		turn++;
	}
	else{
		vector<NeuronNetwork> bestBrains;
		vector<NeuronNetwork> newBrains;
		Evolution* evolution;
		for(int i = 0; i < nbCreaMax; i++){
			creatures[i]->getPosition() -= obj;
		}

		partial_sort(creatures.begin(), creatures.begin() + nbCrea, creatures.end(), Creature::comparePosition);
		for(int i = 0; i < nbCrea; i++){
			bestBrains.push_back(creatures[i]->getBrain());
		}
		evolution = new Evolution(bestBrains);
		newBrains = evolution->evolve();
		createCreatures(newBrains);
		turn = 0;
	}
}

void Controller::createCreatures(){
	creatures.clear();
	for(int i = 0; i < nbCreaMax; i++){
		double spawnX;
		double spawnY;
		Position pos;
		Creature* crea;

		do{
			spawnY = rand() % (NB_CASE_W-1);
			spawnX = rand() % (NB_CASE_H-1);
		}while(map.getCaseMaterial(spawnX, spawnY) == FoodMaterial::getInstance());

		pos = Position(spawnX*SIZE_IMAGE_H, spawnY*SIZE_IMAGE_W);
		crea = new Creature(idCounter, pos);
		idCounter++;
		creatures.push_back(crea);
	}
}

void Controller::createCreatures(vector<NeuronNetwork> brains){
	if((int) brains.size() != nbCreaMax){
		throw NotEnoughCreatureException("Evolution failed, " + to_string(brains.size()) + " brains given, " + to_string(nbCreaMax) + " attempt");
	}

	creatures.clear();
	for(int i = 0; i < nbCreaMax; i++){
		double spawnX;
		double spawnY;
		Position pos;
		Creature* crea;

		do{
			spawnY = rand() % (NB_CASE_W-1);
			spawnX = rand() % (NB_CASE_H-1);
		}while(map.getCaseMaterial(spawnX, spawnY) == FoodMaterial::getInstance());

		pos = Position(spawnX*SIZE_IMAGE_H, spawnY*SIZE_IMAGE_W);
		crea = new Creature(idCounter, pos, brains[i]);
		idCounter++;
		creatures.push_back(crea);
	}

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
