/**
*	@file MapObjective.cpp
*	Purpose : Define the food objective on the map.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "MapObjective.hpp"

using namespace std;

MapObjective::MapObjective(int sizeX, int sizeY) : Map(sizeX, sizeY){
	srand(std::time(0));
	generate();
}

void MapObjective::generate(){
	//int objectiveX = rand() % getSizeX();
	//int objectiveY = rand() % getSizeY();
	int objectiveX = getSizeX() / 2;
	int objectiveY = getSizeY() / 2;

	setCaseMaterial(objectiveX, objectiveY, FoodMaterial::getInstance());
	objective = new Position(objectiveX, objectiveY);
}

Position& MapObjective::getObjective(){
	return *objective;
}
