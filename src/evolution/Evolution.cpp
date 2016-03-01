#include "Evolution.hpp"

using namespace std;

Evolution::Evolution(vector<NeuronNetwork> brains) : brains(brains){

}

vector<NeuronNetwork> Evolution::evolve(){
	vector<NeuronNetwork> result;
	for(int i = 0; i < (int) brains.size(); i++){
		for(int j = 0; j < (int) brains.size(); j++){
			if(i != j){
				result.push_back(NeuronNetwork(brains[i], brains[j]));
			}
		}
	}
	return result;
}
