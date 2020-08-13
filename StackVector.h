#pragma once

class Stack
{
	enum { SIZE = 10, EMPTY = 0 };
	Vector vector;
	//vector<int> v;
	//int ar[10];
	int top = EMPTY; // индекс вершины стека

public:
	void Clear()
	{
		top = EMPTY;
	}

	bool IsEmpty()
	{
		return top == EMPTY;
	}

	bool IsFull()
	{
		return top == SIZE;
	}

	int GetCount()
	{
		return top;
	}

	void Push(int value)
	{
		if (!IsFull())
		{
			//ar[top] = value;
			vector.PushBack(value);
			//v.push_back(value);
			top++;
		}

		else throw "Stack overflow!";
	}

	int Pop()
	{
		if (!IsEmpty())
			return vector[--top];
			//return ar[--top];
			//return v[--top];
		else throw "Stack is empty!";
	}

	void PushLessValue(int value)
	{
		if (IsEmpty()) return;
		if (!IsFull() && vector[top - 1] > value)
			Push(value);
	}

	bool Contains(int value)
	{
		for (int i = 0; i <= top - 1; i++)
			if (vector[i] == value)
				return true;
		return false;
	}

	void PushUnique(int value)
	{
		if (!IsFull() && !Contains(value))
			Push(value);
	}

};

/*
// code for main:

	Stack st;

	while (st.IsFull() == false)
		st.Push(rand() % 90 + 10);

	while (st.IsEmpty() == false)
		cout << st.Pop() << "  ";

*/