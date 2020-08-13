#pragma once

template <typename T>
void sort(T array[], int size)   // объявление и определение
{
	T t;
	for (int i = 0; i < size - 1; i++)
		for (int j = size - 1; j > i; j--)
			if (array[j] < array[j - 1])
			{
				t = array[j];
				array[j] = array[j - 1];
				array[j - 1] = t;
			}
}

template<int BufferSize>         // целочисленный параметр
char* read()
{
	char* Buffer = new char[BufferSize];
	return Buffer;
}

/*
	int ar[5] = { 5, 4, 3, 2, 1 };
	sort<int>(ar, 5);

	sort(ar, 5); // Выведение значений параметров
	// компилятор может сам вывести (логически определить) значение параметра шаблона функции
	// из аргумента функции. Например, при вызове функции sort необязательно указывать
	// параметр шаблона (если он совпадает с типом элементов аргумента - массива)

	char c[] = "abdec";
	sort<char>(c, strlen(c));

	//sort<int>(c, 5);    // ошибка! у sort<int> параметр int[], а не char[]

	for (int i = 0; i < 5; i++)
		cout << ar[i] << " - " << c[i] << "\n";

	char* ReadString = read<20>();
	delete[] ReadString;
	ReadString = read<30>();
*/

// ===================================================================================

template <class T>
T Max(T a, T b)
{
	if (a > b) return a;
	else return b;
}

/*
	cout << Max(12, 100) << endl;
	cout << Max(12.33, 3.0) << endl;
	// cout << Max(12.33, 3) << endl; // ошибка! параметр "T" неоднозначен!
*/

// ===================================================================================

template <class T>
void MySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

/*
	int x = 5, y = 10;
	MySwap(x, y);
	cout << x << " " << y << "\n";

	COORD a{ 1, 1 }, b{ 2, 2 };
	MySwap(a, b);
	cout << "[" << a.X << ", " << a.Y << "], [" << b.X << ", " << b.Y << "]\n";
*/

// ===================================================================================

template <typename T, int N>
double avg(T(&ar)[N])
{
	double sum = 0;
	for (int i = 0; i < N; i++)
		sum += ar[i];
	return sum / N;
}

/*
	double arrayDouble[3] = { 4.5, 6.7, 9.0 };
	cout << avg(arrayDouble) << endl;

	int arrayInt[5] = { 1, 5, 9, 10, 12 };
	cout << avg(arrayInt) << endl;

	char arrayChar[4] = { 'A', 'B', 'B', 'C' };
	cout << (char)avg(arrayChar) << endl;

	auto& sm = arrayInt; // ref to array!
	int(&sm2)[5] = arrayInt;
*/