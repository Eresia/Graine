/**
*	@file main.cpp
*	Purpose : Just the main function, call Graphic functions.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include <vector>
#include "../graphic/Graphic.hpp"
#include "../map/Map.hpp"
#include "../map/mapType/MapProc.hpp"
#include "../evolution/Controller.hpp"
#include "../exception/WindowNotCreatedException.hpp"
#include "../generation/Generation.hpp"

using namespace std;

int main(int argc, char** argv){

	MapObjective map(NB_CASE_H,NB_CASE_W);
	int speed;

	#ifndef MANUAL_CREATURE
		Controller control(map, NB_CREA, NB_CREA_MAX, TURN_MAX);
		speed = 1;
	#else
		Controller control(map);
		speed = DEFAULT_SPEED;
	#endif


	try{
		Graphic* g = new Graphic(map, control, speed);
		g->display_loop();
		g->display_destroy();
		#if defined(TEST_PROBA) && !defined(NB_GEN_MAX)
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
