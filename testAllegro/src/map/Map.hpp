#ifndef MAP
#define MAP

	#include <iostream>
	#include <string>
	#include <vector>
	#include "case/CaseMap.hpp"
	#include "Position.hpp"

	class Map{

	private:
		int sizeX, sizeY;
		CaseMap** map;
		Position spawn;

	public:
	    //Map(int sizeX, int sizeY, void (Map::*generate)(int sizeX, int sizeY, CaseMap** map));
		Map(int sizeX, int sizeY);
		~Map();
		virtual void generate() = 0;
		void setCase(int x, int y, CaseMap c);
		CaseMap getCase(int x, int y);
		void setCaseMaterial(int x, int y, Material* m);
		Material* getCaseMaterial(int x, int y);

		CaseMap** getMap();
		int getSizeX();
		int getSizeY();
		void setSpawn(int x, int y);
		Position* getSpawn();
	};

#endif
