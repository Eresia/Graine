#include "../graphic/Graphic.hpp"
#include "../map/Map.hpp"
#include "../exception/WindowNotCreatedException.hpp"

using namespace std;

int main(int argc, char** argv){

	Map* map = new Map(NB_CASE_H,NB_CASE_W);
	map->addObject(5,4, WATER);
	try{
		Graphic* g = new Graphic(map);
		g->display_map();
	}
	catch(WindowNotCreatedException e){
		cout << e.what() << endl;
	}
	return 0;
}
