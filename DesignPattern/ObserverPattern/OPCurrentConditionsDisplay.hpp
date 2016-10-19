#ifndef __CURRENT_CONDITIONS_DISPLAY_HPP__
#define __CURRENT_CONDITIONS_DISPLAY_HPP__

#include "OP.hpp"

class CurrentConditionsDisplay : public DisplayElement, Observer
{
	public:
		CurrentConditionsDisplay(Subject &weatherData);
		void update(float temperature, float humidity, float pressure);
		void display();
	private:
		float temperature;
		float humidity;
		Subject &weatherData;
};

#endif
