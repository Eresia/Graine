#ifndef OBJECT_FOOD
#define OBJECT_FOOD

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
