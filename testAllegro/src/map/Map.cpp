#include "Map.hpp"

Map::Map(int sizeX, int sizeY){
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	map = (CaseMap**) malloc(sizeX*(sizeof(CaseMap*)));
	for(int i = 0; i < sizeX; i++){
		cout << i << "a" << endl;
		map[i] = (CaseMap*) malloc(sizeY*(sizeof(CaseMap)));
		cout << "b" << endl;
		for(int j = 0; j < sizeY; j++){
			//cout << "i : " << i << ", j : " << j << endl;
			map[i][j] = CaseMap();
		}
	}
}

Map::~Map(){
	for(int i = 0; i < sizeX; i++){
		for(int j = 0; j < sizeY; j++){
			std::free(&map[i][j]);
		}
		std::free(map[i]);
	}
	delete[] map;
}

void Map::setCase(int x, int y, CaseMap c){
	map[x][y] = c;
}

void Map::setCaseMaterial(int x, int y, Material m){
	map[x][y].setMaterial(m);
}

void Map::addObject(int x, int y, TypeObject object){
	try{
		map[x][y].addObject(object);
	}
	catch(BadMapObjectException e){
		cout << "Object not added in Map" << endl;
		throw e;
	}
}
