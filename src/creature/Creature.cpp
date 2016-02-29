#include "Creature.hpp"

Creature::Creature(Position& position, double speed) : position(position), rotation(0), brain(NeuronNetwork(2, 2, 1, 6)){

}

void Creature::think(double info1, double info2){
	vector<double> info;
	info.push_back(info1);
	info.push_back(info2);
	try{
		info = brain.update(info);
		move(info[0], info[1]);
	} catch(BadNumberOfInputException e){
		cout << "Bad number of info" << endl;
		cout << e.what() << endl;
	}
}

void Creature::move(int speed){
	position.updatePosition(sin(rotation) * speed, cos(rotation) * speed);
}

void Creature::move(double forceLeft, double forceRight){
	double force = forceRight - forceLeft;
	rotation += force;
	move(forceRight + forceLeft);
}

void Creature::turnLeft(){
	rotation -= (M_PI/12);
	if(rotation <= (-2*M_PI)){
		rotation += 2*M_PI;
	}
}

void Creature::turnRight(){
	rotation += (M_PI/12);
	if(rotation >= (2*M_PI)){
		rotation -= 2*M_PI;
	}
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
