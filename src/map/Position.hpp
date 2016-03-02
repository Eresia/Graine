#ifndef POSITION
#define POSITION

#include <cmath>

class Position {

	private:
		double x;
		double y;

	public:
		Position();
		Position(double x, double y);
		Position(Position& copy);
		double getX() const;
		double getY() const;
		double& getXRef();
		double& getYRef();
		void setX(double x);
		void setY(double y);
		void updateX(double deltaX);
		void updateY(double deltaY);
		void setPosition(double x, double y);
		void updatePosition(double deltaX, double deltaY);
		double getDistance() const;

		Position &operator+(const Position &rhs);
		Position &operator-(const Position &rhs);
		Position &operator*(const double &rhs);
		Position &operator/(const double &rhs);
		Position &operator+=(const Position &rhs);
		Position &operator-=(const Position &rhs);
		Position &operator*=(const double &rhs);
		Position &operator/=(const double &rhs);
		bool operator<(const Position &rhs);
		bool operator<=(const Position &rhs);
		bool operator>(const Position &rhs);
		bool operator>=(const Position &rhs);
};

#endif
