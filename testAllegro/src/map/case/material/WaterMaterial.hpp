#ifndef WATER_MATERIAL
#define WATER_MATERIAL

#include <string>
#include "Material.hpp"

class WaterMaterial : public Material {

	private:

	public:
		WaterMaterial();
		virtual ~WaterMaterial();
		static Material* getInstance();
		virtual std::string getName();
		virtual bool isCrossable();
		virtual TypeMaterial getType();
};

#endif
