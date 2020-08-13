#pragma once

// раннее связывание
class EarlyBindingPolymorphismDemo
{

	class Transport
	{
		double speed;

	public:
		virtual void Drive()
		{
			cout << "Transport::Drive\n";
		}
	};

	class Car : public Transport
	{
	public:
		/*virtual*/ void Drive()
		{
			cout << "Car::Drive\n";
		}
	};

	class Bike : public Transport
	{
	public:
		/*virtual*/ void Drive()
		{
			cout << "Bike::Drive\n";
		}
	};

	class Telega : public Transport // телега
	{
	public:
		/*virtual*/ void Drive()
		{
			cout << "Telega::Drive\n";
		}
	};

	static Transport* GetSomeTransport()
	{
		int r = rand() % 3;
		if (r == 0) return new Car;
		if (r == 1) return new Telega;
		return new Bike;
	}

public:
	static void Test()
	{
		int count = 5; // количество транспортных средств
	    // cin >> count;
	    // count = rand() % 20;

		Transport** traffic = new Transport* [count];

		// настройка  
		traffic[0] = new Car;
		traffic[1] = new Car;
		traffic[2] = new Bike;
		traffic[3] = new Telega;
		traffic[4] = GetSomeTransport();

		///////////////////////// ждём светофор...

		Application::SetConsoleColor(Application::Color::RED);
		cout << "Wait 3 ";
		Sleep(1000);
		cout << "2 ";
		Sleep(1000);
		cout << "1 ";
		Sleep(1000);
		system("cls");
		Application::SetConsoleColor(Application::Color::GREEN);
		cout << "Go!!!\n\n";
		Sleep(1000);
		Application::SetConsoleColor(Application::Color::GRAY);

		///////////////////////// погнали наши городских!

		for (int i = 0; i < count; i++)
			traffic[i]->Drive();
	}
};

// EarlyBindingPolymorphismDemo::Test();