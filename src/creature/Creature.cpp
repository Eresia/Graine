/**
*	@file Creature.cpp
*	Purpose : Define the creature behavior and mind.
*
*	@author Eresia
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "Creature.hpp"

using namespace std;

Creature::Creature(int id, Map& map, Position position) : Creature(id, map, position, NeuronNetwork(BRAIN_INPUT, BRAIN_OUTPUT, BRAIN_HIDDEN_LAYER, BRAIN_NEURON_PER_LAYER)){
	objective = Position(0, 0);
}

Creature::Creature(int id, Map& map, Position position, NeuronNetwork brain) : id(id), map(map), position(position), rotation(0), brain(brain){
	objective = Position(0, 0);
	feelingBars[FEELING_FOOD] = NULL;
	feelingBars[FEELING_SLEEP] = NULL;
	feelingBars[FEELING_WATER] = NULL;
}

Creature::Creature(int id, Map& map, Position position, Position& objective) : Creature(id, map, position,
																	NeuronNetwork(BRAIN_INPUT, BRAIN_OUTPUT, BRAIN_HIDDEN_LAYER, BRAIN_NEURON_PER_LAYER)){
	this->objective = objective;
}

Creature::Creature(int id, Map& map, Position position, NeuronNetwork brain, Position& objective) : Creature(id, map, position, brain){
	this->objective = objective;
}

Creature::Creature(Creature& copy) : id(copy.id), map(copy.map), position(copy.position), rotation(copy.rotation), brain(copy.brain){

}

void Creature::think(){
	vector<double> infos;
	vector<double> result;
	int i = 0;
	for (std::map<InputId, InputFeature*>::iterator it = inputFeatures.begin(); it != inputFeatures.end(); it++){
		it->second->update();
		infos.push_back(it->second->getValue());
	}
	try{
		result = brain.update(infos);
		if(result.size() != outputFeatures.size()){
			throw BadNumberOfOutputException("Bad number of outputs");
		}

		for (std::map<OutputId, OutputFeature*>::iterator it = outputFeatures.begin(); it != outputFeatures.end(); it++){
			it->second->update(result[i]);
			i++;
		}

		doActions();

	} catch(BadNumberOfInputException e){
		cout << "Bad number of inputs" << endl;
		cout << e.what() << endl;
	} catch(BadNumberOfOutputException e){
		cout << e.what() << endl;
	}
}

void Creature::eat(){
	if(map.onSpecialCase(position.getX()/SIZE_IMAGE_H, position.getY()/SIZE_IMAGE_W, FoodMaterial::getInstance()->getType())){
		feelingBars[FEELING_FOOD]->addPercent(20);
		cout << "Eat : "  << id << endl;
	}
}

void Creature::doActions(){
	move(outputFeatures[OUTPUT_MOVEMENT_LEFT]->getValue(), outputFeatures[OUTPUT_MOVEMENT_RIGHT]->getValue());
}

void Creature::move(int speed){
	position.updatePosition(sin(rotation) * speed, cos(rotation) * speed);
	if(feelingBars[FEELING_FOOD] != NULL){
		feelingBars[FEELING_FOOD]->removePercent(1);
	}
}

void Creature::move(double forceLeft, double forceRight){
	double force = forceRight - forceLeft;
	rotation += force;
	if(rotation <= (-2*M_PI)){
		do{
			rotation += 2*M_PI;
		}while(rotation <= (-2*M_PI));
	}
	else if(rotation >= (2*M_PI)){
		do{
			rotation -= 2*M_PI;
		}while(rotation >= (2*M_PI));
	}
	move((forceRight + forceLeft)*SPEED_MULT);
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

void Creature::addInputFeature(InputId id, InputFeature* input){
	inputFeatures[id]= input;
}

void Creature::addOutputFeature(OutputId id, OutputFeature* output){
	outputFeatures[id] = output;
}

void Creature::clearFeatures(){
	inputFeatures.clear();
	outputFeatures.clear();
}

void Creature::addFeelingBar(FeelingBarId id, FeelingBar* bar){
	feelingBars[id] = bar;
}

double Creature::getFeelingValue(FeelingBarId id) const{
	std::map<FeelingBarId, FeelingBar*> m = feelingBars;
	double value = m[id]->getValue();
	return value;
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

double& Creature::getRotationRef(){
	return rotation;
}

int Creature::getId() const{
	return id;
}

NeuronNetwork& Creature::getBrain(){
	return brain;
}

bool Creature::comparePosition(const Creature* c1, const Creature* c2){
	Position p1, p2;
	p1 = c1->position;
	p2 = c2->position;
	return (p1 < p2);
}

bool Creature::compareHunger(const Creature* c1, const Creature* c2){
	return (c1->getFeelingValue(FEELING_FOOD) > c2->getFeelingValue(FEELING_FOOD));
}


Position& Creature::getObjective(){
	return objective;
}

void Creature::setObjective(Position& objective){
	objective = objective;
}

void Creature::setObjective(double x, double y){
	objective.setPosition(x, y);
}
