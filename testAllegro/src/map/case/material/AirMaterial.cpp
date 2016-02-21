#include "AirMaterial.hpp"

Material* AirMaterial::instance = new AirMaterial();

AirMaterial::AirMaterial() : Material(){}

AirMaterial::~AirMaterial(){
	//Material::~Material();
}

Material* AirMaterial::getInstance(){
	return instance;
}

std::string AirMaterial::getName(){
	return "Air";
}

bool AirMaterial::isCrossable(){
	return true;
}

TypeMaterial AirMaterial::getType(){
	return MATERIAL_AIR;
}
