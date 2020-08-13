#pragma once

// зачем необходимо приватное наследование?
// https://ru.stackoverflow.com/questions/483247/private-%D0%BD%D0%B0%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5

class SimpleInheritanceDemo
{
	class Person // человек
	{
	protected:
		string name_;
		string surname_;
		int age_;

	private:
		int test; // тестовое поле

	public:
		void SetName(string name)
		{
			name_ = name;
		}

		string GetName() const
		{
			return name_;
		}

		// ...other setters and getters

		void DoWork()
		{
			cout << "Person doing something...\n";
		}

		void Print() const
		{
			cout << "Person::Print\n";
		}
	};
	

	class Employee : public Person // сотрудник офиса
	{

	protected:
		string profession_;

	public:
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
		Person* p = new Person();
		p->Print();

		Employee* e = new Employee();
		e->Print();
		//e->
	}
};

// SimpleInheritanceDemo::Test();