/**
*	@file Position.cpp
*	Purpose : Definig up positions of objects in the map.
*
*	@author Eresia
*	@version 1.0
* @date 29/02/2016
* @copyright The Unlicense
*/
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

double Position::getX() const{
	return x;
}

double Position::getY() const{
	return y;
}

double& Position::getXRef(){
	return x;
}

double& Position::getYRef(){
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

double Position::getDistance() const{
	return sqrt(x*x + y*y);
}

Position &Position::operator+(const Position &rhs){
	Position* result = new Position(x + rhs.x, y + rhs.y);
	return *result;
}

Position &Position::operator-(const Position &rhs){
	Position* result = new Position(x - rhs.x, y - rhs.y);
	return *result;
}

Position &Position::operator*(const double &rhs){
	Position* result = new Position(x * rhs, y * rhs);
	return *result;
}

Position &Position::operator/(const double &rhs){
	Position* result = new Position(x / rhs, y / rhs);
	return *result;
}

Position &Position::operator+=(const Position &rhs){
	x += rhs.x;
	y += rhs.y;

	return *this;
}

Position &Position::operator-=(const Position &rhs){
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

Position &Position::operator*=(const double &rhs){
	x *= rhs;
	y *= rhs;

	return *this;
}

Position &Position::operator/=(const double &rhs){
	x /= rhs;
	y /= rhs;

	return *this;
}

bool Position::operator>(const Position &rhs){
	return (getDistance() > rhs.getDistance());
}

bool Position::operator>=(const Position &rhs){
	return (getDistance() >= rhs.getDistance());
}

bool Position::operator<(const Position &rhs){
	return (getDistance() < rhs.getDistance());
}

bool Position::operator<=(const Position &rhs){
	return (getDistance() <= rhs.getDistance());
}
