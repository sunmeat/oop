#pragma once

#include <iostream>
using namespace std;

class Fraction
{
	int numerator; // числитель
	int denominator; // знаменатель

public:
	Fraction();
	Fraction(int chis, int znam);

	// конструктор преобразования
	explicit Fraction(int value)
	{
		numerator = value;
		denominator = 1;
	}
	
	Fraction& operator++() // только для префикса
	{
		numerator += denominator; // изменяем «себя»
		return *this; // возвращаем «себя»
	}

	Fraction operator++(int) // только для постфикса
	{
		numerator += denominator;
		return *this;
	}

	double GetDecimal() const;
	void Print() const;
	void PrintDecimal() const;

	static Fraction Sum(const Fraction& left, const Fraction& right);
	
	bool GreaterThan(const Fraction& another) const;
	bool IsEquals(const Fraction& another) const;
	bool LessThan(const Fraction& another) const;

	int GetNumerator() const;
	int GetDenominator() const;
	void SetNumerator(int chis);
	void SetDenominator(int znam);

	Fraction operator + (/*Fraction* this, */ const Fraction& right);
	Fraction operator + (/*Fraction* this, */int);

	Fraction operator += (const Fraction& right);

	friend ostream& operator << (ostream&, const Fraction&);
	friend class cat;
	friend class String;
	friend class Date;
	friend class Student;
};

/////////////////////////////////////////////////////////////////////////////////////
// прототипы глобальных функций, реализованных в .cpp-файле Fraction.h
Fraction operator + (const Fraction&, const Fraction&);
Fraction operator + (const Fraction&, int);
Fraction operator + (int, const Fraction&);

//bool operator < (const Fraction&, const Fraction&);

//Fraction operator - (const Fraction&);

ostream& operator << (ostream&, const Fraction&);

//////////////////////////////////////////////////////
// REALIZATIONS:

// явный конструктор без параметров с делегированием
Fraction::Fraction() : Fraction(0, 1)
{
	// засчёт делегирования в теле метода делать уже нечего :)
}

// "главный" конструктор
Fraction::Fraction(int chis, int znam)
{
	SetNumerator(chis);
	SetDenominator(znam);
}

// получение дроби в десятичном формате
double Fraction::GetDecimal() const
{
	return (double)numerator / denominator;
}

// распечатка без перехода на следующую строку
void Fraction::Print() const
{
	cout << numerator << "/" << denominator << "\n";
}

// распечатка с переходом на следующую строку
void Fraction::PrintDecimal() const
{
	cout << GetDecimal() << "\n";
}

// геттер числителя
int Fraction::GetNumerator() const
{
	return numerator;
}

// геттер знаменателя
int Fraction::GetDenominator() const
{
	return denominator;
}

// сеттер числителя (без проверок)
void Fraction::SetNumerator(int chis)
{
	numerator = chis;
}

// сеттер знаменателя (знаменатель не должен быть равен 0!)
void Fraction::SetDenominator(int znam)
{
	denominator = znam != 0 ? znam : 1;
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Fraction::LessThan(const Fraction& right) const
{
	return GetDecimal() < right.GetDecimal();
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Fraction::GreaterThan(const Fraction& right) const
{
	return GetDecimal() > right.GetDecimal();
}

// сравнение двух дробей (левая дробь сравнивает себя с правой)
bool Fraction::IsEquals(const Fraction& right) const
{
	return GetDecimal() == right.GetDecimal();
}

// тестовая глобальная функция преобразования инта в дробь №1
void F1(Fraction a)
{
	cout << "explicit c-tor test global function F1\n";
}

// тестовая глобальная функция преобразования инта в дробь №2
Fraction F2()
{
	int a = 10;
	int b = 15;
	cout << "explicit c-tor test global function F2\n";
	return (Fraction)(a + b);
}

// сложение двух дробей (статическим методом класса)
Fraction Fraction::Sum(const Fraction& left, const Fraction& right)
{
	//return left + right;
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetDenominator() + right.GetNumerator() * left.GetDenominator());
	result.SetDenominator(left.GetDenominator() * right.GetDenominator());
	return result;
}

bool operator < (const Fraction& left, const Fraction& right)
{
	return left.GetDecimal() < right.GetDecimal();
}

Fraction operator - (const Fraction& fraction)
{
	Fraction temp;
	temp.SetNumerator(-fraction.GetNumerator());
	temp.SetDenominator(fraction.GetDenominator());
	return temp;
}

// пример перегрузки операции + глобальной функцией
Fraction operator + (const Fraction& left, const Fraction& right)
{
	cout << "GLOBAL FUNCTION === FRACTION + FRACTION!\n";
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetDenominator() + right.GetNumerator() * left.GetDenominator());
	result.SetDenominator(left.GetDenominator() * right.GetDenominator());
	return result;
}

// пример перегрузки операции + методом класса
Fraction Fraction::operator + (/*Fraction* this, */ const Fraction& right)
{
	cout << "CLASS METHOD === FRACTION + FRACTION!\n";
	Fraction result;
	result.SetNumerator(this->GetNumerator() * right.GetDenominator() + right.GetNumerator() * this->GetDenominator());
	result.SetDenominator(this->GetDenominator() * right.GetDenominator());
	return result;
}

/////////////////////////////////////////////

Fraction operator + (const Fraction& left, int value)
{
	cout << "GLOBAL FUNCTION === FRACTION + INT!\n";
	Fraction result;
	result.SetNumerator(1);
	result.SetDenominator(1);
	return result;
}

Fraction Fraction::operator + (/*Fraction* this, */ int right)
{
	cout << "CLASS METHOD === FRACTION + INT!\n";
	Fraction result;
	result.SetNumerator(2);
	result.SetDenominator(1);
	return result;
}

Fraction operator + (int left, const Fraction& right)
{
	cout << "GLOBAL FUNCTION === INT + FRACTION!\n";
	Fraction result;
	result.SetNumerator(3);
	result.SetDenominator(1);
	return result;
}

Fraction Fraction::operator += (const Fraction& right)
{
	cout << "+=\n";
	numerator = numerator * right.denominator + right.numerator * denominator;
	denominator *= right.denominator;
	return *this;
}

ostream& operator << (ostream& os, const Fraction& f)
{
	os << f.numerator << '/' << f.denominator;
	return os;
}

