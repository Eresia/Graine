#include "CaseMap.hpp"
#include <iostream>

CaseMap::CaseMap(){
	material = NOTHING;
	std::cout << this->objects.size() << std::endl;
}

void CaseMap::setMaterial(Material material){
	this->material = material;
}
