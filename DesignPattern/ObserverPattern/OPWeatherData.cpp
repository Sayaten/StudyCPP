#include "OP.hpp"
#include <list>
#include "OPWeatherData.hpp"

using namespace std;

WeatherData::WeatherData() { }
	
/*
virtual void WeatherData::registerObserver(Observer& o) override 
{ 
	observers.push_back(o); 
}
virtual void WeatherData::removeObserver(Observer& o) override 
{ 
	if(observers.size() > 0) 
		observers.remove(o); 
}
virtual void WeatherData::notifyObservers() override 
{ 
	for(auto iter : observers) 
		iter.update(temperature, humidity, pressure); 
}
*/
void WeatherData::measurementsChanged() 
{ 
	notifyObservers(); 
}
void WeatherData::setMeasurements(float temperature, float humidity, float pressure) 
{
	this -> temperature = temperature;
	this -> humidity = humidity;
	this -> pressure = pressure;
	measurementsChanged();
}
