#pragma once

#include <iostream>
#include <string>
using namespace std;

class HashMap
{
	struct Entry
	{
		string key;
		int value;
		Entry* next;

	public:
		Entry(string key, int value, Entry* next)
		{
			this->key = key;
			this->value = value;
			this->next = next;
		}
	};

	Entry** table; // array of entries
	int capacity = 64; // initial capacity of hash map

public:

	HashMap()
	{
		table = new Entry* [capacity];
		for (int i = 0; i < capacity; i++)
		{
			table[i] = nullptr;
		}
	}

	void Put(string key, int data)
	{
		if (key == "")
		{
			return; // doesn't allow to store empty keys!
		}

		int hash = Hash(key); // calculate the hash of key

		Entry* temp = new Entry(key, data, nullptr); // create new entry

		// if table location does not contain any entry, store entry there
		if (table[hash] == nullptr)
		{
			table[hash] = temp;
		}
		else
		{
			Entry* previous = nullptr;
			Entry* current = table[hash];

			while (current != nullptr)
			{ // we have reached last entry of bucket
				if (current->key == key)
				{ // замена элемента!!!
					if (previous == nullptr)
					{  // node has to be insert on first of bucket
						table[hash] = temp; // подмена элемента, лежащего в массиве
						temp->next = current->next;
						return;
					}
					else
					{ // подмена элемента, найденного в цепочке дальше
						temp->next = current->next;
						previous->next = temp;
						return;
					}
				}
				previous = current;
				current = current->next;
			}
			previous->next = temp; // если в списке не было элемента с переданным ключом, добавить его в конец списка
		}
	}

	int Get(string key)
	{
		int hash = Hash(key);
		if (table[hash] == nullptr) {
			throw "OOPS!";
		}
		else
		{
			Entry* temp = table[hash];
			while (temp != nullptr)
			{
				if (temp->key == key)
					return temp->value;
			}
			temp = temp->next; // return value corresponding to key
		}
		throw "OOPS!";
	}

	bool Remove(string key)
	{
		int hash = Hash(key);

		if (table[hash] == nullptr)
		{
			return false;
		}
		else
		{
			Entry* previous = nullptr;
			Entry* current = table[hash];

			while (current != nullptr)
			{ // we have reached last entry node of bucket
				if (current->key == key)
				{
					if (previous == nullptr)
					{  // delete first entry node
						table[hash] = table[hash]->next;
						return true;
					}
					else {
						previous->next = current->next;
						return true;
					}
				}
				previous = current;
				current = current->next;
			}
			return false;
		}

	}

	void Display()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (table[i] != nullptr)
			{
				Entry* entry = table[i];
				while (entry != nullptr)
				{
					cout << "{" + entry->key  << "=" << entry->value << "}" << " ";
					entry = entry->next;
				}
			}
		}
		cout << "\n";
	}

private:
	int Hash(string key)
	{
		int sum = 0;
		for (int i = 0; i < key.size(); i++)
		{
			sum += (int)key[i];
		}
		
		return abs(sum % capacity);
	}

};

/*
// code for main:

	HashMap hm;

	hm.Put("Andrew", 12);
	hm.Put("Helen", 11);
	hm.Put("Denis", 10);
	hm.Put("Alex", 9);
	hm.Put("Maria", 8);

	cout << "value corresponding to key Andrew = "
		<< hm.Get("Andrew") << "\n";

	cout << "value corresponding to key Maria = "
		<< hm.Get("Maria") << "\n";

	hm.Display();

	hm.Remove("Andrew");
	hm.Remove("Helen");

	hm.Display();

*/
