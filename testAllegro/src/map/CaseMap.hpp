#ifndef CASE_MAP
#define CASE_MAP

	#include <string>
	#include <vector>
	#include "ObjectMap.hpp"
	#include "Material.hpp"

	class CaseMap{

	private:
		std::vector<ObjectMap> objects;
		Material material;

	public:
	    CaseMap();
		void setMaterial(Material material);
	};

#endif
