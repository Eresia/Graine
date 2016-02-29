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
		void setPosition(double x, double y);
};

#endif
