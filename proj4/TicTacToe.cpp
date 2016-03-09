/*****************************************
** File:    TicTacToe.h
** Project: CMSC 202 Project 4, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    4/19/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *   Holds the definition of the TicTacToe class, all interactions with the 
 *      player
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
    : GridGame(GAME_TICTACTOE, "TicTacToe",TICTACTOE_BOARD_SIZE) 
{
    m_playerSymbols = "XO";
}

//TicTacToe
//Custom constructor
TicTacToe::TicTacToe(const char *playerSymbols) 
	: GridGame(GAME_TICTACTOE, "TicTacToe",TICTACTOE_BOARD_SIZE)
{
    m_playerSymbols = playerSymbols;
}

//~TicTacToe
//Default constructor
TicTacToe::~TicTacToe()
{
	//Nothing to destroy
}

//IsDone
//Checks whether the game is over
bool TicTacToe::IsDone() const
{
	int boardSize = GetBoardSize();

	//If there is 3 in a row
    for (int r = 0; r < boardSize; r++) {
    	for (int c = 0; c < boardSize; c++) {
    	   int rowIncr, colIncr;
		    for (rowIncr = -1; rowIncr <= 1; rowIncr++) {
		    	for (colIncr = -1; colIncr <= 1; colIncr++) {
		    	    if (rowIncr || colIncr) 
		    	    { // Going in some direction
		    			if(CheckWin(m_board[r][c], r, rowIncr, c, colIncr))
		    			{
		    				return true;
		    			}
		    	    }
		    	}
		    }
    	}
    }

    //All pieces are filled in
    for (int r = 0; r < boardSize; r++) {
    	for (int c = 0; c < boardSize; c++) {
    	   if (m_board[r][c] == '-') {
    		return false;
    	   }
    	}
    }

    //Game is over
    return true;
}

//CheckWin
//Check if there is a winner
bool TicTacToe::CheckWin(char playerSym, int row, int rowIncr, int col, int colIncr) const
{
	int r, c;
    int boardSize = GetBoardSize();
    int count = 1;

    for (r = row + rowIncr, c = col + colIncr; InBounds(r, c, boardSize);
	    r += rowIncr, c += colIncr) 
    {
    	if (m_board[r][c] == '-') 
        {
    	    break;
    	}
    	else if (m_board[r][c] == playerSym) 
        {
        	if(++count >= boardSize)
        	{
        		return true;
        	}
    	}
    }

    return false;
}

//Output
//Output winner and information
void TicTacToe::OutputResults() const
{
	char winner;
	bool tie = true;
	int boardSize = GetBoardSize();

	//Find who is the winner
    for (int r = 0; r < boardSize; r++) {
    	for (int c = 0; c < boardSize; c++) {
    	   int rowIncr, colIncr;
		    for (rowIncr = -1; rowIncr <= 1; rowIncr++) {
		    	for (colIncr = -1; colIncr <= 1; colIncr++) {
		    	    if (rowIncr || colIncr) 
		    	    { // Going in some direction
		    			if(CheckWin(m_board[r][c], r, rowIncr, c, colIncr))
		    			{
		    				tie = false;
		    				winner = m_board[r][c];
		    			}
		    	    }
		    	}
		    }
    	}
    }

	if(tie)
	{
		cout << "The game is a tie\n";
	}
	else
	{
		cout << "Player " << winner << " wins!\n";
	}	
}