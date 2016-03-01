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
	objective = Position(objectiveX, objectiveY);
}

Position MapObjective::getObjective(){
	return objective;
}
