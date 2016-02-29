#ifndef MAP_MOUNTAIN
#define MAP_MOUNTAIN

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Map.hpp"
#include "case/material/WaterMaterial.hpp"
#include "case/material/FoodMaterial.hpp"

class MapMountain : public Map{

private:
	void fullWater(int posX, int posY, int length);
	void expandWater(int posX, int posY, int length);

public:
	MapMountain(int sizeX, int sizeY);
	void generate();
};

#endif
