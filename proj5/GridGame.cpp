/*****************************************
** File:    
** Project: CMSC 202 Project 5, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    5/13/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *  
**
***********************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "GridGame.h"

using namespace std;

const int DEFAULT_NUM_PLAYERS = 2;


//GridGame
//Default (no-arg) constructor
GridGame::GridGame() 
{
	m_gameName = "Unknown";
	m_boardSize = 0;
	m_board = NULL;
	m_playerSymbols = NULL;
}

/*
* These constructors are protected, so only called by subclasses
*/

//GridGame
//Constructor that accepts custom symbols
GridGame::GridGame(const char *gameName,
	const char *playerSymbols, int boardSize) 
{
	m_gameName = gameName;
	m_boardSize = boardSize;
	m_playerSymbols = playerSymbols;
	m_board = new char *[boardSize];
	for (int r = 0; r < boardSize; r++)
	{
		m_board[r] = new char[boardSize];
		for (int c = 0; c < boardSize; c++)
		{
			m_board[r][c] = '-';
		}
	}
}

/* Output the a message saying:
* "Welcome to <GAME NAME>!\nHope you enjoy playing.\n"
*/

//OutputGreeting
//Greets the user with custom greeting
void GridGame::OutputGreeting() const 
{
	cout << "Welcome to " << m_gameName << "!\n";
}

/* Returns NULL on good move, else returns err string.
* Note that this check is game-neutral (at least for TTT and Reversi)
*/

//GetPlayerSymbol
//Returns player symbol
char GridGame::GetPlayerSymbol(int player) const 
{
	if (player >= static_cast<int>(strlen(m_playerSymbols))) 
	{
		cerr << "GetPlayerSymbol: illegal request\n";
		exit(1);
	}
	return m_playerSymbols[player];
}

//NumPlayers
//Returns number of players
int GridGame::NumPlayers() const 
{
	return DEFAULT_NUM_PLAYERS;
}

//GetBoardSize
//Returns board size
int GridGame::GetBoardSize() const 
{
	return m_boardSize;
}

//IsLegalMove
//Checks if move is legal
const char *GridGame::IsLegalMove(int player, int row, int col) const 
{
	if (row < 0 || row >= m_boardSize || col < 0 || col >= m_boardSize) 
	{
		return "Row or column out of range";
	}
	else if (m_board[row][col] != '-') 
	{
		return "Position already played";
	}
	else 
	{
		return NULL;
	}
}

//DoBasicMove
//Puts new piece for player at {row, col} position
void GridGame::DoBasicMove(int player, int row, int col) 
{
	const char *errStr;

// We're paranoid--double-check
	if ((errStr = IsLegalMove(player, row, col)) != NULL) 
	{
		cerr << errStr << "--exiting\n";
		exit(1);
	}
	m_board[row][col] = m_playerSymbols[player];
}


//OutputBoard
//Prints the board to the user
void GridGame::OutputBoard() const
{
	for (int r = 0; r < m_boardSize; r++) 
	{
		for (int c = 0; c < m_boardSize; c++) 
		{
			cout << m_board[r][c];
		}
		cout << endl;
	}
}

//~GridGame
//Virtual destructor to remove any dynamically allocated memory.
GridGame::~GridGame() 
{
	for (int r = 0; r < m_boardSize; r++) 
	{
		delete [] m_board[r];
		m_board[r] = NULL;
	}
	delete [] m_board;
	m_board = NULL;
}