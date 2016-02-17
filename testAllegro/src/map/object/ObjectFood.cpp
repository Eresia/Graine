#include "ObjectFood.hpp"

ObjectFood::ObjectFood(int id) : ObjectMap(id){

}

TypeObject ObjectFood::getType(){
	return OBJECT_FOOD;
}
