/*****************************************
** File:    Fraction.cpp
** Project: CMSC 202 Project 2, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    4/3/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *   This file contains the declaration for the Fraction class. Including
 *		the overloaded operators
 *	DUE TO A DISPUTE ON PIAZZA ABOUT THE MATHEMATICS OF THE CALCULATOR
 *		I HAVE CREATED A VARIABLE THAT CHANGES HOW IT COMPUTES. WHEN IT IS
 *		TRUE IT DOES THE FRACTION AS A TRUE MIXED NUMBER. WHEN IT IS FALSE
 *		IT DOES NOT FOLLOW MIXED NUMBER RULES AND SIMPLY HAS A FRACTION WITH
 *		A WHOLE NUMBER, THEY ARE NOT RELATED IN THE SLIGHTEST.
**
***********************************************/

#include "Fraction.h"
#include <stdlib.h> 
#include <cmath>

//Default (no-arg) constructor
//Default constructor
Fraction::Fraction()
{
	Fraction(0);
}

//One operator constructor
//Single number fraction
Fraction::Fraction(long long int whole)
{
	Fraction(whole,0,1);
}

//Full constructor
//Defines all parts of the fraction
Fraction::Fraction(long long int whole, long long int numerator, long long int denominator)
{
	m_whole = whole;
	m_numerator = numerator;

	//Make sure denominator isn't zero
	if(denominator == 0)
	{
		cout << "err: division by zero\n";
		exit(EXIT_FAILURE);
	}
	
	m_denominator = denominator;

	//https://piazza.com/class/hqvf8pwsx4d55b?cid=290
	//True uses true mixed number mathematics.
	//False uses bogus mixed number logic for the project.
	m_mathematicallyCorrect = false;
}

//GetWholeNumber
//Returns the whole number
long long int Fraction::GetWholeNumber(void) const
{
	return m_whole;
}

//GetNumerator
//Returns the numerator
long long int Fraction::GetNumerator(void) const
{
	return m_numerator;
}

//GetDenominator
//Returns the numerator
long long int Fraction::GetDenominator(void) const
{
	return m_denominator;
}

//SetWholeNumber
//Sets whole number
void Fraction::SetWholeNumber(long long int num)
{
	m_whole = num;
}

//SetNumerator
//Set numerator value
void Fraction::SetNumerator(long long int num)
{
	m_numerator = num;
}

//SetDenominator
//Sets denominator value
void Fraction::SetDenominator(long long int num)
{
	m_denominator = num;
}

//operator+
//Addition operator
const Fraction Fraction::operator+(const Fraction &other) const
{
	//Create new fraction objects to deal with
	Fraction newFract(ConvertToFraction());
	Fraction otherFract(other.ConvertToFraction());

	//Make it rain good values
	newFract.MakeGoodFraction();
	otherFract.MakeGoodFraction();

	//Get the greatest common denominator
	long long int greatCommDenom = newFract.GetDenominator() * otherFract.GetDenominator();

	//Find new numerator
	long long int numerator = newFract.GetNumerator() * otherFract.GetDenominator() +
				otherFract.GetNumerator() * newFract.GetDenominator();

	//Create new fraction with those numbers
	Fraction fract(0,numerator,greatCommDenom);

	//Simplfy it and return it
	return Simplify(fract);
}

//operator-
//Subtraction operator
const Fraction Fraction::operator-(const Fraction &other) const
{
	//Create new fraction objects to deal with
	Fraction newFract(ConvertToFraction());
	Fraction otherFract(other.ConvertToFraction());

	//Make it rain good values
	newFract.MakeGoodFraction();
	otherFract.MakeGoodFraction();

	//Get the greatest common denominator
	long long int greatCommDenom = newFract.GetDenominator() * otherFract.GetDenominator();

	//Find new numerator
	long long int numerator = newFract.GetNumerator() * otherFract.GetDenominator() -
				otherFract.GetNumerator() * newFract.GetDenominator();

	//Create new fraction with those numbers
	Fraction fract(0,numerator,greatCommDenom);

	//Simplfy it and return it
	return Simplify(fract);
}

//operator*
//Multiplication operator
const Fraction Fraction::operator*(const Fraction &other) const
{
	//Create new fraction objects to deal with
	Fraction newFract(ConvertToFraction());
	Fraction otherFract(other.ConvertToFraction());

	//Make it rain good values
	newFract.MakeGoodFraction();
	otherFract.MakeGoodFraction();

	//Multiply denominator
	long long int denominator = newFract.GetDenominator() * otherFract.GetDenominator();

	//Multiply numerator
	long long int numerator = newFract.GetNumerator() * otherFract.GetNumerator();

	//Create new fraction with those numbers
	Fraction fract(0,numerator,denominator);

	//Simplfy it and return it
	return Simplify(fract);
}

//operator/
//Division Operator
const Fraction Fraction::operator/(const Fraction &other) const
{
	//Create new fraction objects to deal with
	Fraction newFract(ConvertToFraction());
	Fraction otherFract(other.ConvertToFraction());

	//Make it rain good values
	newFract.MakeGoodFraction();
	otherFract.MakeGoodFraction();

	//Multiply denominator
	long long int denominator = newFract.GetDenominator() * otherFract.GetNumerator();

	//Multiply numerator
	long long int numerator = newFract.GetNumerator() * otherFract.GetDenominator();

	//Create new fraction with those numbers
	Fraction fract(0,numerator,denominator);

	//Simplfy it and return it
	return Simplify(fract);
}

//Simplfy
//Simplifies and reduces the fraction
Fraction Fraction::Simplify(Fraction fract) const
{
	//Caclulate the numbers
	long long int numerator = fract.GetNumerator() % fract.GetDenominator();
	long long int denominator = fract.GetDenominator();
	long long int whole = fract.GetNumerator() / fract.GetDenominator();

	//Account for no fractional remainder
	if(numerator == 0)
	{
		denominator = 1;
	}

	//Reduce fraction
	for (long long int i = denominator; i > 1; i--) { 
		//If both numbers are divisible by the same number, 
		//	divide by said number
		if ((denominator % i == 0) && (numerator % i == 0)) {  
			denominator /= i;  
			numerator /= i;  
		}  
	}

	//Create new fraction with new values
	Fraction newFract(whole, numerator, denominator);

	newFract.MakeGoodFraction();
	//Return it
	return newFract;
}

//ConvertToFraction
//Converts whole number to fraction
Fraction Fraction::ConvertToFraction(void) const
{
	long long int numerator = 0;

	//https://piazza.com/class/hqvf8pwsx4d55b?cid=290
	if(m_mathematicallyCorrect){
		
		//Generate new numerator that completely encapsulates the whole number
		numerator = llabs(GetNumerator()) + llabs(GetWholeNumber() * GetDenominator());

		//Keep the sign from the original numbers
		if(GetWholeNumber() < 0 || GetNumerator() < 0 || GetDenominator() < 0)
		{
			numerator *= -1;
		}
	} else {
		numerator = GetNumerator() + GetWholeNumber() * GetDenominator();
	}

	//Generate new fraction with 0 as whole number, and new numerator
	Fraction newFrac(0,numerator,GetDenominator());

	return newFrac;
}

//Sign
//Checks if two numbers are of the same sign
bool Fraction::Sign(double one, double two) const
{
	return (one >= 0) ^ (two < 0);
}

void Fraction::MakeGoodFraction(void)
{
	//https://piazza.com/class/hqvf8pwsx4d55b?cid=290
	if(m_mathematicallyCorrect)
	{
		//Correct signs
		if(!Sign(GetNumerator(), GetDenominator()) || GetNumerator() < 0)
		{
			SetNumerator(-llabs(GetNumerator()));
			SetDenominator(llabs(GetDenominator()));
		}
		//Carry over negative
		if(!Sign(GetWholeNumber(), GetNumerator()))
		{
			SetWholeNumber(-llabs(GetWholeNumber()));
			SetNumerator(-llabs(GetNumerator()));
		}
	}
	else
	{
		if(GetDenominator() < 0 && GetNumerator() < 0)
		{
			SetNumerator(llabs(GetNumerator()));
			SetDenominator(llabs(GetDenominator()));
		}
		if(GetDenominator() < 0 && GetNumerator() > 0)
		{
			SetNumerator(-llabs(GetNumerator()));
			SetDenominator(llabs(GetDenominator()));
		}
	}
}

//operator<<
//Stream append operator
ostream& operator<< (ostream& out, const Fraction& fract)
{
	//Print formating of fraction
	out << fract.GetWholeNumber() << "&" 
		<< fract.GetNumerator() << "/"
		<< fract.GetDenominator();
	return out;
}