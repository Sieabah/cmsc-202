#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(int length=0, int width=0);
	virtual ~Rectangle();

	virtual int GetArea() const;
	virtual void Draw() const;
// write the public and private members
private:
	int m_length;
	int m_width;
};

#endif
