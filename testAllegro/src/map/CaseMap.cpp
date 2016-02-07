#include "CaseMap.hpp"

using namespace std;

CaseMap::CaseMap(){
	material = NOTHING;
	std::cout << this->objects.size() << std::endl;
}

void CaseMap::setMaterial(Material material){
	this->material = material;
}

void CaseMap::addObject(TypeObject type){
	/*swich(TypeObject){
		case
	}*/
}

void CaseMap::removeObject(ObjectMap object){
	vector<ObjectMap>::iterator it;
	it = find(objects.begin(), objects.end(), object);
	if(it != objects.end()){
		objects.erase(it);
	}
}
