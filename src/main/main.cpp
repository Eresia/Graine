#include <vector>
#include "../graphic/Graphic.hpp"
#include "../map/Map.hpp"
#include "../map/mapType/MapProc.hpp"
#include "../evolution/Controller.hpp"
#include "../exception/WindowNotCreatedException.hpp"

using namespace std;

int main(int argc, char** argv){

	MapObjective map(NB_CASE_H,NB_CASE_W);

	try{
		Controller control(map, 2, 10);
		Graphic* g = new Graphic(map, control);
		g->display_loop();
		g->display_destroy();
	}
	catch(NotEnoughCreatureException e){
		cout << e.what() << endl;
	}
	catch(WindowNotCreatedException e){
		cout << e.what() << endl;
	}
	return 0;
}
