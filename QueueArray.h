#pragma once

class Queue
{
	int* ar = nullptr;
	int count = 0;
	int max_count;
	

public:
	Queue(int m)
	{
		max_count = m;
		ar = new int[max_count];
	}

	~Queue()
	{
		delete[] ar;
	}

	void Clear()
	{
		count = 0;
	}

	bool IsEmpty()
	{
		return count == 0;
	}

	bool IsFull()
	{
		return count == max_count;
	}

	int GetCount()
	{
		return count;
	}

	void Enqueue(int number)
	{
		if (!IsFull())
		{
			ar[count] = number;
			count++;
		}
			
	}

	int Dequeue()
	{
		if (!IsEmpty())
		{
			int first = ar[0];

			for (int i = 1; i < count; i++)
				ar[i - 1] = ar[i];

			count--;
			return first;
		}
		else
			throw "OOPS! Queue is empty!";
	}

	void Print()
	{
		cout << "-----------------------------------------------------\n";
		for (int i = 0; i < count; i++)
			cout << ar[i] << "  ";
		cout << "\n";
		cout << "-----------------------------------------------------\n";
	}
};

/*
// code for main:

	Queue q(25);

	for (int i = 0; i < 5; i++)
		q.Enqueue(rand() % 90 + 10);

	q.Print();

	q.Dequeue();

	q.Print();

	for (int i = 0; i < 2; i++)
		q.Enqueue(rand() % 90 + 10);

	q.Print();

	for (int i = 0; i < 3; i++)
		q.Dequeue();

	q.Print();
*/
