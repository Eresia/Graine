#ifndef DIRT_MATERIAL
#define DIRT_MATERIAL

#include <string>
#include "Material.hpp"

class DirtMaterial : public Material {

	private:
		static Material* instance;

	public:
		DirtMaterial();
		virtual ~DirtMaterial();
		static Material* getInstance();
		virtual std::string getName();
		virtual bool isCrossable();
		virtual TypeMaterial getType();
};

#endif
