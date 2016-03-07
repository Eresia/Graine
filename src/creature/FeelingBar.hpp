#ifndef FEELING_BAR
#define FEELING_BAR

enum FeelingBarId : int {FEELING_FOOD, FEELING_WATER, FEELING_SLEEP};

class FeelingBar{

	private:
		double max; //!< Max value of the FeelingBar
		double value; //!< Value of the FeelingBar

	public:
		FeelingBar(double max); //!< Constructor of the FeelingBar

		void addValue(double value); //!< Add value to the bar
		void removeValue(double value); //!< Remove value to the bar

		void addPercent(double nbPercent); //!< Add a certain percent amount to the bar
		void removePercent(double nbPercent); //!< Remove a certain percent amount of the bar

		//!< Getters, value of the bar, value in percent and actual percent value of the bar
		double getValue();
		double getValueInPercent();
		double getPercent();
};

#endif
