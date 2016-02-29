#include "Position.hpp"

Position::Position() : Position(0, 0){

}

Position::Position(double x, double y){
	this->x = x;
	this->y = y;
}

Position::Position(Position& copy){
	x = copy.x;
	y = copy.y;
}

double Position::getX(){
	return x;
}

double Position::getY(){
	return y;
}

void Position::setX(double x){
	this->x = x;
}

void Position::setY(double y){
	this->y = y;
}

void Position::updateX(double deltaX){
	x += deltaX;
}

void Position::updateY(double deltaY){
	y += deltaY;
}

void Position::setPosition(double x, double y){
	this->x = x;
	this->y = y;
}

void Position::updatePosition(double deltaX, double deltaY){
	x += deltaX;
	y += deltaY;
}
