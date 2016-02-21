#include "network.hpp"

using namespace std;

Network::Network(int size){
    network = (Neuron**) calloc(size, sizeof(Neuron*));
    this->size = size;
    nbNeuron = 0;

    for(int i = 0 ; i < size; i++){
        network[i] = new Neuron(i, network, size);
    }
}

void Network::stimulate(int neuron, int value){
    network[neuron]->stimulate(value);
}


Neuron* Network::getNewNeuron(){
    Neuron* newNeuron = network[nbNeuron];
    nbNeuron++;
    return newNeuron;
}

int Network::getSize(){
    return size;
}

int Network::getNbNeuron(){
    return nbNeuron;
}

Neuron* Network::getNeuron(int n){
    return network[n];
}

string Network::to_string(){
    string result;

    int width = (int) sqrt(size);
    if((size%width) != 0){
        width++;
    }

    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            if(i*width+j < size){
                string s;
                if(network[i*width+j]->isActivate()){
                    s = "1 ";
                }
                else{
                    s = "0 ";
                }
                result += s;
            }
        }
        result += "\n";
    }

    return result;
}
