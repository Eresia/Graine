/**
*	@file CaseMap.cpp
*	Purpose : Define the differente cases of the map (dirt component).
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "CaseMap.hpp"

using namespace std;

CaseMap::CaseMap(){
	material = DirtMaterial::getInstance();
}

CaseMap::~CaseMap(){

}

void CaseMap::setMaterial(Material* material){
	this->material = material;
}

Material* CaseMap::getMaterial(){
	return material;
}

//!< @deprecated
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

//!< @deprecated
void CaseMap::removeObject(ObjectMap object){
	vector<ObjectMap>::iterator it;
	it = find(objects.begin(), objects.end(), object);
	if(it != objects.end()){
		objects.erase(it);
	}
}
*/
