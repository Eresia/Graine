#include "InputDouble.hpp"

InputDouble::InputDouble(double& value) : InputFeature(), valueRef(value){

}

void InputDouble::update(){
	value = valueRef;
}
