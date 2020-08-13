#pragma once

#include <iostream>
using namespace std;

template <typename T>
class ArrayList
{
	T* collection;
	unsigned int size;

public:
	ArrayList(unsigned int size = 10)
	{
		this->size = size;
		collection = new T[size];
	}

	ArrayList(unsigned int size, const T& value) : ArrayList(size)
	{
		for (unsigned int i = 0; i < size; i++)
			collection[i] = value;
	}

	ArrayList(unsigned int size, const T* arr) : ArrayList(size)
	{
		for (unsigned int i = 0; i < size; i++)
			collection[i] = arr[i];
	}

	ArrayList(const ArrayList& other) : ArrayList(other.size, other.collection) {}

	unsigned int GetSize() const
	{
		return size;
	}

	ArrayList<T>& operator=(const ArrayList<T>& other)
	{
		if (this == &other)
			return *this;

		delete[] collection;
		size = other.size;
		
		collection = new T[size];
		for (unsigned int i = 0; i < size; i++)
			collection[i] = other.collection[i];

		return *this;
	}

	T& operator[](unsigned int index)
	{
		if (index >= size)
			exit(0);
		return collection[index];
	}

	// http://ru.stackoverflow.com/questions/417601/%D0%9F%D0%B5%D1%80%D0%B5%D0%B3%D1%80%D1%83%D0%B7%D0%BA%D0%B0-%D0%BE%D0%BF%D0%B5%D1%80%D0%B0%D1%82%D0%BE%D1%80%D0%B0-%D0%B2-c?rq=1
	const T& operator[](unsigned int index) const
	{
		if (index >= size)
			exit(0);
		return collection[index];
	}

	~ArrayList()
	{
		if (collection)
			delete[] collection;
	}

	template<typename T>
	friend ostream& operator<<(ostream& os, ArrayList<T>& m);
};

template<typename T>
ostream& operator<<(ostream& os, ArrayList<T>& m)
{
	for (unsigned int i = 0; i < m.size; i++)
		os << m.collection[i] << "  ";
	return os;
}

template<typename T>
ArrayList<T> operator+(const ArrayList<T>& m1, const ArrayList<T>& m2)
{
	ArrayList<T> result(m1.GetSize() + m2.GetSize());
	for (unsigned int i = 0; i < m1.GetSize(); i++)
		result[i] = m1[i];
	for (unsigned int i = 0; i < m2.GetSize(); i++)
		result[i + m1.GetSize()] = m2[i];
	return result;
}



/*
	ArrayList<double> a(5, 3.5);
	for (unsigned int i = 0; i < a.GetSize(); i++)
		cout << a[i] << endl;
	a[2] = 5;
	auto b = a;
	const ArrayList<double>& c = b;
	cout << "third in c = " << c[2] << endl;
	//c[2] = 10;
	cout << c[2] << "\n";
	b[2] = 7;
	auto d = a + b;
	cout << d << endl;
*/