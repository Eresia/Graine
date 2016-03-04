/**
*	@file WaterMaterial.cpp
*	Purpose : Define the behavior of the water material
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "WaterMaterial.hpp"

Material* WaterMaterial::instance = new WaterMaterial();

WaterMaterial::WaterMaterial() : Material(){}

WaterMaterial::~WaterMaterial(){
	//Material::~Material();
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
