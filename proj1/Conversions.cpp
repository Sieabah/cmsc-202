/*****************************************
** File:    Conversions.cpp
** Project: CMSC 202 Project 1, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/4/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
**		This file holds conversions between types
**
***********************************************/
#include "Conversions.h"
#include <stdlib.h> 

// CharToNumber
// Given a pointer to char, return integer value
int CharToNumber(char* value)
{
	return atoi(value);
}