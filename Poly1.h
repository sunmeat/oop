#pragma once

class IntroPolymorphismDemo
{

	class Transport
	{
		double speed;

	public:
		void Drive()
		{
			cout << "Transport::Drive\n";
		}
	};

	class Car : public Transport
	{
	public:
		void Drive()
		{
			cout << "Car::Drive\n";
		}
	};

	class Bike : public Transport
	{
	public:
		void Drive()
		{
			cout << "Bike::Drive\n";
		}
	};

	class Cart : public Transport // телега
	{
	public:
		void Drive()
		{
			cout << "Telega::Drive\n";
		}
	};
	
public:
	static void Test()
	{
		Car* c = new Car;
		Bike* b = new Bike;

		c->Drive();
		b->Drive();
	}
};

// IntroPolymorphismDemo::Test();