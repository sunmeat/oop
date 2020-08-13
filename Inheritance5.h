#pragma once

class ReplacementInheritanceDemo
{
	class Person
	{
		string name_;
		string surname_;
		int age_;

	public:
		Person() : Person("John", "Doe")
		{
			cout << "Person default c-tor!\n";
		}

		Person(string name, string surname)
		{
			cout << "Person param c-tor!\n";
			SetName(name);
			SetSurname(surname);
		}

		void SetName(string name)
		{
			name_ = name;
		}

		string GetName() const
		{
			return name_;
		}

		void SetSurname(string surname)
		{
			surname_ = surname;
		}

		string GetSurname() const
		{
			return surname_;
		}

		void Print() const
		{
			cout << name_ << " " << surname_;
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
			profession_ = "programmer";
		}

		Employee(string name, string surname, string profession) : Person(name, surname)
		{
			cout << "Employee param c-tor!\n";
			SetProfession(profession);
		}

		void SetProfession(string profession)
		{
			profession_ = profession;
		}

		string GetProfession() const
		{
			return profession_;
		}

		void Print(int value) const // REPLACEMENT!
		{
			cout << value << "\n\n";
		}
	};

public:
	static void Test()
	{
		Person a;
		a.Print();
		
		Employee b;
		b.Print(5);
		// b.Print(); // метод с такой сигнатурой больше не доступен
		// так как произошло замещение интерфейса
	}
};

// ReplacementInheritanceDemo::Test();