/*****************************************
** File:    TicTacToe.cpp
** Project: CMSC 202 Project 5, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    5/13/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *  Holds the TicTacToe class (PROVIDED)
**
***********************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "TicTacToe.h"

using namespace std;

//TicTacToe
//Default (no-arg) constructor
TicTacToe::TicTacToe()
: GridGame("TicTacToe", "XO", TICTACTOE_BOARD_SIZE)
{}

//TicTacToe
//Constructor that accepts custom symbols
TicTacToe::TicTacToe(const char *playerSymbols)
: GridGame("TicTacToe", playerSymbols, TICTACTOE_BOARD_SIZE)
{}

//~TicTacToe
//Virtual destructor to remove any dynamically allocated memory.
TicTacToe::~TicTacToe()
{}

//IsDone
//Checks if the game is over
bool TicTacToe::IsDone() const 
{
    char winner;  // Dummy
    return (FindWinner(winner));
}

//FindWinner
//Determines who is the winner
 bool TicTacToe::FindWinner(char& winner) const 
 {
 	int r, c;
 	int bdSize = GetBoardSize();

    // Game is over when someone has bdSize-in-a-row
    // First, check each column
 	for (r = 0; r < bdSize; r++) 
 	{
 		winner = m_board[r][0];
 		if (winner != '-') 
 		{
 			for (c = 1; c < bdSize; c++) 
 			{
 				if (m_board[r][c] != winner) 
 				{
 					break;
 				}
 			}
 			if (c >= bdSize) 
 			{
 				return true;
 			}
 		}
 	}

    // Now, check each column
 	for (c = 0; c < bdSize; c++) 
 	{
 		winner = m_board[0][c];
 		if (winner != '-') 
 		{
 			for (r = 1; r < bdSize; r++) 
 			{
 				if (m_board[r][c] != winner) 
 				{
 					break;
 				}
 			}
 			if (r >= bdSize) 
 			{
 				return true;
 			}
 		}
 	}
    // Lastly, check diagonals
 	winner = m_board[0][0];
 	if (winner != '-') 
 	{
 		for (r = 1; r < bdSize; r++) 
 		{
 			if (m_board[r][r] != winner) 
 			{
 				break;
 			}
 		}
 		if (r >= bdSize) 
 		{
 			return true;
 		}
 	}
 	winner = m_board[0][bdSize - 1];
 	if (winner != '-') 
 	{
 		for (r = 1; r < bdSize; r++) 
 		{
 			if (m_board[r][bdSize - 1 - r] != winner) 
 			{
 				break;
 			}
 		}
 		if (r >= bdSize) 
 		{
 			return true;
 		}
 	}

    // Okay, found no winners--see if there is anywhere else to move
 	for (r = 0; r < bdSize; r++) 
 	{
 		for (c = 0; c < bdSize; c++) 
 		{
 			if (m_board[r][c] == '-') 
 			{
 				return false;
 			}
 		}
 	}
    winner = '\0';  // Indicate a draw
    return true;
}

//DoMove
//Puts new piece for player at {row, col} position
 void TicTacToe::DoMove(int player, int row, int col) 
 {
 	DoBasicMove(player, row, col);
    // Nothing else to do--checking for 3-in-a-row is done elsewhere.
 }


//OutputResults
//Print the results of the board to the players
 void TicTacToe::OutputResults() const 
 {
 	char winner;

 	if (!FindWinner(winner)) 
 	{
 		cerr << "OutputResults(): called before game over??\n";
 		exit(1);
 	}
 	if (winner != '\0') 
 	{
 		cout << "Player " << winner << " wins!\n";
 	}
 	else 
 	{
 		cout << "The game is a tie\n";
 	}
 }
