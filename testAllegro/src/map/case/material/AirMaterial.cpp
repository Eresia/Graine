#include "AirMaterial.hpp"

AirMaterial::AirMaterial() : Material(){}

AirMaterial::~AirMaterial(){
	Material::~Material();
}

Material* AirMaterial::getInstance(){
	if(instance == NULL){
		instance = new AirMaterial();
	}
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
