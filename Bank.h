#pragma once

#include <iostream>
using namespace std;

class Bank
{
	static double totalbalance;
	double balance;

public:
	Bank()
	{
		//cout << "default c-tor!\n";
		SetBalance(0);
	}

	Bank(double b)
	{
		//cout << "param c-tor!\n";
		SetBalance(b);
		SetTotalbalance(GetTotalbalance() + b);
	}

private:
	void SetTotalbalance(double t)
	{
		totalbalance = t;
	}

public:
	double GetTotalbalance() const
	{
		return totalbalance;
	}

private:
	void SetBalance(double b)
	{
		if (b < 0) cout << "Обратите внимание:отрицательный баланс!\n";
		balance = b;
	}

public:
	double GetBalance()const
	{
		return balance;
	}

	void GiveKredit(double k)
	{
		if (balance > k)
		{
			balance -= k;
			totalbalance -= k;
		}
	}
	void ReturnKredit(double k)
	{
		balance += 1.2 * k;
		totalbalance += 1.2 * k;
	}

	void TakeDepozit(double d)
	{
		balance += d;
		totalbalance += d;
	}

	void ReturnDepozit(double d)
	{
		balance -= 1.1 * d;
		totalbalance -= 1.1 * d;
	}

	void PrintBalance()const
	{
		cout << "Баланс одного филиала равен:" << balance << "\n";
	}

	void PrintTotal()const
	{
		cout << "Общий баланс банка равен:" << totalbalance << "\n";
	}
};

double Bank::totalbalance = 1000000;