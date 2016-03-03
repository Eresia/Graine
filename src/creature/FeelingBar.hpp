#ifndef FEELING_BAR
#define FEELING_BAR

enum FeelingBarId : int {FEELING_FOOD, FEELING_WATER, FEELING_SLEEP};

class FeelingBar{

	private:
		double max;
		double value;

	public:
		FeelingBar(double max);

		void addValue(double value);
		void removeValue(double value);

		void addPercent(double nbPercent);
		void removePercent(double nbPercent);

		double getValue();
		double getPercent();
};

#endif
