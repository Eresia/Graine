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

Map::~Map(){
	for(int i = 0; i < sizeX; i++){
		for(int j = 0; j < sizeY; j++){
			//delete map[i][j];
			std::free(&map[i][j]);
		}
		std::free(map[i]);
	}
	delete[] map;
	std::free(&sizeX);
	std::free(&sizeY);
}

void Map::setCase(int x, int y, CaseMap c){
	map[x][y] = c;
}

void Map::setCaseMaterial(int x, int y, Material m){
	map[x][y].setMaterial(m);
}

void Map::addObject(int x, int y, TypeObject object){
	map[x][y].addObject(object);
}
