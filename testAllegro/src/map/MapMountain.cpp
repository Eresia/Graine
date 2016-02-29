#include "MapMountain.hpp"

using namespace std;

MapMountain::MapMountain(int sizeX, int sizeY) : Map(sizeX, sizeY){
	srand(std::time(0));
	generate();
}

void MapMountain::generate(){
	int waterPosX = rand() % getSizeX();
	int waterPosY = rand() % getSizeY();
	int spawnPosX;
	int spawnPosY;

	setCaseMaterial(waterPosX, waterPosY, WaterMaterial::getInstance());
	expandWater(waterPosX, waterPosY, 4);

	do{
		spawnPosX = rand() % getSizeX();
		spawnPosY = rand() % getSizeY();
	}while(getCaseMaterial(spawnPosX, spawnPosY) == WaterMaterial::getInstance());
	setSpawn(spawnPosX, spawnPosY);
}

void MapMountain::fullWater(int posX, int posY, int length){
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

void MapMountain::expandWater(int posX, int posY, int length){
	fullWater(posX-1, posY, length);
	fullWater(posX+1, posY, length);
	fullWater(posX, posY+1, length);
	fullWater(posX, posY-1, length);
}
