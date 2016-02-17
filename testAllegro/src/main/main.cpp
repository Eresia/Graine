#include "../graphic/Graphic.hpp"
#include "../map/Map.hpp"
#include "../map/MapMountain.hpp"
#include "../exception/WindowNotCreatedException.hpp"

using namespace std;

int main(int argc, char** argv){

	Map* map = new MapMountain(NB_CASE_H,NB_CASE_W);
	try{
		Graphic* g = new Graphic(map);
		g->display_map();
	}
	catch(WindowNotCreatedException e){
		cout << e.what() << endl;
	}
	return 0;
}
