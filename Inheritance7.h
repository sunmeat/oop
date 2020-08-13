#pragma once

class GraphicsInheritanceDemo
{
	class Point
	{
		int x_ = 10;
		int y_ = 10;

	public:
		Point() {}
		Point(int x, int y) : x_(x), y_(y) {} // https://ravesli.com/urok-117-spisok-initsializatsii-chlenov-klassa/

		void SetY(int y) { y_ = y; }
		void SetX(int x) { x_ = x; }

		int GetX() const { return x_; }
		int GetY() const { return y_; }
	};

	using ushort = unsigned short;
	using uchar = unsigned char;

	class Rectangle
	{
		Point top_left_;
		ushort width_ = 265;
		ushort height_ = 265;
		COLORREF color_;

	public:
		enum class SHAPE_COLOR { BLACK, RED, GREEN, BLUE, WHITE, NONE };

		Rectangle() { color_ = RGB(255, 255, 255); }
		Rectangle(Point top_left, ushort width, ushort height)
		{
			top_left_ = top_left;
			width_ = width;
			height_ = height;
			SetColor(SHAPE_COLOR::RED);
		}

		Point GetTopLeftCorner() const { return top_left_; }
		ushort GetWidth() const { return width_; }
		ushort GetHeight() const { return height_; }
		COLORREF GetColor() const { return color_; }

		void SetPointTopLeft(const Point& top_left) { top_left_ = top_left; }
		void SetWidth(ushort width) { width_ = width; }
		void SetHeight(ushort height) { height_ = height; }
		void SetColor(uchar red, uchar green, uchar blue)
		{
			color_ = RGB(red, green, blue);
		}
		void SetColor(SHAPE_COLOR color)
		{
			switch (color)
			{
			case SHAPE_COLOR::BLACK:
				SetColor(0, 0, 0);
				break;
			case SHAPE_COLOR::RED:
				SetColor(255, 0, 0);
				break;
			case SHAPE_COLOR::GREEN:
				SetColor(0, 255, 0);
				break;
			case SHAPE_COLOR::BLUE:
				SetColor(0, 0, 255);
				break;
			case SHAPE_COLOR::WHITE:
				SetColor(255, 255, 255);
				break;
			}
		}

		void Draw() const
		{
			cout << "RECTANGLE!\n";
			//auto pen = CreatePen(PS_SOLID, 3, color_);
			//SelectObject(Application::hdc, pen);
			//MoveToEx(Application::hdc, top_left_.GetX(), top_left_.GetY(), NULL);
			//LineTo(Application::hdc, top_left_.GetX() + width_, top_left_.GetY());
			//LineTo(Application::hdc, top_left_.GetX() + width_, top_left_.GetY() + height_);
			//LineTo(Application::hdc, top_left_.GetX(), top_left_.GetY() + height_);
			//LineTo(Application::hdc, top_left_.GetX(), top_left_.GetY());
		}
	};

	class FilledRectangle : public Rectangle
	{
		COLORREF fill_color;
	public:
		FilledRectangle(Point top_left, ushort width, ushort height, COLORREF fill)
			: Rectangle(top_left, width, height), fill_color(fill) {}

		FilledRectangle() : Rectangle(Point(50, 50), 100, 50), fill_color(RGB(204, 204, 0)) {}

		void Draw() const // overriding
		{
			auto pen = CreatePen(PS_SOLID, 3, GetColor());
			SelectObject(Application::hdc, pen);
			auto hBrush = CreateSolidBrush(fill_color);
			SelectObject(Application::hdc, hBrush);

			::Rectangle(Application::hdc, GetTopLeftCorner().GetX(), GetTopLeftCorner().GetY(),
				GetTopLeftCorner().GetX() + GetWidth(), GetTopLeftCorner().GetY() + GetHeight());
		}
	};

public:
	static void Test()
	{
		Rectangle a;
		Rectangle b(Point(150, 150), 100, 100);
		b.SetColor(Rectangle::SHAPE_COLOR::GREEN);
		//b.Draw();

		Rectangle* p[2] = { &a, &b };
		p[0]->Draw();
		p[1]->Draw();
	}
};

// GraphicsInheritanceDemo::Test();