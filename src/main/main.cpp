#include <vector>
#include "../graphic/Graphic.hpp"
#include "../map/Map.hpp"
#include "../map/mapType/MapProc.hpp"
#include "../evolution/Controller.hpp"
#include "../exception/WindowNotCreatedException.hpp"

using namespace std;

int main(int argc, char** argv){

	MapObjective map(NB_CASE_H,NB_CASE_W);
	int speed;

	#ifndef MANUAL_CREATURE
		Controller control(map, 4, 30);
		speed = 30;
	#else
		Controller control(map);
		speed = DEFAULT_SPEED;
	#endif


	try{
		Graphic* g = new Graphic(map, control, speed);
		g->display_loop();
		g->display_destroy();
		#ifndef MANUAL_CREATURE
			cout << control.getNbGen() << endl;
		#endif
	}
	catch(NotEnoughCreatureException e){
		cout << e.what() << endl;
	}
	catch(WindowNotCreatedException e){
		cout << e.what() << endl;
	}
	return 0;
}
