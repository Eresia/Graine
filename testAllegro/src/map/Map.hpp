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
		~Map();
		void setCase(int x, int y, CaseMap c);
		void setCaseMaterial(int x, int y, Material m);
		void addObject(int x, int y, TypeObject object);
	};

#endif
