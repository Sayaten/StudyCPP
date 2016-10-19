#include <iostream>
#include "OP.hpp"
#include "OPWeatherData.hpp"
#include "OPCurrentConditionsDisplay.hpp"

using namespace std;

int main()
{
	WeatherData weatherData;
	CurrentConditionsDisplay currentDisplay(weatherData);
	
	weatherData.setMeasurements(80, 65, 30.4f);
	weatherData.setMeasurements(82, 70, 29.2f);
	weatherData.setMeasurements(78, 90, 29.2f);

	return 0;
}
