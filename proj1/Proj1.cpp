/*****************************************
** File:    Proj1.cpp
** Project: CMSC 202 Project 1, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/4/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
**		This file holds the main project file which spins off the Reversi
**	program where the player can play the game
**
***********************************************/
#include <iostream>
#include <cctype>
#include <cstring>
#include <stdlib.h> 

#include "Reversi.h"
#include "Conversions.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Find out if we have enough variables to do anything with
	//2 isn't a magic number here, it's representative of how many required 
	//	arguments. This will only need to ever be 2.
	if(argc < 2)
	{
		//Print out how to use this
		cout << "How to run:" << endl;
		cout << "\t" << argv[0] << " <board size> " << endl;
		return 0;
	}

	//Get boardsize from first argument, convert it to number
	const int BOARD_SIZE = CharToNumber(argv[1]);

	PlayReversi(BOARD_SIZE);

	return 0;
}