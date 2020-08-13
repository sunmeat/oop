#pragma once

#include <forward_list>
#include <algorithm>
#include <windows.h>
#include <stdexcept>
#include <iostream>
#include <typeinfo>
#include <direct.h>
#include <conio.h>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <ctime>
#include <list>
#include <io.h>
using namespace std;

class Application
{
private:
	Application()
	{
		// создавать объекты типа Application запрещено!
	}

public:
	enum class Color { BLACK, DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKMAGENTA, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE, GREY = GRAY };
	enum class KeyCode { BACKSPACE = 8, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80, ENTER = 13, SPACE = 32, ESCAPE = 27 };

	static HANDLE h;
	static HWND hwnd;
	static HDC hdc;

	static void Options(string title = "TITLE")
	{
		system("mode con cols=120 lines=50");

		title = "title " + title;
		system(title.c_str());

		// CONSOLE WINDOW CENTER SCREEN
		int desktop_width = GetSystemMetrics(SM_CXSCREEN);
		int desktop_height = GetSystemMetrics(SM_CYSCREEN);
		int console_width = 1000;
		int console_height = 750;
		int left_shift = (desktop_width - console_width) / 2;
		int top_shift = (desktop_height - console_height) / 2;
		MoveWindow(hwnd, left_shift, top_shift, console_width, console_height, true);

		CONSOLE_CURSOR_INFO info;
		info.bVisible = false;
		info.dwSize = 100;
		SetConsoleCursorInfo(h, &info);

		srand((unsigned int)time(0));
		int r = rand();

		setlocale(0, "UKR");
	}

	static void Exit()
	{
		int code = _getch();
		SetConsoleTextAttribute(h, (WORD)Color::BLACK);
	}

	static int Rand(int min, int max)
	{
		return (rand() * rand()) % (max - min + 1) + min;
	}

	static void SetConsoleColor(Color color)
	{
		SetConsoleTextAttribute(h, (WORD)color);
	}
};

// в С++ статические поля также должны быть объявлены за пределами класса
HANDLE Application::h = GetStdHandle(STD_OUTPUT_HANDLE);
HWND Application::hwnd = GetConsoleWindow();
HDC Application::hdc = GetDC(hwnd);