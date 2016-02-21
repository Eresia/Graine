#ifndef NEURON
#define NEURON

#include <thread>
#include <iostream>
#include <string>
#include <cstdlib>
#include <mutex>
#include <chrono>

#include "../main/constant.hpp"

#include "../idea/idea.hpp"

#define SIMULATION_THRESHOLD 1
#define EPSILON 0.5

class Neuron{

private:
    Idea* idea;
    int id;
    int stimulation;
    bool isInActivation;

    std::mutex* stimulationMutex;
    std::mutex* activationMutex;
    std::mutex* liaisonMutex;

    Neuron** network;
    int networkSize;
    double* liaisons;

    std::thread* th;

public:
    Neuron(const Neuron& n);
    Neuron(Idea* idea, int id, Neuron** network, int networkSize);
    Neuron(int id, Neuron** network, int networkSize);
    //C++89
    //void Init(Idea* idea, int id, Neuron* network, int networkSize);

    void stimulate(int value);
    void activation();

    int getStimulation();
    bool isActivate();
    void addLiaison(int id, double value);
    double getLiaison(int id);

};

#endif
