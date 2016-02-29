#ifndef FOOD_MATERIAL
#define FOOD_MATERIAL

#include <string>
#include "Material.hpp"

class FoodMaterial : public Material {

	private:
		static Material* instance;

	public:
		FoodMaterial();
		virtual ~FoodMaterial();
		static Material* getInstance();
		virtual std::string getName();
		virtual bool isCrossable();
		virtual TypeMaterial getType();
};

#endif
