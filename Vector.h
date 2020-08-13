#pragma once

#include <iostream>
using namespace std;

class Vector
{
	int size = 0; // количество действительно присутствующих элементов в коллекции
	int capacity = 10; // ёмкость (вместительность, запас памяти)
	int* data; // указатель на динамический массив данных

public:
	Vector() : Vector(10)
	{
		// cout << "C-TOR WITHOUT PARAMS!\n";
	}

	Vector(int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		if (capacity > 500000000)
		{
			capacity = 500000000;
		}
		this->capacity = capacity;
		data = new int[capacity];
		// cout << "C-TOR WITH PARAMS!\n";
	}

	~Vector()
	{
		// cout << "DESTRUCTOR!\n";
		delete[] data;
	}

private:
	void EnsureCapacity(int count)
	{
		// если запас памяти достаточен
		if (capacity >= count) return;
		// если нет
		int new_capacity = capacity * 3 / 2 + 1;
		int* temp = new int[new_capacity];

		for (int i = 0; i < capacity; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;

		capacity = new_capacity;
		cout << "NEW CAP: " << capacity << "\n";
	}
public:
	void PushBack(int value)
	{
		EnsureCapacity(size + 1); // проверка, хватит ли места для нового элемента - делайте сами ;)
		data[size++] = value;
	}

	Vector operator+(const Vector& another)
	{
		Vector result;

		result.capacity = this->capacity + another.capacity;
		result.size = this->size + another.size;
		result.data = new int[result.capacity];

		int index = 0;
		for (; index < this->size; index++)
		{
			result.data[index] = this->data[index];
		}

		for (; index < this->size + another.size; index++)
		{
			result.data[index] = another.data[index - this->size];
		}

		return result;
	}


	bool Equals(const Vector& another)const
	{
		if (size == another.size)
		{
			int result = 0;
			for (int i = 0; i < size; i++)
			{
				if (data[i] == another.data[i])
				{
					result++;
				}
			}
			return result == size;
		}

		return false;
	}

	void PushFront(int value)
	{
		// EnsureCapacity(size + 1);
		for (int i = size; i > 0; i--)
		{
			data[i] = data[i - 1];
		}
		data[0] = value;
		size++;
	}

	Vector(const Vector& original)
	{
		this->size = original.size;
		this->capacity = original.capacity;
		this->data = new int[original.capacity];
		for (int i = 0; i < size; i++)
		{
			this->data[i] = original.data[i];
		}
	}

	void Clear()
	{
		size = 0;
	}

	bool IsEmpty()
	{
		return size == 0;
	}

	void Print()
	{
		if (IsEmpty())
		{
			cout << "Vector is empty.\n";
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				cout << data[i] << " ";
			}
			cout << endl;
		}
	}

	const int& operator[](unsigned int index) const
	{
		if (index >= size) throw "Incorrect index!"; // генерация исключения
		return data[index];
	}
};

