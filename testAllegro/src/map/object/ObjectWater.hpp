#ifndef OBJECT_WATER_HPP
#define OBJECT_WATER_HPP

#include <iostream>
#include <string>
#include "ObjectMap.hpp"

class ObjectWater : public ObjectMap{

	private:

	public:
		ObjectWater(int id);
		virtual TypeObject getType();
};

#endif
