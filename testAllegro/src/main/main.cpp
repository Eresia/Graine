#include "../graphic/Graphic.hpp"
#include "../map/Map.hpp"
#include "../map/MapMountain.hpp"
#include "../creature/Creature.hpp"
#include "../exception/WindowNotCreatedException.hpp"

using namespace std;

int main(int argc, char** argv){

	Map* map = new MapMountain(NB_CASE_H,NB_CASE_W);
	double spawnX = map->getSpawn().getX();
	double spawnY = map->getSpawn().getY();
	Position pos(spawnX*SIZE_IMAGE_H, spawnY*SIZE_IMAGE_W);
	Creature* crea = new Creature(pos, 10);
	try{
		Graphic* g = new Graphic(map, crea);
		g->display_loop();
		g->display_destroy();
	}
	catch(WindowNotCreatedException e){
		cout << e.what() << endl;
	}
	return 0;
}
