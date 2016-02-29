#include "Creature.hpp"

Creature::Creature(Position& position, double speed) : position(position), rotation(0), speed(speed){

}

void Creature::move(){
	double posX = position.getX();
	double posY = position.getY();
	double deltaX = cos(rotation);
	double deltaY = sin(rotation);
	position.setPosition(posX + deltaX, posY + deltaY);
}

void Creature::turnLeft(){
	rotation += (M_PI/12);
}

void Creature::turnRight(){
	rotation -= (M_PI/12);
}

Position& Creature::getPosition(){
	return position;
}

void Creature::setPosition(Position& position){
	this->position = position;
}

double Creature::getRotation(){
	return rotation;
}

void Creature::setRotation(double rotation){
	this->rotation = rotation;
}

double Creature::getSpeed(){
	return speed;
}

void Creature::setSpeed(double speed){
	this->speed = speed;
}
