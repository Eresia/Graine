/**
*	@file Evolution.cpp
*	Purpose : Define the evolution of the NeuralNetwork.
*
*	@author Eresia & Monsieur
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "Evolution.hpp"

using namespace std;

Evolution::Evolution(vector<NeuralNetwork> brains, int nbCreaMax) : brains(brains), nbCreaMax(nbCreaMax){

}

vector<NeuralNetwork> Evolution::evolve(){
	#if defined(EGALITARY_EVOLUTION)
		return egalitary();
	#elif defined(EGALITARY_EVOLUTION)
		return favoritism();
	#else
		return egalitary();
	#endif
}

vector<NeuralNetwork> Evolution::egalitary(){
	vector<NeuralNetwork> result;
	while((int) result.size() < nbCreaMax){
		for(int i = 0; i < (int) brains.size(); i++){
			for(int j = 0; j < (int) brains.size(); j++){
				if(i != j){
					result.push_back(NeuralNetwork(brains[i], brains[j]));
				}

				if((int) result.size() >= nbCreaMax){
					break;
				}
			}
			if((int) result.size() >= nbCreaMax){
				break;
			}
		}
	}
	return result;
}

vector<NeuralNetwork> Evolution::favoritism(){
	vector<NeuralNetwork> result;
	/*while((int) result.size() < nbCreaMax){
		for(int i = 0; i < (int) brains.size(); i++){
			for(int j = 0; j < ((int) brains.size()-i); j++){
				if(i != j){
					result.push_back(NeuralNetwork(brains[i], brains[j]));
				}
				else if((int) result.size() >= nbCreaMax){
					break;
				}
			}
			if((int) result.size() >= nbCreaMax){
				break;
			}
		}
	}*/
	return result;
}
