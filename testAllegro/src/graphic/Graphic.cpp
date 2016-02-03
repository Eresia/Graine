#include "Graphic.hpp"

using namespace std;

Graphic::Graphic(){

	ALLEGRO_DISPLAY *display = NULL;

   if(!al_init()) {
      cout << "failed to initialize allegro!\n" << endl;
      return ;
   }

   display = al_create_display(640, 480);
   if(!display) {
      cout << "failed to create display!\n" << endl;
      return ;
   }

   al_clear_to_color(al_map_rgb(0,0,0));

   al_flip_display();

   al_rest(10.0);

   al_destroy_display(display);
}
