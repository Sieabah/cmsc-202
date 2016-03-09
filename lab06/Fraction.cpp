#include "Fraction.h"
#include <iostream>
#include <stdlib.h>

//Default constructor, with default values;
Fraction::Fraction()
{
	m_numerator = 1;
	m_denomenator = 1;
}

//Constructor that takes values when created
Fraction::Fraction(const int numerator, const int denomenator)
{
	//If denomenator is zero
	if(denomenator == 0)
	{
		//Quit because it's not possible to have a zero in the denomenator
		std::cout << "Can't have a denomenator of zero!" << std::endl;
		exit(EXIT_FAILURE);
		return;
	}
	else
	{
		//Otherwise declare as normal
		m_numerator = numerator;
		m_denomenator = denomenator;
	}
}

//Get the values of the fraction individually
void Fraction::GetValues(int &numerator, int &denomenator)
{
	//Set the passed variables as the internal variables
	numerator = m_numerator;
	denomenator = m_denomenator;
}

//Print out the fraction
void Fraction::Output()
{
	std::cout << m_numerator << "/" << m_denomenator << std::endl;
}

//Return the reciprocal of the given fraction
Fraction Fraction::Reciprocal(Fraction &oldFrac)
{
	//Create shell variables
	int numerator, denomenator;
	//Get the values
	oldFrac.GetValues(numerator, denomenator);

	//Return swapped Fraction
	return Fraction(denomenator,numerator);
}