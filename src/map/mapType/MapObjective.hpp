#ifndef MAP_OBJECTIVE
#define MAP_OBJECTIVE

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../Map.hpp"
#include "../case/material/FoodMaterial.hpp"

class MapObjective : public Map{

	private:
		Position objective;

	public:
		MapObjective(int sizeX, int sizeY);
		void generate();
		Position getObjective();
	};

#endif
