#include "CaseMap.hpp"

using namespace std;

CaseMap::CaseMap(){
	material = AirMaterial::getInstance();
}

CaseMap::~CaseMap(){
	delete material;
}

void CaseMap::setMaterial(Material* material){
	this->material = material;
}

Material* CaseMap::getMaterial(){
	return material;
}

/*void CaseMap::addObject(TypeObject type){
	switch(type){
		case OBJECT_FOOD:
			objects.push_back(ObjectFood(objects.size()));
			break;
		case OBJECT_WATER:
			objects.push_back(ObjectWater(objects.size()));
			break;
		default:
			throw BadMapObjectException("Bad type");
	}
}

void CaseMap::removeObject(ObjectMap object){
	vector<ObjectMap>::iterator it;
	it = find(objects.begin(), objects.end(), object);
	if(it != objects.end()){
		objects.erase(it);
	}
}
*/
