#include "Position.hpp"

Position::Position() : Position(0, 0){

}

Position::Position(int x, int y){
	this->x = x;
	this->y = y;
}

Position::Position(Position& copy){
	x = copy.x;
	y = copy.y;
}

int Position::getX(){
	return x;
}

int Position::getY(){
	return y;
}

void Position::setX(int x){
	this->x = x;
}

void Position::setY(int y){
	this->y = y;
}

void Position::setPosition(int x, int y){
	this->x = x;
	this->y = y;
}
