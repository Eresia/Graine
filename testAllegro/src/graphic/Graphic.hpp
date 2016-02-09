#ifndef GRAPHIC
#define GRAPHIC

	#include <iostream>
	#include <string>
	#include <allegro5/allegro.h>
	#include "../map/Map.hpp"

	#define HEIGHT 700 //Taille de la fenêtre
	#define WIDTH 1000
	#define NB_CASE_H 30
	#define NB_CASE_W 42

	class Graphic{

	private:


	public:
	    Graphic(Map map);

	};

#endif
