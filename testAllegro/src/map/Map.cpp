#include "Map.hpp"

Map::Map(int sizeX, int sizeY){
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	map = (CaseMap**) malloc(sizeX*(sizeof(CaseMap*)));
	for(int i = 0; i < sizeX; i++){
		map[i] = (CaseMap*) malloc(sizeY*(sizeof(CaseMap)));
		for(int j = 0; j < sizeY; j++){
			map[i][j] = CaseMap();
		}
	}
}

void Map::setCase(int x, int y, CaseMap c){
	map[x][y] = c;
}

void Map::setCaseMaterial(int x, int y, Material m){
	map[x][y].setMaterial(m);
}

void Map::addObject(int x, int y, ObjectMap object){
	map[x][y].addObject(object);
}
