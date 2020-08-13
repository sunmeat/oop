#pragma once

class FoodPolymorphismDemo
{

	class Food
	{
	public:
		virtual void Print()
		{
			cout << "Food::Print\n";
		}
	};

	class Cutlet : public Food
	{
	public:
		virtual void Print() override
		{
			cout << "Cutlet\n";
		}
	};

	class Fish : public Food
	{
	public:
		virtual void Print() override
		{
			cout << "Fish\n";
		}
	};

	class HeatableFood : public Food
	{
	public:
		virtual void Heat()
		{
			cout << "Food is heating...\n";
			Sleep(1000);
			cout << "DONE!\n";
		}

		virtual void Print() override
		{
			cout << "HeatableFood::Print\n";
		}
	};

	class RawEgg : public HeatableFood
	{
	public:
		virtual void Heat() override
		{
			cout << "RawEgg is heating...\n";
			Sleep(1000);
			throw "OOPS!\n";
		}
		virtual void Print() override
		{
			cout << "RawEgg\n";
		}
	};

	class Pizza : public HeatableFood
	{
	public:
		virtual void Heat() override
		{
			cout << "Pizza is heating...\n";
			Sleep(1000);
			cout << "DONE!\n";
		}
		virtual void Print() override
		{
			cout << "Pizza\n";
		}
	};

	class Oatmeal : public HeatableFood
	{
	public:
		virtual void Heat() override
		{
			cout << "Oatmeal is heating...\n";
			Sleep(1000);
			cout << "DONE!\n";
		}
		virtual void Print() override
		{
			cout << "Oatmeal\n";
		}
	};

	class SmartPhone
	{
	public:
		virtual void Heat() /*override*/ // !!!
		{
			cout << "SmartPhone is heating...\n";
		}
		virtual void Print() /*override*/ // !!!
		{
			cout << "SmartPhone\n";
		}
	};

	// microwave test function
	static void HeatFood(HeatableFood* food)
	{
		food->Print();
		food->Heat();
	}

	static Food* OrderFood()
	{
		int random = rand() % 5; // 0...4
		switch (random)
		{
		case 0:
			return new Cutlet;
		case 1:
			return new Pizza;
		case 2:
			return new Oatmeal;
		case 3:
			return new RawEgg;
		case 4:
			return new Fish;
		}
	}

public:
	static void Test()
	{
		/*
		// условно неразогреваемые 
		Fish f;
		Cutlet c;

		// то, что можно разогреть
		RawEgg e; // на свой страх и риск
		Pizza p;
		Oatmeal o;

		SmartPhone s; // это вообще не еда

		// HeatFood(&f); // compile error
		// e.Heat(); // runtime error
		e.Print();
		// HeatFood(&e); // runtime error
		// HeatFood(&c); // compile error
		// HeatFood(&s); // compile error

		HeatFood(&p); // OK!
		HeatFood(&o); // OK!

		void* ptr = &f;
		// HeatFood(ptr); // compile error
		// HeatFood((HeatableFood*)ptr); // runtime error

		ptr = &s;
		HeatFood((HeatableFood*)ptr); // OK!

		//Food* f1 = new Fish();
		//f1->Print(); */

		Food* food = OrderFood();
		food->Print();
	}
};

// FoodPolymorphismDemo::Test();