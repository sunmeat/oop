#pragma once

#include <iostream>
using namespace std;

class SinglyLinkedList
{
public:
	struct Node
	{
		int data = 0;
		Node* next = nullptr;
	};

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int count = 0;

public:

	SinglyLinkedList()
	{

	}

	~SinglyLinkedList()
	{
		cout << "DESTRUCTOR!\n";
		Clear();
	}

	void AddToHead(int data)
	{
		Node* newElem = new Node();
		newElem->data = data;
		newElem->next = head;
		if (head == nullptr)
		{
			tail = newElem;
		}
		head = newElem;
		count++;
	}

	void AddToTail(int data)
	{
		Node* newElem = new Node;
		newElem->data = data;

		if (head == nullptr) // если список пустой (в нём 0 элементов)
		{
			head = newElem;
		}
		else
		{
			tail->next = newElem;
		}
		tail = newElem;
		count++;
	}

	void InsertInto(int data, int index)
	{
		if (index >= count)
		{
			AddToTail(data);
			return;
		}
		else if (index <= 0)
		{
			AddToHead(data);
			return;
		}

		// n - указатель на новый вставляемый элемент списка
		Node* n = new Node();
		n->data = data;

		// current - указатель на текущий элемент списка, поначалу - на нулевой элемент списка
		Node* current = head;

		// необходимо выполнить index - 1 переходов по списку, для того чтобы найти элемент ПЕРЕД вставляемым
		for (int i = 1; i < index; i++)
		{
			current = current->next;
		}

		// настройка 2 связок:
		// сначала новому элементу говорим, что за ним кто-то есть
		n->next = current->next;
		// тому, который находится ПЕРЕД вставляемым - сообщаем адрес нового
		current->next = n;

		count++;
	}

	void DeleteFromHead()
	{
		if (count == 0)
		{
			// cout << "Empty list!\n";
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;

		count--;

		if (count == 0)
		{
			tail = nullptr;
		}
	}

	void DeleteFromTail()
	{
		if (count == 0) {
			// cout << "Empty list!\n";
			return;
		}
		DeleteByIndex(count - 1);
	}

	void DeleteByIndex(int index)
	{
		if (index <= 0 || count == 1)
		{
			DeleteFromHead();
			return;
		}

		if (index >= count)
		{
			index = count - 1;
		}

		// current - указатель на текущий элемент списка, поначалу - на нулевой элемент списка
		Node* current = head;

		// необходимо выполнить index - 1 переходов по списку, для того чтобы найти элемент ПЕРЕД вставляемым
		for (int i = 1; i < index; i++)
		{
			current = current->next;
		}

		// del - указатель на удаляемый элемент
		Node* del = current->next;

		current->next = del->next;

		delete del;

		count--;
	}

	void Clear()
	{
		while (head != nullptr)
		{
			DeleteFromHead();
		}
	}

	void Print() const
	{
		if (count == 0)
		{
			cout << "Empty list!\n";
			return;
		}
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	int GetCount() const
	{
		return count;
	}

	int IndexOf(int value) const
	{
		if (count == 0)
		{
			return -1;
		}

		Node* current = head;
		for (int i = 0; i < count; i++)
		{
			if (current->data == value)
			{
				return i;
			}
			current = current->next;
		}

		return -1;
	}

	bool IsEmpty()
	{
		return count == 0;
	}

	void Reverse()
	{
		if (IsEmpty())
		{
			return;
		}
		Node* temp = 0;
		Node* current = head;
		while (current != NULL)
		{
			Node* next = current->next;
			current->next = temp;
			temp = current;
			current = next;
		}
		head = temp;
	}

	void SortAsc()
	{
		if (IsEmpty())
		{
			return;
		}
		for (Node* i = head; i != NULL; i = i->next)
		{
			for (Node* j = i->next; j != NULL; j = j->next)
			{
				if (i->data > j->data)
				{
					swap(i->data, j->data);
				}
			}
		}
	}

	void SortDesc()
	{
		SortAsc();
		Reverse();
	}

	void Shuffle()
	{
		int k = 0;
		int* ar = new int[count];
		Node* current = head;
		while (current != nullptr)
		{
			ar[k++] = current->data;
			current = current->next;
		}
		random_shuffle(ar, ar + k);
		current = head;
		k = 0;
		while (current != nullptr)
		{
			current->data = ar[k++];
			current = current->next;
		}
		delete[] ar;
	}

	SinglyLinkedList Clone()
	{
		SinglyLinkedList* copy = this;
		return *copy;
	}

	SinglyLinkedList operator+(const SinglyLinkedList& sll)
	{
		// формируем результирующий список на основании левого операнда
		SinglyLinkedList res = *this;

		Node* temp = sll.head;
		
		// перебираем все элементы правого списка
		for (int i = 0; i < sll.count; i++)
		{
			// и добавляем их в результирующий список
			res.AddToTail(temp->data);
			temp = temp->next;
		}
		
		return res;
	}

	bool operator > (const SinglyLinkedList& sll)
	{
		return count > sll.count;
	}

	operator int*()
	{
		return to_array();
	}

	int* to_array()
	{
		int* ar = new int[count];
		Node* current = head;
		for (int i = 0; i < count; i++)
		{
			ar[i] = current->data;
			current = current->next;
		}
		return ar;
	}

	SinglyLinkedList& operator=(const SinglyLinkedList& original)
	{
		// проверка на самоприсваивание
		// second = second;
		if (this == &original) return *this;

		// все элементы списка-копии должны быть уничтожены!
		this->Clear();

		// выставляем указатель на начало оригинального списка (который сейчас является правым операндом в вырадении типа SLL a = b;
		Node* current = original.head;
		// пробегаемся по всему оригинальному списку один раз от начала до конца
		for (int i = 0; i < original.count; i++)
		{
			// при добавлении в хвост копии списка создаётся новый нод
			AddToTail(current->data);
			// переместились на следующий элемент списка-оригинала
			current = current->next;
		}

		return *this;
	} 

	SinglyLinkedList(const SinglyLinkedList& original)
	{
		// выставляем указатель на начало оригинального списка (который сейчас является правым операндом в вырадении типа SLL a = b;
		Node* current = original.head;
		// пробегаемся по всему оригинальному списку один раз от начала до конца
		for (int i = 0; i < original.count; i++)
		{
			// при добавлении в хвост копии списка создаётся новый нод
			AddToTail(current->data);
			// переместились на следующий элемент списка-оригинала
			current = current->next;
		}
	}

	Node* ElemAt(int index) const
	{
		if (index <= 0)
		{
			return head;
		}
		if (index >= count - 1)
		{
			return tail;
		}
		Node* curent = head;

		for (int i = 0; i < index; i++)
		{
			curent = curent->next;
		}
		return curent;
	}
	
	int& operator[](const int index)
	{

		if (index < 0 || index >= count) throw "incorrect oops!";
		
		auto counter = 0;
		auto* current = head;

		while (current)
		{
			if (counter == index)
				return current->data;

			current = current->next;
			counter++;
		}
	}

	SinglyLinkedList MergeWith(const SinglyLinkedList& sll)
	{
		return *this + sll;
	}

	
	
};

// a = b;
// a = b = c = b = a = b = c;
// a++ = a.Clone() = ++c = b++ = a = b = c;

/*
	SinglyLinkedList sll;

	// вставка в конец списка
	sll.AddToTail(10);
	sll.AddToTail(20);
	sll.AddToTail(30);
	sll.AddToTail(40);
	sll.Print();

	// вставка в начало списка
	sll.AddToHead(50);
	sll.AddToHead(60);
	sll.AddToHead(70);
	sll.AddToHead(80);
	sll.Print();

	// количество элементов, поиск элементов
	cout << "count: " << sll.GetCount() << "\n";
	cout << "index of 70: " << sll.IndexOf(70) << ", index of 90: " << sll.IndexOf(90) << "\n";

	// вставка по позиции
	sll.InsertInto(-1, -1);
	sll.Print();
	sll.InsertInto(2, 2);
	sll.Print();
	sll.InsertInto(22, 22);
	sll.Print();

	// удаление с начала списка
	sll.DeleteFromHead();
	sll.DeleteFromHead();
	sll.DeleteFromHead();
	sll.Print();

	// удаление с конца списка
	sll.DeleteFromTail();
	sll.DeleteFromTail();
	sll.DeleteFromTail();
	sll.Print();

	// удаление по указанному индексу
	sll.DeleteByIndex(0);
	sll.DeleteByIndex(1);
	sll.DeleteByIndex(2);
	sll.Print();

	// очистка списка
	sll.Clear();
	sll.Print();
*/