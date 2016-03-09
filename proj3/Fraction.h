/*****************************************
** File:    Fraction.h
** Project: CMSC 202 Project 2, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    4/3/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *   This file contains the declaration for the Fraction class. includes 
 *        operator overloading.
**
***********************************************/

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction
{
public:
     /****************************************************************
     * Name: Fraction
     *    Default (no-arg) constructor
     * Preconditions:
     *   None
     * Postconditions:
     *   Fraction of form 0&0/1
     ****************************************************************/
	Fraction();

	/****************************************************************
     * Name: Fraction
     *    One-arg constructor that initiates the whole
     * Preconditions:
     *   whole number is a valid integer
     * Postconditions:
     *   Fraction of form whole/0&1
     ****************************************************************/
	Fraction(long long whole);

	/****************************************************************
     * Name: Fraction
     *    Full constructor that intializes 
     * Preconditions:
     *   whole and numerator are both the same sign
     * Postconditions:
     *   Fraction of form whole&numerator&denominator
     ****************************************************************/
	Fraction(long long whole, long long numerator, long long denominator);

     /****************************************************************
     * Name: GetWholeNumber
     *    Returns whole number of the fraction
     * Preconditions:
     *   None
     * Postconditions:
     *   Returns integer
     ****************************************************************/
     long long GetWholeNumber(void) const;

     /****************************************************************
     * Name: GetNumerator
     *    Returns numerator of the fraction
     * Preconditions:
     *   none
     * Postconditions:
     *   Returns integer
     ****************************************************************/
     long long GetNumerator(void) const;

     /****************************************************************
     * Name: GetDenominator
     *    Returns denominator of the fraction
     * Preconditions:
     *   none
     * Postconditions:
     *   Returns integer
     ****************************************************************/
     long long GetDenominator(void) const;

     /****************************************************************
     * Name: SetWholeNumber
     *    Sets the whole number of the fraction
     * Preconditions:
     *   num - is an integer
     * Postconditions:
     *   Sets number to given number
     ****************************************************************/
     void SetWholeNumber(long long num);

     /****************************************************************
     * Name: SetNumerator
     *    Sets the numerator of the fraction
     * Preconditions:
     *   num - is an integer
     * Postconditions:
     *   Sets numerator to given number
     ****************************************************************/
     void SetNumerator(long long num);

     /****************************************************************
     * Name: SetDenominator
     *    Sets the denominator of the fraction
     * Preconditions:
     *   num - is an integer
     * Postconditions:
     *   Sets denominator to given number
     ****************************************************************/
     void SetDenominator(long long num);

     /****************************************************************
     * Name: ConvertToFraction
     *    Returns fraction with whole number removed and put into the fraction
     * Preconditions:
     *   none
     * Postconditions:
     *   Fraction - fraction with whole number = 0
     ****************************************************************/
     Fraction ConvertToFraction(void) const;

     /****************************************************************
     * Name: Simplify
     *    Returns fraction reduced w/ whole number
     * Preconditions:
     *   fract is a valid fraction
     * Postconditions:
     *   Fraction - fraction with whole number & reduced fraction
     ****************************************************************/
     Fraction Simplify(Fraction fract) const;

	/****************************************************************
     * Name: operator+
     *    Addition operator
     * Preconditions:
     *   other is defined
     * Postconditions:
     *   Fraction is addition of both
     ****************************************************************/
	const Fraction operator+(const Fraction &other) const;

	/****************************************************************
     * Name: operator-
     *    Subtraction operator
     * Preconditions:
     *   other is defined
     * Postconditions:
     *   Fraction is subtraction of both
     ****************************************************************/
	const Fraction operator-(const Fraction &other) const;

	/****************************************************************
     * Name: operator*
     *    Multiplication operator
     * Preconditions:
     *   other is defined
     * Postconditions:
     *   Fraction is multiplication of both
     ****************************************************************/
	const Fraction operator*(const Fraction &other) const;

	/****************************************************************
     * Name: operator/
     *    Division operator
     * Preconditions:
     *   other is defined
     * Postconditions:
     *   Fraction is division of both
     ****************************************************************/
	const Fraction operator/(const Fraction &other) const;

private:
	//Parts of the fraction
	long long m_whole;
	long long m_denominator;
	long long m_numerator;

     //https://piazza.com/class/hqvf8pwsx4d55b?cid=290
     bool m_mathematicallyCorrect;

     /****************************************************************
     * Name: MakeGoodFraction
     *    Makes the fraction values make sense
     * Preconditions:
     *   none
     * Postconditions:
     *   fraction has matching signs
     ****************************************************************/
     void MakeGoodFraction();

     /****************************************************************
     * Name: Sign
     *    Check if two numbers have the same sign
     * Preconditions:
     *   one and two are any number
     * Postconditions:
     *   boolean true/false depending on match
     ****************************************************************/
     bool Sign(double one, double two) const;
};

/****************************************************************
* Name: Operator<<
*    Print out fraction
* Preconditions:
*   fract is defined
* Postconditions:
*   Returns ostream
****************************************************************/
ostream& operator<< (ostream& out, const Fraction& fract);

#endif