#include <vector>
#include "../graphic/Graphic.hpp"
#include "../map/Map.hpp"
#include "../map/mapType/MapProc.hpp"
#include "../creature/Creature.hpp"
#include "../exception/WindowNotCreatedException.hpp"

using namespace std;

int main(int argc, char** argv){

	MapObjective map(NB_CASE_H,NB_CASE_W);
	vector<Creature> creatures;

	for(int i = 0; i < 1; i++){
		double spawnX;
		double spawnY;
		Position pos;

		do{
			spawnX = rand() % map.getSizeX();
			spawnY = rand() % map.getSizeY();
		}while(map.getCaseMaterial(spawnX, spawnY) == FoodMaterial::getInstance());

		pos = Position(spawnX*SIZE_IMAGE_H, spawnY*SIZE_IMAGE_W);
		creatures.push_back(Creature(pos, 10));
	}

	try{
		Graphic* g = new Graphic(map, creatures);
		g->display_loop();
		g->display_destroy();
	}
	catch(WindowNotCreatedException e){
		cout << e.what() << endl;
	}
	return 0;
}
