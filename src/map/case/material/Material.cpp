/**
*	@file Material.cpp
*	Purpose : Material class to get materials.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "Material.hpp"

Material::Material() {}

Material::~Material(){

}

std::string Material::getName(){
	return "Material";
}

/*Material* Material::getInstance(){
	if(instance == NULL){
		instance = getMaterial();
	}
	return instance;
}*/
