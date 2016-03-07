/**
*	@file ObjectiveDirection.cpp
*	Purpose : Define the direction of the objective to go to.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "ObjectiveDirection.hpp"

ObjectiveDirection::ObjectiveDirection(double& objective, int mult, double& creature) : InputFeature(), objective(objective), creature(creature), mult(mult){

}

void ObjectiveDirection::update(){
	value = ((double) (objective*mult)) - creature;
	value *= DIRECTION_DATA_MULT;
}
