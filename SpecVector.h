#pragma once

#include <iostream>
using namespace std;

template <typename T = int>
class SpecVector
{
	T* ptr;
	unsigned int size;

public:
	SpecVector(unsigned int size = 10)
	{
		this->size = size;
		ptr = new T[size];
	}

	SpecVector(unsigned int size, const T& value) : SpecVector(size)
	{
		for (unsigned int i = 0; i < size; i++)
			ptr[i] = value;
	}

	SpecVector(unsigned int size, const T* _ptr) : SpecVector(size)
	{
		for (unsigned int i = 0; i < size; i++)
			ptr[i] = _ptr[i];
	}

	SpecVector(const SpecVector& other) : SpecVector(other.size, other.ptr) {}

	unsigned int GetSize() const { return size; }

	SpecVector& operator=(const SpecVector& other)
	{
		if (this == &other)
			return *this;

		delete[] ptr;
		size = other.size;
		ptr = new T[size];
		for (unsigned int i = 0; i < size; i++)
			ptr[i] = other.ptr[i];
		return *this;
	}

	T& operator[](unsigned int index)
	{
		if (index >= size)
			exit(0);
		return ptr[index];
	}

	const T& operator[](unsigned int index) const
	{
		if (index >= size)
			exit(0);
		return ptr[index];
	}

	~SpecVector()
	{
		if (ptr) delete[] ptr;
	}

	unsigned int search(const T& value)
	{
		for (unsigned int i = 0; i < size; i++)
			if (ptr[i] == value)
				return i;
		return size;
	}
};

template <typename T>
SpecVector<T> operator+(const SpecVector<T>& m1, const SpecVector<T>& m2)
{
	SpecVector<T> result(m1.GetSize() + m2.GetSize());
	for (unsigned int i = 0; i < m1.GetSize(); i++)
		result[i] = m1[i];
	for (unsigned int i = 0; i < m2.GetSize(); i++)
		result[i + m1.GetSize()] = m2[i];
	return result;
}

template <typename T>
ostream& operator<<(ostream& os, SpecVector<T>& m)
{
	for (unsigned int i = 0; i < m.GetSize(); i++)
		os << m[i] << "  ";
	return os;
}

template <typename Tkey, typename Tvalue = double>
class myMap
{
	Tkey key;
	Tvalue value;
public:
	myMap() {}
	myMap(Tkey _key, Tvalue _value) : key(_key), value(_value) {}
	const Tkey& GetKey()const { return key; }
	const Tvalue& GetValue()const { return value; }
};

template <typename T, typename K>
ostream& operator<<(ostream& os, myMap<T, K>& m)
{
	os << "key = " << m.GetKey() << " value = " << m.GetValue() << "  ";
	return os;
}

//////////////////////////////////////////////////////////////////

typedef myMap<int, const char*> Imap;

template<> // специализация для типа Imap
class SpecVector<Imap>
{
	Imap* ptr;
	unsigned int size;
public:
	SpecVector(unsigned int size = 10)
	{
		this->size = size;
		ptr = new Imap[size];
	}
	Imap& operator[](unsigned int index)
	{
		if (index >= size)
			exit(0);
		return ptr[index];
	}
	unsigned int GetSize()const { return size; }

	unsigned int searchByKey(unsigned int key)
	{
		for (unsigned int i = 0; i < size; i++)
			if (ptr[i].GetKey() == key)
				return i;
		return size;
	}

	~SpecVector()
	{
		if (ptr) delete[] ptr;
	}
};

/*
// code for main:

	SpecVector<double> a(5, 3.5);
	for (unsigned int i = 0; i < a.GetSize(); i++)
		cout << a[i] << endl;
	a[2] = 5;
	auto  b = a;
	const SpecVector<double>& c = b;
	cout << "third in c = " << c[2] << endl;
	b[2] = 7;
	auto d = a + b;
	cout << d << endl;

	SpecVector<SpecVector<double>> e(3);
	e[0] = a, e[1] = c, e[2] = a;
	cout << e << endl;
	auto f = e;

	SpecVector<SpecVector<SpecVector<double>>> k(2);
	k[0] = f, k[1] = e;
	cout << k << endl;
	cout << k[0][0][0] << endl;


	int m[] = { 1, 2, 3, 4, 5 };
	SpecVector<int> a2(5, m);
	cout << a2.search(4) << endl;
	cout << a2.search(7) << endl;

	myMap<int, double> a3(3, 2.5);
	cout << a3 << endl;

	const char *s[] = { "Sidorov", "Ivanov", "Petrov" };

	SpecVector<myMap<int, const char *>> spisok(3);
	spisok[0] = (myMap<int, const char *>(5, s[0]));
	spisok[1] = (myMap<int, const char *>(15, s[1]));
	spisok[2] = (myMap<int, const char *>(12, s[2]));
	cout << spisok << endl;

	int b2 = spisok.searchByKey(15);
	cout << b2 << "\n";
*/

