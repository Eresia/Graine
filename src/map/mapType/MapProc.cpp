/**
*	@file MapProc.cpp
*	Purpose : Part of the procedurale generation of the map, currently holding water generation.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "MapProc.hpp"

using namespace std;

MapProc::MapProc(int sizeX, int sizeY) : Map(sizeX, sizeY){
	srand(std::time(0));
	generate();
}

void MapProc::generate(){
	int waterPosX = rand() % getSizeX();
	int waterPosY = rand() % getSizeY();

	setCaseMaterial(waterPosX, waterPosY, WaterMaterial::getInstance());
	expandWater(waterPosX, waterPosY, 4);
}

void MapProc::fullWater(int posX, int posY, int length){
	if((length != 0) && (posX > 0) && (posY > 0) && (posX < getSizeX()) && (posY < getSizeY())){
		if(getCaseMaterial(posX, posY) != WaterMaterial::getInstance()){
			int ifWater = rand() % 2;
			if(ifWater == 1){
				setCaseMaterial(posX, posY, WaterMaterial::getInstance());
				expandWater(posX, posY, length-1);
			}
		}
	}
}

void MapProc::expandWater(int posX, int posY, int length){
	fullWater(posX-1, posY, length);
	fullWater(posX+1, posY, length);
	fullWater(posX, posY+1, length);
	fullWater(posX, posY-1, length);
}
