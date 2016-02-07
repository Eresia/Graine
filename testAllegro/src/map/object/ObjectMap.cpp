#include "ObjectMap.hpp"

ObjectMap::ObjectMap(int id){
	this->id = id;
}

int ObjectMap::getId(){
	return id;
}

bool ObjectMap::operator==(ObjectMap const& other){
	return (id == other.id);
}

bool ObjectMap::operator!=(ObjectMap const& other){
	return !(id == other.id);
}
