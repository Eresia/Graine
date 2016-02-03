#ifndef NETWORK
#define NETWORK

#include <iostream>
#include <string>
#include <cmath>

#include "../main/constant.hpp"
#include "neuron.hpp"

class Network{

private:
    Neuron** network;
    int size;
    int nbNeuron;

public:
    Network(int size);

    void stimulate(int neuron, int value);
    Neuron* getNewNeuron();

    int getSize();
    int getNbNeuron();
    Neuron* getNeuron(int n);
    std::string to_string();
};

#endif
