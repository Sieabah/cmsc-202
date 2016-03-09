#ifndef FRACTION_H
#define FRACTION_H

//Fraction class
class Fraction
{
public:
	//Constructors
	Fraction();
	Fraction(const int numerator, const int denomenator);

	//Printing output
	void Output();
	
	//Able to call this function without creating a fraction
	static Fraction Reciprocal(Fraction &oldFrac);

	//Get current numerator and denomenator values
	void GetValues(int &numerator, int &denomenator);
private:
	//Numerator
	int m_numerator;
	//Denomenator
	int m_denomenator;
};

#endif