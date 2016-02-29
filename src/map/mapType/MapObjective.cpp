#include "MapObjective.hpp"

using namespace std;

MapObjective::MapObjective(int sizeX, int sizeY) : Map(sizeX, sizeY){
	srand(std::time(0));
	generate();
}

void MapObjective::generate(){
	int objectiveX = rand() % getSizeX();
	int objectiveY = rand() % getSizeY();

	setCaseMaterial(objectiveX, objectiveY, FoodMaterial::getInstance());
	objective = Position(objectiveX, objectiveY);
}

Position MapObjective::getObjective(){
	return objective;
}
