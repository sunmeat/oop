#pragma once

#include <iostream>
#include <string>
using namespace std;

class CompositionDemo
{
	class PegLeg // деревянная нога
	{
	public:
		string color;  // brown will be OK
		bool dirty;    // yes / no
		double length; // inches
		int usability; // 0 - 100%

		PegLeg()
		{
			cout << "Peg Leg C-TOR!\n";
		}

		~PegLeg()
		{
			cout << "Peg Leg DESTRUCTOR!\n";
		}
	};

	class HandHook // рука-крючок
	{
	public:
		string material;
		int usability;
		bool dirty;
		bool canMakeSelfy;

		HandHook()
		{
			cout << "Hand Hook C-TOR!\n";
		}
		~HandHook()
		{
			cout << "Hand Hook DESTRUCTOR!\n";
		}
	};

	class EyePatch // наглазник
	{
	public:
		string color; // black is timeless classic
		double size;  // XXL 
		bool elastic; // yes / no
		bool leather; // yes / no

		EyePatch()
		{
			cout << "Eye Patch C-TOR!\n";
		}
		~EyePatch()
		{
			cout << "Eye Patch DESTRUCTOR!\n";
		}
	};

	class Pirate
	{
	public:
		string nickname;
		PegLeg leg;
		HandHook hand;
		EyePatch patch;

		Pirate(string nickname)
		{
			this->nickname = nickname;
			cout << "Pirate C-TOR!\n";
		}
		
		~Pirate()
		{
			cout << "Pirate DESTRUCTOR!\n";
		}

		void CaptureShip()
		{
			cout << nickname << " says: " << "Prepare a boarding party!!!\n";
		}

		void SingSong()
		{
			cout << nickname << " singing: " << "\"...Yo-ho-ho, and a bottle of rum!!!\"\n";
		}
	};

public:
	static void Test()
	{
		Pirate p("Captain Jack Sparrow");
		p.CaptureShip();
		p.SingSong();
	}

	/////////////////////////////////////////////////////////

private:
	class Point
	{
	public:
		int X;
		int Y;

		Point()
		{
			X = Y = 0;
		}
		void SetPoint(int iX, int iY)
		{
			X = iX;
			Y = iY;
		}
	};

	class Figure
	{
		Point* obj;
		int count;
		int rc, gc, bc;

	public:
		Figure()
		{
			count = 0;
			obj = nullptr;
		}
		void CreateFigura(int p_count, int R, int G, int B)
		{
			if (p_count < 3) p_count = 3;
			count = p_count;
			rc = R;
			gc = G;
			bc = B;

			// выделение памяти под массив точек
			obj = new Point[count];
			if (!obj) exit(0);

			for (int i = 0; i < count; i++) {
				obj[i].SetPoint(rand() % 600, rand() % 400);
			}
		}

		// показ фигуры
		void ShowFigure()
		{
			ReleaseDC(Application::hwnd, Application::hdc);
			Application::hdc = GetDC(Application::hwnd);
			HPEN pen = CreatePen(rand() % 5, 1, RGB(rc, gc, bc));
			HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));

			SelectObject(Application::hdc, brush);
			Rectangle(Application::hdc, 0, 0, 610, 410);
			SelectObject(Application::hdc, pen);
			POINT p;
			MoveToEx(Application::hdc, obj[0].X, obj[0].Y, &p);
			for (int i = 1; i < count; i++) {
				LineTo(Application::hdc, obj[i].X, obj[i].Y);
				Sleep(1500 / count);
			}
			LineTo(Application::hdc, obj[0].X, obj[0].Y);
		}

		~Figure()
		{
			if (obj) delete[] obj;
		}

	};

	public:
		static void Test2()
		{
			while (true)
			{
				system("cls");
				COORD c = { 0, 0 };
				SetConsoleCursorPosition(Application::h, c);
				Figure f;
				int points;
				cout << "How many points do you want? ";
				cin >> points;
				f.CreateFigura(points, rand() % 255, rand() % 255, rand() % 255);
				f.ShowFigure();
			}
		}
};

// CompositionDemo::Test2();