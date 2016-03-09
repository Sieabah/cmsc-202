#include "Triangle.h"
#include "Shape.h"
#include <iostream>

using namespace std;

Triangle::Triangle()
{
	//No code
}

Triangle::Triangle(int length, int height)
: m_length(length), m_height(height)
{
	//No code
}

Triangle::~Triangle()
{
	cout << "Triangle Deconstructor" <<endl;
}

int Triangle::GetArea() const
{
	return 0.5 * m_length * m_height;
}

void Triangle::Draw() const
{
	cout << "Triangle draw" << endl;
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_length-i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
}
