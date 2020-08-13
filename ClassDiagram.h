#include <iostream>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <stack>
#include <ctime>
#include <typeinfo>
#include <io.h>
#include <direct.h>
using namespace std;

#define PI 3.14159265358979323846

// точка
class Point
{
protected:
	double x_;
	double y_;

public:
	Point()
	{
		cout << "Point default c-tor!\n";
		x_ = y_ = 5;
	}
	Point(int x, int y)
	{
		cout << "Point param c-tor!\n";
		x_ = x;
		y_ = y;
	}
	void Print() const
	{
		cout << "Point - X: " << x_ << ", Y: " << y_ << "\n";
	}
	~Point()
	{
		//cout << "Point destructor!\n";
	}
};

// окружность
class Circle : virtual public Point
{
protected:
	double radius_;
	double area_;

public:
	Circle()
	{
		cout << "Circle default c-tor!\n";
		radius_ = 5;
		area_ = PI * radius_ * radius_;
	}
	Circle(int center_x, int center_y, int radius) : Point(center_x, center_y)
	{
		cout << "Circle param c-tor!\n";
		radius_ = radius;
		area_ = PI * radius_ * radius_;
	}
	void Print() const
	{
		//Point::Print();
		cout << x_ << " " << y_ << " " << radius_ << "\n";
	}
	~Circle()
	{
		//cout << "Circle destructor!\n";
	}
};

// квадрат
class Square : virtual public Point
{
protected:
	double side_;
	double area_; // TO DO: remove redundant field

public:
	Square()
	{
		cout << "Square c-tor!\n";
		side_ = 10;
		area_ = abs(side_) * abs(side_);
	}
	void Print() const
	{
		//Point::Print();
		cout << x_ << " " << y_ << " " << side_ << "\n";
	}
	~Square()
	{
		//cout << "Square destructor!\n";
	}
};

// окружность, вписанная в квадрат
class SquareCircle : public Circle, public Square
{
	double exclusive_area_;

public:
	SquareCircle()
	{
		x_ = 0;
		y_ = 0;
		cout << "SquareCircle c-tor!\n";
		exclusive_area_ = Square::area_ - Circle::area_; // OOPS!
	}
	void Print() const
	{
		//Square::Print();
		//Circle::Print();
		cout << x_ << " " << y_ << " " << side_ << "\n";
		cout << "SquareCircle::Print - OOPS!\n";
	}
	~SquareCircle()
	{
		cout << "SquareCircle destructor!\n";
	}
};