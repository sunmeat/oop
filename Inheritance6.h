#pragma once

class HidingInheritanceDemo
{
	class Person
	{
	public:
		string name_ = "Alex";
	};


	class Employee : public Person
	{
	public:
		const char* name_ = "Alexander"; // hiding example
		
		void SayHello() const
		{
			cout << name_ << "\n";
			cout << Person::name_ << "\n";
		}
	};

public:
	static void Test()
	{
		Employee e;
		e.SayHello();
	}
};

// HidingInheritanceDemo::Test();