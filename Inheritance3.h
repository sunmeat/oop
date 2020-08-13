#pragma once

class InitInheritanceDemo
{
	class Person
	{
	protected: // try to comment this line
		string name_;
		string surname_;
		int age_;

	public:
		Person()
		{
			cout << "Person default c-tor!\n";
			name_ = "John";
			surname_ = "Doe";
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
			cout << "Person: " << name_ << " " << surname_ << "\n\n";
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

		Employee(string name, string surname, string profession)
		{
			cout << "Employee param c-tor!\n";
			name_ = name; // <<< it's way to error!
			// SetName(name); // redundant line
			surname_ = surname; // <<< it's way to error!
			// SetSurname(surname); // redundant line
			profession_ = profession; // ok
			// SetProfession(profession); // ok
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
			cout << "Employee: " << name_ << " " << surname_ << ", " << profession_ << "\n\n";
		}
	};

public:
	static void Test()
	{
		Person a;
		a.Print();
		Person b("Boris", "Denisov");
		b.Print();
		Employee c;
		c.Print();
		Employee d("Denis", "Borisov", "accountant");
		d.Print();
	}
};

// InitInheritanceDemo::Test();