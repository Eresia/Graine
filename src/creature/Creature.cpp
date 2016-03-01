#include "Creature.hpp"

Creature::Creature(int id, Position position) : id(id), position(position), rotation(0), brain(NeuronNetwork(2, 2, 1, 6)){

}

Creature::Creature(int id, Position position, NeuronNetwork brain) : id(id), position(position), rotation(0), brain(brain){

}

Creature::Creature(Creature& copy) : id(copy.id), position(copy.position), rotation(copy.rotation), brain(copy.brain){

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

void Creature::setPosition(Position position){
	this->position = position;
}

double Creature::getRotation() const{
	return rotation;
}

void Creature::setRotation(double rotation){
	this->rotation = rotation;
}

int Creature::getId() const{
	return id;
}

bool Creature::comparePosition(const Creature* c1, const Creature* c2){
	Position p1, p2;
	p1 = c1->position;
	p2 = c2->position;
	return (p1 < p2);
}
