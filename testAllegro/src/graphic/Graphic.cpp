#include "Graphic.hpp"

using namespace std;

Graphic::Graphic(Map* map){

	display = NULL;
	this->map = map;

	if(!al_init()) {
		throw WindowNotCreatedException("Failed to initialize allegro !");
	}

	textures["sky"] = al_load_bitmap("images/sky.bmp");
	textures["dirt"] = al_load_bitmap("images/dirt.bmp");

	if(!textures["sky"] || !textures["dirt"]){
		throw WindowNotCreatedException("Failed to load images !");
	}

	display = al_create_display(WIDTH, HEIGHT);
	if(!display) {
		throw WindowNotCreatedException("Failed to create display !");
	}

}

void Graphic::display_map(){

	double sizeImageW = WIDTH/NB_CASE_W;
	double sizeImageH = HEIGHT/NB_CASE_H;

	for(int i = 0; i < NB_CASE_H; i++){
		for(int j = 0; j < NB_CASE_W; j++){
			//blit(sky, display,0,0, (sizeImageW*i), (sizeImageH*j), sizeImageW, sizeImageH);
			al_draw_bitmap(textures["sky"], (sizeImageW*i), (sizeImageH*j),  0);
		}
	}

	al_flip_display();

	al_rest(10.0);

	al_destroy_display(display);
}
