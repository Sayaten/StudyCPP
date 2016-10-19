#ifndef __OP_HPP__
#define __OP_HPP__

class Observer
{
	public:
		virtual void update(float temp, float humidity, float pressure) { };
		bool operator==(const Observer& rhs)
		{
			if(this == &rhs) return true;
			else false;
		}
};

class DisplayElement
{
	public:
		virtual void display() = 0;
};

class Subject
{
	public:
		virtual void registerObserver(Observer& o) { };
		virtual void removeObserver(Observer& o) { };
		virtual void notifyObservers() { };
};

#endif
