#pragma once

#include <iostream>
using namespace std;

class DoublyLinkedList
{
public:
	struct Node
	{
		int data = 0;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int count = 0;

public:
	int GetCount() const
	{
		return count;
	}

	void Clear()
	{
		while (head != nullptr)
		{
			DeleteFromHead();
		}
	}

	bool IsEmpty() const
	{
		return count == 0;
	}

	void AddToHead(int data)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->next = head;
		if (IsEmpty())
		{
			tail = temp;
		}
		else
		{
			head->prev = temp;
		}
		head = temp;
		count++;
	}

	void AddToTail(int data)
	{
		Node* temp = new Node();
		temp->data = data;
		temp->prev = tail;
		if (IsEmpty())
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}
		tail = temp;
		count++;
	}

private:
	Node* GetNode(int index)
	{
		if (index < 0 || index >= count) {
			return nullptr;
		}
		if (index == 0)
		{
			return head;
		}
		if (index == count - 1)
		{
			return tail;
		}

		Node* temp;
		int i = index;
		if (index <= count / 2) // если элемент находится в левой половине списка, то бежим слева направо
		{
			temp = head->next;
			while (--i)
			{
				temp = temp->next; // перемещаем указатель на следующий элемент
			}
		}
		else
		{
			temp = tail->prev;
			while (++i != count - 1) 
			{
				temp = temp->prev;
			}
		}
		return temp;
	}

public:
	void Insert(int data, int index)
	{
		if (index <= 0)
		{
			AddToHead(data);
			return;
		}
		if (index >= count)
		{
			AddToTail(data);
			return;
		}

		Node* elem = GetNode(index);

		Node* temp = new Node();

		temp->data = data;

		temp->next = elem;
		temp->prev = elem->prev;

		temp->prev->next = temp;
		temp->next->prev = temp;

		count++;
	}

	void DeleteFromHead()
	{
		if (IsEmpty())
		{
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		else
		{
			head->prev = nullptr;
		}
		count--;
	}

	void DeleteFromTail()
	{
		if (IsEmpty())
		{
			return;
		}
		Node* temp = tail;
		tail = tail->prev;
		delete temp;
		if (tail == nullptr)
		{
			head = nullptr;
		}
		else
		{
			tail->next = nullptr;
		}
		count--;
	}

	void DeleteByIndex(int position)
	{
		if (position == 0)
		{
			DeleteFromHead();
			return;
		}
		if (position == count - 1)
		{
			DeleteFromTail();
			return;
		}
		Node* sacrifice = GetNode(position);
		sacrifice->prev->next = sacrifice->next;
		sacrifice->next->prev = sacrifice->prev;
		delete sacrifice;
		count--;
	}

	friend ostream& operator << (ostream& os, const DoublyLinkedList& dll);

	int GetElementByIndex(int index)
	{
		if (index < 0 || index >= count)
			throw "Incorrect index";

		Node* temp = head;

		int i = 0;
		while (i < index)
		{
			temp = temp->next;
			i++;
		}

		return temp->data;
	}
};


ostream& operator << (ostream& os, const DoublyLinkedList& dll)
{
	if (dll.count == 0)
	{
		os << "list is empty!";
	}
	else
	{
		DoublyLinkedList::Node* temp = dll.head;
		while (temp != nullptr)
		{
			os << temp->data << " ";
			temp = temp->next;
		}
		return os;
	}
}

/*
	// code for main:

	DoublyLinkedList dll;
	cout << dll << "\n";

	dll.AddToTail(10);
	dll.AddToTail(20);
	dll.AddToTail(30);
	dll.AddToTail(40);
	cout << dll << "\n";

	dll.AddToHead(50);
	dll.AddToHead(60);
	dll.AddToHead(70);
	dll.AddToHead(80);
	cout << dll << "\n";

	dll.Insert(0, 7);
	dll.Insert(0, 5);
	dll.Insert(0, 3);
	dll.Insert(0, 1);
	cout << dll << "\n";

	dll.DeleteByIndex(1);
	dll.DeleteByIndex(3);
	dll.DeleteByIndex(5);
	dll.DeleteByIndex(7);
	cout << dll << "\n";
*/
