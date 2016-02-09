#include "Graphic.hpp"

using namespace std;

Graphic::Graphic(Map map){

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP* sky, *dirt;
	double sizeImageW = WIDTH/NB_CASE_W;
	double sizeImageH = HEIGHT/NB_CASE_H;

	if(!al_init()) {
		cout << "failed to initialize allegro!\n" << endl;
		return ;
	}

	sky = al_load_bitmap("images/sky.bmp");
	dirt = al_load_bitmap("images/dirt.bmp");

	if(!sky || !dirt){
		cout << "failed to load images!\n" << endl;
		return ;
	}

	display = al_create_display(WIDTH, HEIGHT);
	if(!display) {
		cout << "failed to create display!\n" << endl;
		return ;
	}

	for(int i = 0; i < NB_CASE_H; i++){
		for(int j = 0; j < NB_CASE_W; j++){
			//blit(sky, display,0,0, (sizeImageW*i), (sizeImageH*j), sizeImageW, sizeImageH);
		}
	}

	al_flip_display();

	al_rest(10.0);

	al_destroy_display(display);
}
