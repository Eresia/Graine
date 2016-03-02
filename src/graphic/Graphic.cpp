#include "Graphic.hpp"

using namespace std;

Graphic::Graphic(Map& map, Controller& control, int simSpeed) : map(map), control(control), simSpeed(simSpeed), actualiseGraphic(AUTO_AFFICHAGE){

	display = NULL;

	#ifndef TEST_PROBA

		if(!al_init() || !al_init_image_addon()) {
			throw WindowNotCreatedException("Failed to initialize allegro !");
		}

		al_init_font_addon(); // initialize the font addon
		al_init_ttf_addon();// initialize the ttf (True Type Font) addon

		font = al_load_ttf_font("font/CollegiateInsideFLF.ttf",6,0 );

		if (!font){
			throw WindowNotCreatedException("Failed to initialize font !");
		}

		if(!al_install_keyboard()) {
			throw WindowNotCreatedException("Failed to initialize keyboard !");
		}

		textures[MATERIAL_AIR] = al_load_bitmap("images/sky.bmp");
		textures[MATERIAL_DIRT] = al_load_bitmap("images/dirt.bmp");
		textures[MATERIAL_FOOD] = al_load_bitmap("images/apple.bmp");
		textures[MATERIAL_WATER] = al_load_bitmap("images/water.bmp");
		creatTexture = al_load_bitmap("images/creature.bmp");

		for(std::map<TypeMaterial, ALLEGRO_BITMAP*>::iterator it=textures.begin() ; it!=textures.end() ; ++it)
		{
			if(!it->second){
				throw WindowNotCreatedException("Failed to load image " + to_string(it->first) + " !");
			}
		}

		if(!creatTexture){
			throw WindowNotCreatedException("Failed to load image of creature !");
		}

		display = al_create_display(WIDTH, HEIGHT);
		if(!display) {
			throw WindowNotCreatedException("Failed to create display !");
		}

	#endif

}

void Graphic::display_map(){
	al_flip_display();
	int widthCrea = al_get_bitmap_width(creatTexture);
	int heigthCrea = al_get_bitmap_height(creatTexture);

	for(int i = 0; i < NB_CASE_H; i++){
		for(int j = 0; j < NB_CASE_W; j++){
			TypeMaterial type = map.getCase(i, j).getMaterial()->getType();
			int w = al_get_bitmap_width(textures[type]);
			int h = al_get_bitmap_height(textures[type]);
			al_draw_scaled_bitmap(textures[type], 0, 0, w, h, SIZE_IMAGE_W*j, SIZE_IMAGE_H*i, SIZE_IMAGE_W, SIZE_IMAGE_H, 0);

			#ifdef DRAW_POS_ON_MAP
				string text = "(" + to_string(i) + "," + to_string(j) + ")";
				al_draw_text(font, al_map_rgb(0,0,0), SIZE_IMAGE_W*j, SIZE_IMAGE_H*i ,ALLEGRO_ALIGN_LEFT, text.c_str());
			#endif
			//al_draw_sprite(textures[type], display, sizeImageW*j, sizeImageH*i);
		}
	}

	for(int i = 0; i < control.getNbCreaMax(); i++){
		Position posCrea;
		posCrea = control.getPositionCrea(i);
		al_draw_rotated_bitmap(creatTexture, widthCrea/2, heigthCrea/2, posCrea.getY(), posCrea.getX(), control.getRotationCrea(i),0);

		#ifdef DRAW_POS_ON_MAP
			string text = "(" + to_string((int) (posCrea.getX() / SIZE_IMAGE_H)) + "," + to_string((int) (posCrea.getY() / SIZE_IMAGE_W)) + ")";
			al_draw_text(font, al_map_rgb(0,0,0), posCrea.getY(), posCrea.getX(),ALLEGRO_ALIGN_LEFT, text.c_str());
		#endif
		//al_flip_display();
	}
}

void Graphic::display_loop(){

	bool close = false;

	#ifndef TEST_PROBA
		ALLEGRO_EVENT_QUEUE* queue;
		queue = al_create_event_queue();
		if (!queue){
			throw EventListNotCreatedException("");
		}
		al_register_event_source(queue, al_get_display_event_source(display));
		al_register_event_source(queue, al_get_keyboard_event_source());
	#endif
	while(!close){

		#ifndef TEST_PROBA
			ALLEGRO_EVENT event = { 0 };
			al_wait_for_event_timed(queue, &event, 1.0 / 1000);
			if(actualiseGraphic){
				display_map();
			}

			if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
				close = true;
			}
			else if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch(event.keyboard.keycode) {
					case ALLEGRO_KEY_ESCAPE:
						close = true;
						break;

					case ALLEGRO_KEY_ENTER:
						actualiseGraphic = !actualiseGraphic;
						break;

					#ifdef MANUAL_CREATURE

						case ALLEGRO_KEY_UP:
							control.update(10);
							break;

							case ALLEGRO_KEY_DOWN:
								control.update(-10);
								break;

						case ALLEGRO_KEY_LEFT:
							control.update(ROTATE_LEFT);
							break;

						case ALLEGRO_KEY_RIGHT:
							control.update(ROTATE_RIGHT);
							break;

					#endif
				}
			}
		#endif

		if(!close){
			control.update();
			if(control.doneObjective()){
				/*while(1){
					display_map();
					sleep(1);
				}*/
				#ifdef TEST_PROBA
					close = true;
				#endif
			}
			usleep(simSpeed);
		}
	}

}

void Graphic::display_destroy(){
	al_destroy_display(display);
}
