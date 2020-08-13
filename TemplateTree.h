#pragma once

#include <iostream>
using namespace std;

template <class T>
struct TreeItem
{
	T item;
	int key;
	TreeItem *parent, *left, *right;
};

template <class T>
class TemplateTree
{
	TreeItem<T>* root;
	uint count;
public:
	TemplateTree();
	~TemplateTree() { Clear(); }

	// очистка дерева
	void Clear();

	// работа с размером дерева
	uint GetCount() const { return count; }
	bool IsEmpty() const { return count == 0; }

	void Insert(const T& item, int key);
	void Delete(TreeItem<T>* node);

	TreeItem<T>* GetRoot() const { return root; }

	// операции над деревом
	void Print(TreeItem<T>* node);
	TreeItem<T>* Search(TreeItem<T>* node, int key);
	TreeItem<T>* GetMin(TreeItem<T>* node);
	TreeItem<T>* GetMax(TreeItem<T>* node);
	TreeItem<T>* GetNext(TreeItem<T>* node);
	TreeItem<T>* GetPrev(TreeItem<T>* node);
};

template <class T>
TemplateTree<T>::TemplateTree()
{
	root = nullptr;
	count = 0;
}

template <class T>
void TemplateTree<T>::Clear()
{
	Delete(root);
}

template <class T>
void TemplateTree<T>::Insert(const T& item, int key)
{
	TreeItem<T>* x = new TreeItem<T>;
	x->item = item;
	x->key = key;
	x->left = nullptr;
	x->right = nullptr;

	TreeItem<T>* y = nullptr, *node = root;

	while (node != nullptr)
	{
		y = node;
		if (x->key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	x->parent = y;

	if (y == nullptr)
		root = x;
	else if (x->key < y->key)
		y->left = x;
	else
		y->right = x;

	count++;
}

template <class T>
void TemplateTree<T>::Delete(TreeItem<T>* node)
{
	if (node)
	{
		TreeItem<T> *x, *y;

		if (node->left == nullptr || node->right == nullptr)
			y = node;
		else
			y = GetNext(node);

		if (y->left)
			x = y->left;
		else
			x = y->right;

		if (x)
			x->parent = y->parent;

		if (!y->parent)
			root = x;
		else if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;

		if (y != node)
			node->item = y->item;

		delete y;

		count--;
	}
}

template <class T>
void TemplateTree<T>::Print(TreeItem<T>* node)
{
	if (node)
	{
		Print(node->left);
		cout << node->key << " : " << node->item << endl;
		Print(node->right);
	}
}

template <class T>
TreeItem<T>* TemplateTree<T>::Search(TreeItem<T>* node, int key)
{
	while (node != nullptr && key != node->key)
	{
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return node;
}

template <class T>
TreeItem<T>* TemplateTree<T>::GetMin(TreeItem<T>* node)
{
	if (node != nullptr)
		while (node->left != nullptr)
			node = node->left;
	return node;
}

template <class T>
TreeItem<T>* TemplateTree<T>::GetMax(TreeItem<T>* node)
{
	if (node != nullptr)
		while (node->right != 0)
			node = node->right;
	return node;
}

template <class T>
TreeItem<T>* TemplateTree<T>::GetNext(TreeItem<T>* node)
{
	TreeItem<T> *y = 0;
	if (node != nullptr)
	{
		if (node->right != nullptr)
			return GetMin(node->right);

		y = node->parent;
		while (y != nullptr && node == y->right)
		{
			node = y;
			y = y->parent;
		}
	}
	return y;
}

template <class T>
TreeItem<T>* TemplateTree<T>::GetPrev(TreeItem<T>* node)
{
	TreeItem<T> *y = nullptr;
	if (node != nullptr)
	{
		if (node->left != nullptr)
			return GetMax(node->left);

		y = node->parent;
		while (y != nullptr && node == y->left)
		{
			node = y;
			y = y->parent;
		}
	}
	return y;
}


/*
// code for main:

	TemplateTree<int> bt;
	for (int i = 0; i < 5; i++)
	{
		bt.Insert(rand() % 100, i);
	}

	bt.Print(bt.GetRoot());
*/