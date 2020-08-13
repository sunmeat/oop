#pragma once

class Stack
{
	// SIZE - максимальное количество элементов в стеке (больше 10 их не будет!)
public:
	enum { SIZE = 10, EMPTY = 0 };

private:
	int ar[SIZE]; // в качестве хранилища элементов стека избран массив
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

	// "заталкивание" (добавление) элемента в стек
	void Push(int value)
	{
		if (IsFull())
			throw "Stack overflow!";
		
		ar[top++] = value;
	}

	// извлечение элемента из стека
	int Pop()
	{
		if (IsEmpty())
			throw "Stack is empty!";

		top--;
		return ar[top];
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