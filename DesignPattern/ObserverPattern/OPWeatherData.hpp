#ifndef __WEATHER_DATA_HPP__
#define __WEATHER_DATA_HPP__

#include "OP.hpp"
#include <list>

class WeatherData : public Subject
{
	public:
		WeatherData();
		virtual void registerObserver(Observer& o) override
		{
			observers.push_back(&o);
		}
		virtual void removeObserver(Observer& o) override
		{
			if(observers.size() > 0) observers.remove(&o);
		}
		virtual void notifyObservers() override
		{
			for(auto iter : observers)
				iter -> update(temperature, humidity, pressure);
		}
		void measurementsChanged();
		void setMeasurements(float temperature, float humidity, float pressure);
	private:
		std::list<Observer*> observers;
		float temperature;
		float humidity;
		float pressure;
};

#endif
