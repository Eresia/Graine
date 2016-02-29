#ifndef POSITION
#define POSITION

class Position {

	private:
		int x;
		int y;

	public:
		Position();
		Position(double x, double y);
		Position(Position& copy);
		double getX();
		double getY();
		void setX(double x);
		void setY(double y);
		void updateX(double deltaX);
		void updateY(double deltaY);
		void setPosition(double x, double y);
		void updatePosition(double deltaX, double deltaY);
};

#endif
