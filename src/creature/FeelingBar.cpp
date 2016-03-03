#include "FeelingBar.hpp"

FeelingBar::FeelingBar(double max) : max(max), value(max){

}

void FeelingBar::addValue(double value){
	this->value += value;
	if(this->value > max){
		this->value = max;
	}
}

void FeelingBar::removeValue(double value){
	this->value -= value;
	if(this->value < 0){
		this->value = 0;
	}
}

void FeelingBar::addPercent(double nbPercent){
	addValue(getPercent()*nbPercent);
}

void FeelingBar::removePercent(double nbPercent){
	removeValue(getPercent()*nbPercent);
}

double FeelingBar::getValue(){
	return value;
}

double FeelingBar::getPercent(){
	return (value/max) * 100;
}
