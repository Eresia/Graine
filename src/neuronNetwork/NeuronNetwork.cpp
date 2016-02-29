#include "NeuronNetwork.hpp"

using namespace std;

NeuronNetwork::NeuronNetwork(int nbInput, int nbOutput, int nbHiddenLayer, int nbNeuronPerLayer) : nbInput(nbInput), nbHiddenLayer(nbHiddenLayer){
	if(nbHiddenLayer > 0){
		layers.push_back(NeuronLayer(nbNeuronPerLayer, nbInput));
		for(int i = 0; i < nbHiddenLayer - 1; i++){
			layers.push_back(NeuronLayer(nbNeuronPerLayer, nbNeuronPerLayer));
		}
		layers.push_back(NeuronLayer(nbOutput, nbNeuronPerLayer));
	}
	else{
		layers.push_back(NeuronLayer(nbOutput, nbInput));
	}
}

vector<double> NeuronNetwork::update(vector<double>& firstInputs){
	vector<double> outputs;
	vector<double> inputs = firstInputs;

	if((int) firstInputs.size() != nbInput){
		throw BadNumberOfInputException("NeuronNetwork need " + to_string(nbInput) + " inputs, " + to_string(firstInputs.size()) + " send");
	}

	for(int i = 0; i < nbHiddenLayer + 1; i++){
		outputs = layers[i].stimule(inputs);
		inputs = outputs;
	}

	return outputs;
}
