/**
*	@file FoodMaterial.cpp
*	Purpose : Define the behavior of the food material.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "FoodMaterial.hpp"

Material* FoodMaterial::instance = new FoodMaterial();

FoodMaterial::FoodMaterial() : Material(){}

FoodMaterial::~FoodMaterial(){
	//Material::~Material();
}

Material* FoodMaterial::getInstance(){
	if(instance == NULL){
		instance = new FoodMaterial();
	}
	return instance;
}

std::string FoodMaterial::getName(){
	return "Food";
}

bool FoodMaterial::isCrossable(){
	return true;
}

TypeMaterial FoodMaterial::getType(){
	return MATERIAL_FOOD;
}
