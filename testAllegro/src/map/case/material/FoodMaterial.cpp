#include "FoodMaterial.hpp"

FoodMaterial::FoodMaterial() : Material(){}

FoodMaterial::~FoodMaterial(){
	Material::~Material();
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
