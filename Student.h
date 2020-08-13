#pragma once

class Student
{
	char* name = nullptr;
	char* surname = nullptr;
	Date birthdate;

public:
	Student()
	{
		this->name = new char[200];
		strcpy_s(this->name, 200, "IVAN");

		this->surname = new char[200];
		strcpy_s(this->surname, 200, "IVANOV");

		this->birthdate.SetDate(1, 1, 1970);
	}

	Student(const char* name, const char* surname, Date birthdate)
	{
		this->name = new char[200];
		strcpy_s(this->name, 200, name);

		this->surname = new char[200];
		strcpy_s(this->surname, 200, surname);

		this->birthdate.SetDate(birthdate.GetDay(), birthdate.GetMonth(), birthdate.GetYear());
	}

	void Print() const
	{
		cout << "Name: " << name << " " << surname << "\nBirthdate: ";
		birthdate.Print();
	}

	Student* CreateRandomStudent()
	{
		string names[] = {"Vasya", "Petya", "Masha"};

		Date d;
		d.SetDate(rand() % 28 + 1, rand() % 12 + 1, rand() % 100 + 1935);
		
		Student* temp = new Student();

		// temp->name = new char[200]; // эта строка уже есть в конструкторе
		strcpy_s(this->name, 200, names[rand() % 3].c_str());

		// this->surname = new char[200]; // здесь можно было бы написать код генерации случайной фамилии, но мне лень
		// strcpy_s(this->surname, 200, surname);

		temp->birthdate = d;
		return temp;
	}

	~Student()
	{
		delete[] name;
		delete[] surname;
	}

	// конструктор копирования 
	Student(const Student& original) : Student(original.name, original.surname, original.birthdate)
	{
		
	}

	Student& operator= (const Student& original)
	{
		// ситуация с самоприсваиванием (s = s)
		if (this == &original) return *this;

		if (name != nullptr)
		{
			delete[] name;
		}
		name = new char[strlen(original.name) + 1];
		strcpy_s(name, strlen(original.name) + 1, original.name);

		if (surname != nullptr)
		{
			delete[] surname;
		}
		surname = new char[strlen(original.surname) + 1];
		strcpy_s(surname, strlen(original.surname) + 1, original.surname);
		
		this->birthdate = original.birthdate;

		return *this;
	}
};
