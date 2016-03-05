/**
*	@file Evolution.cpp
*	Purpose : Define the evolution of the NeuronNetwork.
*
*	@author Eresia
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
#include "Evolution.hpp"

using namespace std;

Evolution::Evolution(vector<NeuronNetwork> brains, int nbCreaMax) : brains(brains), nbCreaMax(nbCreaMax){

}

vector<NeuronNetwork> Evolution::evolve(){
	#if defined(EGALITARY)
		return egalitary();
	#elif defined(FAVORITISM)
		return favoritism();
	#else
		return egalitary();
	#endif
}

vector<NeuronNetwork> Evolution::egalitary(){
	vector<NeuronNetwork> result;
	while((int) result.size() < nbCreaMax){
		for(int i = 0; i < (int) brains.size(); i++){
			for(int j = 0; j < (int) brains.size(); j++){
				if(i != j){
					result.push_back(NeuronNetwork(brains[i], brains[j]));
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

vector<NeuronNetwork> Evolution::favoritism(){
	vector<NeuronNetwork> result;
	/*while((int) result.size() < nbCreaMax){
		for(int i = 0; i < (int) brains.size(); i++){
			for(int j = 0; j < ((int) brains.size()-i); j++){
				if(i != j){
					result.push_back(NeuronNetwork(brains[i], brains[j]));
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
