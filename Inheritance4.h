#pragma once

class InitSolvedInheritanceDemo
{
	class Person
	{
	protected: // try to comment this line
		string name_;
		string surname_;
		int age_;

	public:
		Person() : Person("John", "Doe") // делегирование
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
			cout << name_ << " " << surname_; // little changes
		}
	};


	class Employee : public Person
	{

	protected:
		string profession_;

	public:
		Employee() /* : Person() */
		{
			cout << "Employee default c-tor!\n";
			profession_ = "programmer";
		}

		Employee(string name, string surname, string profession) : Person(name, surname)
		{
			cout << "Employee param c-tor!\n";
			// profession_ = profession; // ok
			SetProfession(profession); // ok
		}

		void SetProfession(string profession)
		{
			profession_ = profession;
		}

		string GetProfession() const
		{
			return profession_;
		}

		void Print() const
		{
			Person::Print();
			cout << ", " << profession_ << "\n\n";
		}
	};

public:
	static void Test()
	{
		Person a;
		a.Print();
		cout << "\n\n";
		Person b("Boris", "Yurinov");
		b.Print();
		cout << "\n\n";
		
		Employee c;
		c.Print();
		Employee d("Denis", "Kosyakov", "actor");
		d.Print();
	}
};

// InitSolvedInheritanceDemo::Test();