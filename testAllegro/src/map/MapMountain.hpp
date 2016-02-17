#ifndef MAP_MOUNTAIN
#define MAP_MOUNTAIN

#include <iostream>
#include <string>
#include <vector>
#include "Map.hpp"

class MapMountain : public Map{

private:

public:
	MapMountain(int sizeX, int sizeY);
	void generate();
};

#endif
