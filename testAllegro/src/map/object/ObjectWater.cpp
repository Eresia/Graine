#include "ObjectWater.hpp"

ObjectWater::ObjectWater(int id) : ObjectMap(id){

}

TypeObject ObjectWater::getType(){
	return OBJECT_WATER;
}
