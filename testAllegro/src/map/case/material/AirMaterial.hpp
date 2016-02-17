#ifndef AIR_MATERIAL
#define AIR_MATERIAL

#include <string>
#include "Material.hpp"

class AirMaterial : public Material {

	private:

	public:
		AirMaterial();
		virtual ~AirMaterial();
		static Material* getInstance();
		virtual std::string getName();
		virtual bool isCrossable();
		virtual TypeMaterial getType();
};

#endif
