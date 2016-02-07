#include "../graphic/Graphic.hpp"
#include "../map/Map.hpp"

using namespace std;

int main(int argc, char** argv){

	Map* map = new Map(10,10);
	map->addObject(5,4,ObjectMap(0));
	/*Graphic* g = *///new Graphic();
	return 0;
}
