#include "ObjectiveDirection.hpp"

ObjectiveDirection::ObjectiveDirection(double& objective, int mult, double& creature) : objective(objective), creature(creature), mult(mult){

}

void ObjectiveDirection::update(){
	value = ((double) (objective*mult)) - creature;
}
