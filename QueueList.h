#pragma once

class Queue
{
	DoublyLinkedList list;
	int max_count;

public:
	Queue(int max_count)
	{
		this->max_count = max_count;
	}

	~Queue()
	{
		list.Clear();
	}

	void Clear()
	{
		list.Clear();
	}

	bool IsEmpty()
	{
		return list.GetCount() == 0;
	}

	bool IsFull()
	{
		return list.GetCount() == max_count;
	}

	int GetCount()
	{
		return list.GetCount();
	}

	void Enqueue(int number)
	{
		if (!IsFull())
		{
			list.AddToTail(number);
		}
		//else
		//	throw "OOPS! Queue is full!\n";
	}

	int Dequeue()
	{
		if (!IsEmpty())
		{
			int first = list.GetElementByIndex(0);
			list.DeleteFromHead();

			list.AddToTail(first);

			return first;
		}
		else throw "Queue is empty!";
	}

	void Print()
	{
		// list.Print(); // !!! предпочтительнее в плане оптимизации!

		cout << "-----------------------------------------------------\n";
		
		int x = list.GetCount();

		for (int i = 0; i < x; i++)
			cout << list.GetElementByIndex(i) << "  ";
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