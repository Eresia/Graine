#ifndef MATERIAL
#define MATERIAL

#include <iostream>
#include <string>

enum TypeMaterial : int {MATERIAL_AIR, MATERIAL_DIRT, MATERIAL_WATER, MATERIAL_FOOD};

class Material{

	private:

	public:
		Material();
		virtual ~Material();
		bool operator== (const Material&);
		virtual std::string getName()= 0;
		virtual bool isCrossable() = 0;
		virtual TypeMaterial getType() = 0;


};

#endif
