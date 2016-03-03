#ifndef MAP
#define MAP

	#include <iostream>
	#include <string>
	#include <vector>
	#include "case/CaseMap.hpp"
	#include "Position.hpp"

	#define HEIGHT 700 //Taille de la Map
	#define WIDTH 1000
	#define NB_CASE_H 30
	#define NB_CASE_W 42

	#define SIZE_IMAGE_W ((double) (WIDTH)/ (double) (NB_CASE_W))
	#define SIZE_IMAGE_H ((double) (HEIGHT)/(double) (NB_CASE_H))

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
		CaseMap getCase(int x, int y);
		void setCaseMaterial(int x, int y, Material* m);
		Material* getCaseMaterial(int x, int y);

		bool onSpecialCase(Position pos, TypeMaterial m);
		bool onSpecialCase(int x, int y, TypeMaterial m);

		CaseMap** getMap();
		int getSizeX();
		int getSizeY();
	};

#endif
