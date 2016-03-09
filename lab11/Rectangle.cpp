#include "Rectangle.h"
#include "Shape.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle()
{
	//No code
}

Rectangle::Rectangle(int length, int width)
: m_length(length), m_width(width)
{}

Rectangle::~Rectangle()
{
cout << "Rectangle Deconstructor" <<endl;
}

int Rectangle::GetArea() const
{
	return m_length * m_width;
}

void Rectangle::Draw() const
{
	cout << "Rectangle draw" << endl;
	for (int i = 0; i < m_length; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
}
