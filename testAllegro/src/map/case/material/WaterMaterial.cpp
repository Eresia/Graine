#include "WaterMaterial.hpp"

WaterMaterial::WaterMaterial() : Material(){}

WaterMaterial::~WaterMaterial(){
	Material::~Material();
}

Material* WaterMaterial::getInstance(){
	if(instance == NULL){
		instance = new WaterMaterial();
	}
	return instance;
}

std::string WaterMaterial::getName(){
	return "Water";
}

bool WaterMaterial::isCrossable(){
	return true;
}

TypeMaterial WaterMaterial::getType(){
	return MATERIAL_WATER;
}
