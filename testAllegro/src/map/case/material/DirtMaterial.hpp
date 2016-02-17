#ifndef DIRT_MATERIAL
#define DIRT_MATERIAL

#include <string>
#include "Material.hpp"

class DirtMaterial : public Material {

	private:

	public:
		DirtMaterial();
		virtual ~DirtMaterial();
		static Material* getInstance();
		virtual std::string getName();
		virtual bool isCrossable();
		virtual TypeMaterial getType();
};

#endif
