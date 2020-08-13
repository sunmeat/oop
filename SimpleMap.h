#pragma once

#include <iostream>
#include <string>
using namespace std;

class SimpleMap
{
	int size = 0;
	int capacity = 16;

public:
	class Entry
	{
		string key = "";
		int value = 0;

	public:
		Entry(string key, int value)
		{
			this->key = key;
			this->value = value;
		}

		string GetKey() const
		{
			return key;
		}

		int GetValue() const
		{
			return value;
		}

		void SetValue(int value)
		{
			this->value = value;
		}
	};

private:
	Entry** values = new Entry* [capacity];

public:

	SimpleMap()
	{
		for (int i = 0; i < capacity; i++)
		{
			values[i] = nullptr;
		}
	}

	int Get(const string& key)
	{
		for (int i = 0; i < size; i++)
		{
			if (values[i] != nullptr)
			{
				if (values[i]->GetKey() == key)
				{
					return values[i]->GetValue();
				}
			}
		}
		return -1;
	}

	int operator[](const string& key)
	{
		return Get(key);
	}

	void Put(const string& key, int value)
	{
		bool insert = true;
		for (int i = 0; i < size; i++)
		{
			if (values[i]->GetKey() == key)
			{
				values[i]->SetValue(value);
				insert = false;
			}
		}
		if (insert)
		{
			EnsureCapacity();
			values[size++] = new Entry(key, value);
		}
	}

private:
	void EnsureCapacity()
	{
		if (size == capacity)
		{
			capacity *= 2;
			Entry** temp = new Entry* [capacity];
			for (int i = 0; i < capacity; i++)
			{
				if (i < size) temp[i] = values[i];
				else temp[i] = nullptr;
			}
			delete[] values;
			values = temp;
		}
	}

public:
	int GetSize() const
	{
		return size;
	}

	void Remove(const string& key)
	{
		for (int i = 0; i < size; i++)
		{
			if (values[i]->GetKey() == key)
			{
				values[i] = nullptr;
				size--;
				CondenseArray(i);
			}
		}
	}

private:
	void CondenseArray(int start)
	{
		for (int i = start; i < size; i++)
		{
			values[i] = values[i + 1];
		}
	}
};

/*
// code for main:

	SimpleMap map;
	map.Put("Valera", 11);
	map.Put("Olga", 12);
	map.Put("Dima", 9);

	if (map.Get("Andrew") == 11)
	{
		cout << "yes 1\n";
	}

	for (int i = 0; i < 10; i++)
	{
		map.Put(to_string(i), i);
	}

	if (map.GetSize() == 13)
	{
		cout << "yes 2\n";
	}

	if (map.Get("5") == 5)
	{
		cout << "yes 3\n";
	}

	if (map["7"] == 7)
	{
		cout << "yes 4\n";
	}

*/
