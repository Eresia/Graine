#ifndef MAP
#define MAP

	#include <iostream>
	#include <string>
	#include <vector>
	#include "case/CaseMap.hpp"

	class Map{

	private:
		int sizeX, sizeY;
		CaseMap** map;

	public:
	    //Map(int sizeX, int sizeY, void (Map::*generate)(int sizeX, int sizeY, CaseMap** map));
		Map(int sizeX, int sizeY);
		~Map();
		virtual void generate() = 0;
		void setCase(int x, int y, CaseMap c);
		void setCaseMaterial(int x, int y, Material* m);
		//void addObject(int x, int y, TypeObject object);
	};

#endif
