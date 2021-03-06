/**
*	@file Map.cpp
*	Purpose : Map size and materials definition class.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "Map.hpp"

Map::Map(int sizeX, int sizeY){
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	map = new CaseMap*[sizeX];
	for(int i = 0; i < sizeX; i++){
		map[i] = new CaseMap[sizeY];
	}
}

Map::~Map(){
	/*for(int i = 0; i < sizeX; i++){
		for(int j = 0; j < sizeY; j++){
			delete &map[i][j];
		}
		std::free(map[i]);
	}
	delete[] map;*/
}

bool Map::onSpecialCase(Position pos, TypeMaterial m){
	return onSpecialCase(pos.getX(), pos.getY(), m);
}

bool Map::onSpecialCase(int x, int y, TypeMaterial m){
	if((x < 0) || (x >= NB_CASE_H) || (y < 0) || (y >= NB_CASE_W)){
		return false;
	}
	return (map[x][y].getMaterial()->getType() == m);
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
