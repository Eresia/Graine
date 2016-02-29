#ifndef MAP_PROC
#define MAP_PROC

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../Map.hpp"
#include "../case/material/WaterMaterial.hpp"
#include "../case/material/FoodMaterial.hpp"

class MapProc : public Map{

	private:
		void fullWater(int posX, int posY, int length);
		void expandWater(int posX, int posY, int length);

	public:
		MapProc(int sizeX, int sizeY);
		void generate();
};

#endif
