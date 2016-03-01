#include "Controller.hpp"

using namespace std;

Controller::Controller(Map& map, int nbCrea, int turnMax) : map(map), nbCrea(nbCrea), nbCreaMax(nbCrea*nbCrea), turn(0), turnMax(turnMax), idCounter(0){

	if(nbCrea < 2){
		throw NotEnoughCreatureException("More one creature expected, " + to_string(nbCrea) + " given");
	}

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

		for(int i = 0; i < nbCreaMax; i++){
			creatures[i]->getPosition() -= obj;
		}

		partial_sort(creatures.begin(), creatures.begin() + nbCrea, creatures.end(), Creature::comparePosition);
		
		turn = 0;
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
