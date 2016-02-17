#ifndef OBJECT_MAP
#define OBJECT_MAP

	#include <iostream>
	#include <string>
	#include <vector>
	#include "TypeObject.hpp"

	class ObjectMap{

	private:
		int id;

	public:
	    ObjectMap(int id);
		~ObjectMap();
		int getId();
		virtual TypeObject getType() = 0;

		bool operator==(ObjectMap const& other);
		bool operator!=(ObjectMap const& other);
	};

#endif
