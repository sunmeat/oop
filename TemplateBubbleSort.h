#pragma once

#include <iostream>
#include <string>
using namespace std;

struct Player
{
	string nick;
	int money;
	int expirience;
	int level;
};

bool operator > (const Player& one, const Player& two)
{
	return one.expirience > two.expirience;
}

/*void bubble_sort(int ar[], const unsigned int size)
{
	for (int pr = 0; pr < size - 1; pr++)
	{
		for (int i = size - 1; i > pr; i--)
		{
			if (ar[i] > ar[i - 1])
			{
				//swap(ar[i], ar[i - 1]);
				int temp = ar[i];
				ar[i] = ar[i - 1];
				ar[i - 1] = temp;
			}
		}
	}
}

void bubble_sort(double ar[], const unsigned int size)
{
	for (int pr = 0; pr < size - 1; pr++)
	{
		for (int i = size - 1; i > pr; i--)
		{
			if (ar[i] > ar[i - 1])
			{
				//swap(ar[i], ar[i - 1]);
				double temp = ar[i];
				ar[i] = ar[i - 1];
				ar[i - 1] = temp;
			}
		}
	}
}

void bubble_sort(Player ar[], const unsigned int size)
{
	for (int pr = 0; pr < size - 1; pr++)
	{
		for (int i = size - 1; i > pr; i--)
		{
			if (ar[i] > ar[i - 1])
			{
				//swap(ar[i], ar[i - 1]);
				Player temp = ar[i];
				ar[i] = ar[i - 1];
				ar[i - 1] = temp;
			}
		}
	}
} */

template <typename T> // параметр типа
void bubble_sort(T ar[], const unsigned int size)
{
	for (int pr = 0; pr < size - 1; pr++)
	{
		for (int i = size - 1; i > pr; i--)
		{
			if (ar[i] > ar[i - 1])
			{
				T temp = ar[i];
				ar[i] = ar[i - 1];
				ar[i - 1] = temp;
			}
		}
	}
}

/*
	// code for main:

	const int size = 5;
	int ar[size] = { 5, 15, 47, 28, 37 };
	bubble_sort(ar, size);
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << "\t";
	}
	cout << "\n\n";

	/////////////////////////////////////////////////

	double br[size] = { 5.2, 15.3, 47.4, 28.5, 37.6 };
	bubble_sort(br, size);
	for (int i = 0; i < size; i++)
	{
		cout << br[i] << "\t";
	}
	cout << "\n\n";

	Player first;
	first.expirience = 123123;
	first.level = 1;
	first.money = 1234;
	first.nick = "Vasya";

	Player second;
	second.expirience = 234;
	second.level = 2;
	second.money = 2345;
	second.nick = "Petya";

	Player third;
	third.expirience = 345;
	third.level = 3;
	third.money = 3456;
	third.nick = "Masha";

	Player fourth;
	fourth.expirience = 456;
	fourth.level = 4;
	fourth.money = 4567;
	fourth.nick = "Alex";

	Player fifth;
	fifth.expirience = 567;
	fifth.level = 5;
	fifth.money = 5678;
	fifth.nick = "Mira";

	Player players[size] = { first, second, third, fourth, fifth };

	bubble_sort(players, size);

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") " << players[i].nick << " - ";
		cout << players[i].expirience << ", ";
		cout << players[i].money << ", ";
		cout << players[i].level << "\n";
	}
*/