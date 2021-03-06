/**
*	@file DirtMaterial.cpp
*	Purpose : Define the behavior of the dirt material.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "DirtMaterial.hpp"

Material* DirtMaterial::instance = new DirtMaterial();

DirtMaterial::DirtMaterial() : Material(){}

DirtMaterial::~DirtMaterial(){
	//Material::~Material();
}

Material* DirtMaterial::getInstance(){
	if(instance == NULL){
		instance = new DirtMaterial();
	}
	return instance;
}

std::string DirtMaterial::getName(){
	return "Dirt";
}

bool DirtMaterial::isCrossable(){
	return true;
}

TypeMaterial DirtMaterial::getType(){
	return MATERIAL_DIRT;
}
