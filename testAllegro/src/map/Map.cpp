#include "Map.hpp"

Map::Map(int sizeX, int sizeY){
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	map = (CaseMap**) malloc(sizeX*(sizeof(CaseMap*)));
	for(int i = 0; i < sizeX; i++){
		map[i] = (CaseMap*) malloc(sizeY*(sizeof(CaseMap)));
		for(int j = 0; j < sizeY; j++){
			map[i][j] = NULL;
		}
	}
}

void Map::addCase(int x, int y, CaseMap c){

}
