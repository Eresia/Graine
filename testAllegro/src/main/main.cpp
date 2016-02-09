#include "../graphic/Graphic.hpp"
#include "../map/Map.hpp"

using namespace std;

int main(int argc, char** argv){

	Map* map = new Map(NB_CASE_H,NB_CASE_W);
	map->addObject(5,4, WATER);
	/*Graphic* g = *///new Graphic();
	return 0;
}
