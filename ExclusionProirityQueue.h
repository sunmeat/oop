#pragma once

class ExclusionPriorityQueue
{
	int* ar;
	int* pr;
	int max_count;
	int count;

public:
	ExclusionPriorityQueue(int m)
	{
		max_count = m;
		ar = new int[max_count];
		pr = new int[max_count];
		count = 0;
	}

	~ExclusionPriorityQueue()
	{
		delete[] ar;
		delete[] pr;
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

	void Enqueue(int number, int priority)
	{
		if (!IsFull())
		{
			ar[count] = number;
			pr[count] = priority;
			count++;
		}
	}

	int Dequeue()
	{
		if (!IsEmpty())
		{
			int max_pr = pr[0];
			int max_pr_position = 0;

			for (int i = 1; i < count; i++)
			{
				if (max_pr < pr[i])
				{
					max_pr = pr[i];
					max_pr_position = i;
				}
			}

			int elem = ar[max_pr_position];

			for (int i = max_pr_position; i < count - 1; i++)
			{
				ar[i] = ar[i + 1];
				pr[i] = pr[i + 1];
			}

			count--;
			return elem;
		}

		return -1;
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
