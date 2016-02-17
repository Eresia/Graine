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
