/**
*	@file AirMaterial.cpp
*	Purpose : Define the behavior of the air material.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
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
