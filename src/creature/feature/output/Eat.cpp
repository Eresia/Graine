#include "Eat.hpp"

Eat::Eat(Creature* creature) : OutputFeature(), creature(creature){

}

void Eat::update(double value){
	if(value < 0.5){
		creature->eat();
	}
}
