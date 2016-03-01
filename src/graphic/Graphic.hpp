#ifndef GRAPHIC
#define GRAPHIC

	#include <iostream>
	#include <string>
	#include <allegro5/allegro.h>
	#include <allegro5/allegro_image.h>
	#include "allegro5/allegro_native_dialog.h"
	#include <map>
	#include "../map/Map.hpp"
	#include "../map/mapType/MapObjective.hpp"
	#include "../evolution/Controller.hpp"
	#include "../map/Position.hpp"
	#include "../exception/WindowNotCreatedException.hpp"
	#include "../exception/EventListNotCreatedException.hpp"

	class Graphic{

		private:
			Map& map;
			Controller& control;
			ALLEGRO_DISPLAY *display;
			std::map<TypeMaterial, ALLEGRO_BITMAP*> textures;
			ALLEGRO_BITMAP* creatTexture;

		public:
		    Graphic(Map& map, Controller& control);
			void display_map();
			void display_loop();
			void display_destroy();
	};

#endif
