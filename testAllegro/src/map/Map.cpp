#include "Map.hpp"

Map::Map(int sizeX, int sizeY){
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	map = (CaseMap**) malloc(sizeX*(sizeof(CaseMap*)));
	for(int i = 0; i < sizeX; i++){
		map[i] = new CaseMap[sizeY];
		for(int j = 0; j < sizeY; j++){
			map[i][j] = CaseMap();
		}
	}
	spawn = Position();
	//generate(sizeX, sizeY, map);
}

Map::~Map(){
	for(int i = 0; i < sizeX; i++){
		for(int j = 0; j < sizeY; j++){
			delete &map[i][j];
		}
		std::free(map[i]);
	}
	delete[] map;
}

void Map::setCase(int x, int y, CaseMap c){
	map[x][y] = c;
}

CaseMap Map::getCase(int x, int y){
	return map[x][y];
}

void Map::setCaseMaterial(int x, int y, Material* m){
	map[x][y].setMaterial(m);
}

Material* Map::getCaseMaterial(int x, int y){
	return map[x][y].getMaterial();
}

CaseMap** Map::getMap(){
	return map;
}

int Map::getSizeX(){
	return sizeX;
}

int Map::getSizeY(){
	return sizeY;
}

void Map::setSpawn(int x, int y){
	spawn.setPosition(x, y);
}

Position* Map::getSpawn(){
	return &spawn;
}
