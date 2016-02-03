#ifndef MAP
#define MAP

	#include <iostream>
	#include <string>
	#include <vector>
	#include "CaseMap.hpp"

	class Map{

	private:
		int sizeX, sizeY;
		CaseMap** map;

	public:
	    Map(int sizeX, int sizeY);
		void addCase(int x, int y, CaseMap c);
	};

#endif
