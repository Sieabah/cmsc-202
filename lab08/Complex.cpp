#include "Complex.h"

// Complex class constructor
Complex::Complex(int real, int imaginary):m_real(real),m_imaginary(imaginary)
{
 
}

// Accessor that returns real part of complex number
int Complex::GetReal() const
{
  return m_real;
}

// Accessor that returns imaginary part of complex number
int Complex::GetImaginary() const
{
  return m_imaginary;
}

const Complex Complex::operator+ (const Complex& rhs) const
{
	return Complex(m_real + rhs.GetReal(), m_imaginary + rhs.GetImaginary());
}

// Overloaded unary minus operator as member function 
const Complex Complex::operator-() const
{
	return Complex(-m_real, -m_imaginary);
}

ostream& operator<< (ostream& out, const Complex& number)
{
	char op[] = "+";
	int imagine = number.GetImaginary();
	if(imagine < 0)
	{
		op[0] = '-';
		imagine *= -1;
	}

	out << number.GetReal() << " " 
		<< op << " " 
		<< imagine << "i";
	return out;
}
