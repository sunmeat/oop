#pragma once

#include <iostream>
using namespace std;

//typedef unsigned int uint;
using uint = unsigned int;

template <class T>
struct ListItem
{
	T item;
	ListItem* next;
};

template <class T>
class List
{
private:
	ListItem<T>* head;
	uint count;
public:
	List();
	List(const List<T>& l);
	~List() { Clear(); }

	// очистка списка
	void Clear();

	// присваивание
	List<T>& operator=(const List<T>& original);

	// работа с размером списка
	uint GetCount() const { return count; }
	bool IsEmpty() const { return count == 0; }

	// доступ к элементам
	T& operator[](uint index);

	// добавление и удаление элементов
	void AddHead(const T& item);
	void AddTail(const T& item);
	void Insert(uint index, const T& item);
	void Remove(uint index);
};

template <class T>
List<T>::List()
{
	head = nullptr;
	count = 0;
}

template <class T>
List<T>::List(const List<T>& l)
{
	if (!l.count)
		head = 0;
	else
	{
		ListItem<T> *prev, *temp, *src = l.head;
		for (uint i = 0; i < l.count; i++)
		{
			temp = new ListItem<T>;
			temp->item = src->item;
			temp->next = 0;

			if (!i)
				head = temp;
			else
				prev->next = temp;

			prev = temp;
			src = src->next;
		}
	}
	count = l.count;
}

template <class T>
void List<T>::Clear()
{
	if (count)
	{
		while (head)
		{
			ListItem<T>* temp = head;
			head = head->next;
			delete temp;
		}
		count = 0;
	}
}

template <class T>
List<T>& List<T>::operator=(const List<T>& l)
{
	// самоприсваивание
	if (this == &l) return *this;

	Clear();

	if (l.count)
	{
		ListItem<T> *prev, *temp, *src = l.head;
		for (uint i = 0; i < l.count; i++)
		{
			temp = new ListItem<T>;
			temp->item = src->item;
			temp->next = nullptr;

			if (!i)
				head = temp;
			else
				prev->next = temp;

			prev = temp;
			src = src->next;
		}
		count = l.count;
	}

	return *this;
}

template <class T>
T& List<T>::operator[](uint index)
{
	if (index >= count)
		return head->item;

	auto temp = head;
	int i = 0;

	// цикл поиска элемента
	while (i++ < index)
		temp = temp->next;

	return temp->item;
}

template <class T>
void List<T>::AddHead(const T& item)
{
	Insert(0, item);
}

template <class T>
void List<T>::AddTail(const T& item)
{
	auto temp = new ListItem<T>;
	temp->item = item;
	temp->next = nullptr;

	if (!count)
		head = temp;
	else
	{
		auto tail = head;
		while (tail->next)
			tail = tail->next;
		tail->next = temp;
	}
	count++;
}

template <class T>
void List<T>::Insert(uint index, const T& item)
{
	if (index > count)
		return;

	auto temp = new ListItem<T>;
	temp->item = item;

	if (!index)
	{
		if (!count)
		{
			head = temp;
			head->next = nullptr;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}
	else
	{
		ListItem<T>* prev = head;
		int i = 0;
		while (i++ < index)
			prev = prev->next;
		temp->next = prev->next;
		prev->next = temp;
	}
	count++;
}

template <class T>
void List<T>::Remove(uint index)
{
	if (index >= count)
		return;

	ListItem<T>* temp;

	if (!index)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		ListItem<T>* prev = head;
		int i = 0;
		while (i++ < index - 1)
			prev = prev->next;
		temp = prev->next;
		prev->next = temp ? temp->next : nullptr;
		delete temp;
	}
	count--;
}

/*
	List<int> l;
	l.AddHead(1);
	l.AddHead(2);
	l.AddTail(3);
	cout << l.GetCount() << "\n";
*/