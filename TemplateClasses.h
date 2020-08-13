#pragma once

class First
{
	int field;
	int ar[20];
};

template <int len, typename T>
class Second
{
	T field;
	T ar[len];
};

template <class T>
class TemplateList
{
	/* ... */
public:
	void Add(const T& Element) {}
	int IndexOf(const T& Element) { "какая-то дичь"; }
	/* ... */
};

/*
	Second<20, int> s1;
	Second<30, double> s2;

	List<int> li;
	List<string> ls;
	li.Add(17);
	ls.Add("Hello!");
	// ls.IndexOf("Test"); // попробуйте раскомментировать ;)
*/

// ===================================================================================

