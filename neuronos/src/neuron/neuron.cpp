#include "neuron.hpp"

using namespace std;
using namespace this_thread;

Neuron::Neuron(const Neuron& n) : 	idea(n.idea), id(n.id), stimulation(n.stimulation), isInActivation(n.isInActivation),
									network(n.network), networkSize(n.networkSize), liaisons(n.liaisons){}

Neuron::Neuron(int id, Neuron** network, int networkSize) : Neuron(NULL, id, network, networkSize){}

Neuron::Neuron(Idea* idea, int id, Neuron** network, int networkSize){
	this->idea = idea;
	this->id = id;
	this->network = network;
	this->networkSize = networkSize;
	liaisons = (double*) calloc(networkSize, sizeof(int));
	stimulation = 0;
	isInActivation = false;
	th = NULL;
}

/*void Neuron::Init(Idea* idea, int id, Neuron* network, int networkSize){
this->idea = idea;
this->id = id;
this->network = network;
liaisons = (int*) calloc(networkSize, sizeof(int));
stimulation = 0;
isActivate = false;
}*/

void Neuron::stimulate(int value){

	bool activate = false;

	activationMutex->lock();
	activate = isInActivation;
	activationMutex->unlock();

	if(!activate){

		stimulationMutex->lock();
		if(stimulation + value >= SIMULATION_THRESHOLD){
			activate = true;
			stimulation = 0;
		}
		else{
			stimulation += value;
		}
		stimulationMutex->unlock();

		if(activate){
			activationMutex->lock();
			isInActivation = true;
			activationMutex->unlock();

			th = new thread(&Neuron::activation, this);

		}


	}
}

void Neuron::activation(){
	#ifdef DEBUG
	cout << "Activate neuron : " + to_string(id) << endl;
	#endif
	for(int i = 0; i < networkSize; i++){
		if(i != id){
			if(network[i]->isActivate()){
				addLiaison(i, EPSILON);
				network[i]->addLiaison(id, EPSILON);
			}
			else{
				network[i]->stimulate(liaisons[i]);
			}
		}
	}
	sleep_for(chrono::seconds(1));

	activationMutex->lock();
	isInActivation = false;
	activationMutex->unlock();
}

int Neuron::getStimulation(){
	return stimulation;
}

bool Neuron::isActivate(){
	bool result;
	activationMutex->lock();
	result = isInActivation;
	activationMutex->unlock();
	return result;
}

void Neuron::addLiaison(int id, double value){
	liaisonMutex->lock();
	liaisons[id] += value;
	liaisonMutex->unlock();
	#ifdef DEBUG
	cout << "New liaison beetween neuron " + to_string(this->id) + " and " + to_string(id) + " : " + to_string(getLiaison(id)) << endl;
	#endif
}

double Neuron::getLiaison(int id){
	double result;
	liaisonMutex->lock();
	result = liaisons[id];
	liaisonMutex->unlock();
	return result;
}
