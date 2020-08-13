#pragma once

class Date
{
	// static - чтобы массив не копировался для каждого объекта (48 байтов это не много, но тем не менее)
	// const - чтобы нельзя было поменять количество дней в месяце
	static const int month_days[12];

	// перечисление не очень-то удобно использовать, потому что нельзя запустить переборный цикл для просмотра элементов перечисления
	//enum md {JAN=31, FEB=28, MAR=31, APR=30};

	int day;
	int month;
	int year;
	char* weekday = nullptr;

	void SetWeekday()
	{
		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + 12 * a - 2;
		int w = (day + (31 * m) / 12 + y + y / 4 - y / 100 + y / 400) % 7;

		if (weekday != nullptr) delete[] weekday;
		weekday = new char[15];

		const char* days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		strcpy_s(weekday, 15, days[w]);
	}

public:
	Date(int day, int month, int year) // Date d(1,1,1999)
	{
		//cout << "c-tor param\n";
		SetDate(day, month, year);
	}

	Date()
	{
		//cout << "c-tor without parameters!\n";
		//SetDate(1, 1, 1970);
		SYSTEMTIME st;
		GetSystemTime(&st);
		SetDate(st.wDay, st.wMonth, st.wYear);
	}

	~Date()
	{
		//cout << "DESTRUCTOR!\n";
		if (weekday != nullptr)
			delete[] weekday;
	}

	void SetDay(int value)
	{
		if (value >= 1 && value <= 31) {
			day = value; 
			SetWeekday();
		}
		else {
			throw "ERROR!\n";
		}
	}

	void SetMonth(int value)
	{
		if (value >= 1 && value <= 12) {
			month = value;
			SetWeekday();
		}
		else {
			throw "ERROR!\n";
		}
	}

	void SetYear(int value)
	{
		year = value;
		SetWeekday();
	}

	int GetDay() const
	{
		return day;
	}

	int GetMonth() const
	{
		return month;
	}

	int GetYear() const { return year; }

	string GetWeekday() const
	{
		return weekday;
	}

	void Print() const
	{
		printf("%s, %02d.%02d.%04d\n", weekday, day, month, year);
	}

	void SetDate(int day, int month, int year)
	{
		SetDay(day);
		SetMonth(month);
		SetYear(year);
	}

	void SetDateFromKeyboard()
	{
		cout << "Please, enter day (1-31): ";
		int value;
		cin >> value;
		SetDay(value);
		cout << "Please, enter month (1-12): ";
		cin >> value;
		SetMonth(value);
		cout << "Please, enter year: ";
		cin >> value;
		SetYear(value);
	}

	// конструктор копирования 
	Date(const Date& original) : Date(original.day, original.month, original.year)
	{

	}

	Date& operator= (const Date& original)
	{
		// ситуация с самоприсваиванием (s = s)
		if (this == &original) return *this;

		if (weekday != nullptr)
		{
			delete[] weekday;
		}
		weekday = new char[15];
		strcpy_s(weekday, 15, original.weekday);

		this->day = original.day;
		this->month = original.month;
		this->year = original.year;

		return *this;
	}

};

const int Date::month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
