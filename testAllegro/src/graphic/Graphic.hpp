#ifndef GRAPHIC
#define GRAPHIC

	#include <iostream>
	#include <string>
	#include <allegro5/allegro.h>
	#include <map>
	#include "../map/Map.hpp"
	#include "../exception/WindowNotCreatedException.hpp"

	#define HEIGHT 700 //Taille de la fenêtre
	#define WIDTH 1000
	#define NB_CASE_H 30
	#define NB_CASE_W 42

	class Graphic{

		Map* map;
		ALLEGRO_DISPLAY *display;
		std::map<std::string, ALLEGRO_BITMAP*> textures;

	private:


	public:
	    Graphic(Map* map);
		void display_map();
	};

#endif
