#ifndef OBJECT_FOOD_HPP
#define OBJECT_FOOD_HPP

#include <iostream>
#include <string>
#include "ObjectMap.hpp"

class ObjectFood : public ObjectMap{

	private:

	public:
		ObjectFood(int id);
		virtual TypeObject getType();
};

#endif
