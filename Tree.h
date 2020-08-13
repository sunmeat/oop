#pragma once

#include <iostream>
using namespace std;

class Tree
{
public:

	struct Node // one element of the tree
	{
		int value; // useful data

		Node* parent;
		Node* right;
		Node* left;

		void ShowNode()
		{
			cout << value << ", ";
		}
	};

	///////////////////////////////////

private:
	Node* root;
	// int count;

public:
	Tree()
	{
		root = nullptr;
	}

	bool IsEmpty()
	{
		return root == nullptr;
	}

	~Tree()
	{
		Clear();
	}

private:
	void ShowTree(Node* elem)
	{
		if (elem != nullptr)
		{
			ShowTree(elem->left);
			elem->ShowNode();
			ShowTree(elem->right);
		}
	}

public:
	void ShowTree()
	{
		cout << "\n";
		ShowTree(root);
		cout << "\n";
	}

private:
	Node* GetRoot()
	{
		return root;
	}

	int GetCount(Node* elem, int count)
	{
		if (elem != nullptr)
		{
			count = GetCount(elem->left, count);
			count++; // 1
			count = GetCount(elem->right, count);
		}
		return count;
	}

public:
	int GetCount()
	{
		int count = 0;
		count = GetCount(root, count);
		return count;
	}

private:
	void Clear(Node* elem)
	{
		if (elem != nullptr)
		{
			Clear(elem->left);
			Clear(elem->right);
			delete elem;
			
			elem = nullptr;
		}
	}

public:
	void Clear()
	{
		if (!IsEmpty())
		{
			Clear(root);
			root = nullptr;
		}
	}

	Node* FindNode(int value)
	{
		if (IsEmpty())
			return nullptr;
		
		Node* f = root;
		while (true)
		{
			if (value < f->value)
			{
				if (f->left != nullptr)
					f = f->left;
				else
					break;
			}
			else if (value > f->value)
			{
				if (f->right != nullptr)
					f = f->right;
				else
					break;
			}
			else
				return f;
		}
		return nullptr;
	}

	void AddNode(int value)
	{
		if (FindNode(value))
			return;
		Node* n = new Node;
		n->right = n->left = nullptr;
		n->value = value;
		Node* parent = nullptr;
		if (IsEmpty())
		{
			root = n;
			root->parent = nullptr;
		}
		else
		{
			Node* p = root;
			while (p != nullptr)
			{
				parent = p;
				if (n->value > p->value)
					p = p->right;
				else
					p = p->left;
			}

			n->parent = parent;

			if (n->value < parent->value)
				parent->left = n;
			else
				parent->right = n;
			
		}
	}

	Tree& operator = (const Tree& obj)
	{
		if (!IsEmpty())
			Clear();

		AddNode(obj.root->value);
		Copy(obj.root);
		return *this;
	}

	Tree(const Tree& obj)
	{
		root = nullptr;
		AddNode(obj.root->value);
		Copy(obj.root);
	}

	void Copy(Node* elem)
	{
		if (elem->left != nullptr)
			AddNode(elem->left->value);
		if (elem->right != nullptr)
			AddNode(elem->right->value);
		if (elem->left != nullptr)
			Copy(elem->left);
		if (elem->right != nullptr)
			Copy(elem->right);
	}

	void DeleteNode(int value)
	{
		Node* d = FindNode(value);
		if (d == nullptr)
			return;

		Node* parent = d->parent;
		if (d == root && GetCount() == 1)
		{
			Clear();
			return;
		}
		if (d->left == nullptr && d->right == nullptr)
		{
			if (parent->left == d)
				parent->left = nullptr;
			else
				parent->right = nullptr;
			delete d;
			return;
		}
		if (d->left == nullptr && d->right != nullptr)
		{
			if (parent->left == d)
			{
				parent->left = d->right;
			}
			else
			{
				parent->right = d->right;

			}
			d->right->parent = parent;
			delete d;
			return;
		}

		if (d->left != nullptr && d->right == nullptr)
		{
			if (parent->left == d)
			{
				parent->left = d->left;
			}
			else
			{
				parent->right = d->left;

			}
			d->left->parent = parent;
			delete d;
			return;
		}
		if (d->left != nullptr && d->right != nullptr)
		{
			Node* r = d->right;
			if (r->right == nullptr && r->left == nullptr)
			{
				d->value = r->value;
				d->right = nullptr;
				delete r;
			}
			else if (r->left != nullptr)
			{
				Node* p = r->left;
				while (p->left != nullptr)
					p = p->left;
				d->value = p->value;
				if (p->right == nullptr)
					p->parent->left = nullptr;
				else
					p->parent->left = p->right;
				delete p;
			}
			else
			{
				d->value = r->value;
				d->right = r->right;
				delete r;
			}
		}
	}
};

/*
// code for main:

	const int size = 25;
	int ar[size] = { 100, 50, 25, 10, 5, 15, 35, 27, 40, 75, 60, 90, 300, 200, 150, 250, 500, 400, 350, 370, 700, 800, 750, 900, 100 };

	Tree bt;
	for (int i = 0; i < size; i++)
		bt.AddNode(ar[i]);
	bt.ShowTree();

	Tree bt2 = bt;
	bt2.ShowTree();

	Tree bt3;
	for(int i = 0;i<10;i++)
	bt3.AddNode(rand()%100);
	bt3.ShowTree();

	bt3 = bt2;

	Tree::Node* f = bt.FindNode(200);
	if(f)
	cout << f->value << "\n";

	bt.DeleteNode(750);
	bt.ShowTree();

	bt.DeleteNode(700);
	bt.ShowTree();

	bt.DeleteNode(500);
	bt.ShowTree();

	bt.DeleteNode(25);
	bt.ShowTree();

	cout << "\n" << bt3.GetCount() << "\n";

*/
