#include "Creature.hpp"

Creature::Creature(int id, Position position) : Creature(id, position, NeuronNetwork(BRAIN_INPUT, BRAIN_OUTPUT, BRAIN_HIDDEN_LAYER, BRAIN_NEURON_PER_LAYER)){
	objective = Position(0, 0);
}

Creature::Creature(int id, Position position, NeuronNetwork brain) : id(id), position(position), rotation(0), brain(brain){
	objective = Position(0, 0);
}

Creature::Creature(int id, Position position, Position& objective) : Creature(id, position, NeuronNetwork(BRAIN_INPUT, BRAIN_OUTPUT, BRAIN_HIDDEN_LAYER, BRAIN_NEURON_PER_LAYER)){
	this->objective = objective;
}

Creature::Creature(int id, Position position, NeuronNetwork brain, Position& objective) : Creature(id, position, brain){
	this->objective = objective;
}

Creature::Creature(Creature& copy) : id(copy.id), position(copy.position), rotation(copy.rotation), brain(copy.brain){

}

void Creature::think(){
	vector<double> infos;
	vector<double> result;
	for(int i = 0; i < (int) inputFeatures.size(); i++){
		inputFeatures[i]->update();
		infos.push_back(inputFeatures[i]->getValue());
	}
	try{
		result = brain.update(infos);
		if(result.size() != outputFeatures.size()){
			throw BadNumberOfOutputException("Bad number of outputs");
		}

		for(int i = 0; i < (int) outputFeatures.size(); i++){
			outputFeatures[i]->update(result[i]);
		}

		doActions();

	} catch(BadNumberOfInputException e){
		cout << "Bad number of inputs" << endl;
		cout << e.what() << endl;
	} catch(BadNumberOfOutputException e){
		cout << e.what() << endl;
	}
}

void Creature::doActions(){
	move(outputFeatures[0]->getValue(), outputFeatures[1]->getValue());
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

void Creature::addInputFeature(InputFeature* input){
	inputFeatures.push_back(input);
}

void Creature::addOutputFeature(OutputFeature* output){
	outputFeatures.push_back(output);
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

NeuronNetwork& Creature::getBrain(){
	return brain;
}

bool Creature::comparePosition(const Creature* c1, const Creature* c2){
	Position p1, p2;
	p1 = c1->position;
	p2 = c2->position;
	return (p1 < p2);
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
