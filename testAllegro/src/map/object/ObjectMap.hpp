#ifndef OBJECT_MAP
#define OBJECT_MAP

	#include <iostream>
	#include <string>
	#include <vector>

	class ObjectMap{

	private:
		int id;

	public:
	    ObjectMap(int id);
		~ObjectMap();
		int getId();

		bool operator==(ObjectMap const& other);
		bool operator!=(ObjectMap const& other);
	};

#endif
