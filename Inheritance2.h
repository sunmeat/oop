#pragma once

class CtorInheritanceDemo
{
	class Person
	{
	protected:
		string name_;
		string surname_;
		int age_;

	public:
		Person()
		{
			cout << "Person default c-tor!\n";
		}

		Person(string name)
		{
			cout << "Person param c-tor!\n";
			SetName(name);
		}

		void SetName(string name)
		{
			name_ = name;
		}

		string GetName()
		{
			return name_;
		}

		// ...other setters and getters

		void DoWork()
		{
			cout << "Person doing smth\n";
		}

		void Print() const
		{
			cout << "Person::Print\n";
		}
	};

	
	class Employee : public Person
	{

	protected:
		string profession_;

	public:

		Employee()
		{
			cout << "Employee default c-tor!\n";
		}
		
		void SetProfession(string profession)
		{
			profession_ = profession;
		}

		string GetProfession() const
		{
			return profession_;
		}
	};

	
public:
	static void Test()
	{
		Person a;
		Person b("Boris");
		Employee c;
		// Employee d("Denis");
	}
};

// CtorInheritanceDemo::Test();