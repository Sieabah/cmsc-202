/*****************************************
** File: GridGame.cpp
** Project: CMSC 202 Project 4, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    4/19/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *   Holds the definition of the GridGame class, including interactions with the
 *      basic class
**
***********************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "GridGame.h"

using namespace std;

//GridGame
//Default (no-arg) constructor
GridGame::GridGame() {
    m_type = GAME_UNKNOWN;
    m_gameName = "Unknown";

    InitBoard();
}

//GridGame
//Custom Constructor
GridGame::GridGame(enum GameType type, const char *gameName, int size) {
    if(size < 0)
    {
        cerr << "GridGame: Size is negative\n";
        exit(1);
    }

    m_type = type;
    m_gameName = gameName;
    m_boardSize = size;

    InitBoard();
}

//OutputGreeting
//Greet the user to the game
void GridGame::OutputGreeting() const {
    cout << "Welcome to " << m_gameName << "!\n";
}

//InitBoard
//Initialize the board with dashes
void GridGame::InitBoard()
{
    m_board = new char *[GetBoardSize()];

    //Go through board
    for (int r = 0; r < GetBoardSize(); r++) {
        m_board[r] = new char[GetBoardSize()];
        for (int c = 0; c < GetBoardSize(); c++) {
            m_board[r][c] = '-';
        }
    }
}

//GetBoardSize
//Returns size of the current board
int GridGame::GetBoardSize() const {
    return m_boardSize;
}

//GetPlayerSymbol
//Returns player symbol
char GridGame::GetPlayerSymbol(int player) const {
    if (player >= static_cast<int>(strlen(m_playerSymbols))) {
        cerr << "GetPlayerSymbol: illegal request\n";
        exit(1);
    }
    return m_playerSymbols[player];
}

//IsLegalMove
//Find out if play is a legal move
const char *GridGame::IsLegalMove(int player, int row, int col) const {
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

//GoBasicMove
//Puts new piece for player at {row, col} position
void GridGame::DoBasicMove(int player, int row, int col) {
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
//Draw the board to the console
void GridGame::OutputBoard() const {
    for (int r = 0; r < m_boardSize; r++) 
    {
    	for (int c = 0; c < m_boardSize; c++) 
        {
    	    cout << m_board[r][c];
    	}
    	cout << endl;
    }
}

//InBounds
//Determine if play is in bounds
bool GridGame::InBounds(int row, int col, int boardSize) {
    return (row >= 0 && row < boardSize && col >= 0 && col < boardSize);
}

//DoMove
//Puts new piece for player at {row, col} position
void GridGame::DoMove(int player, int row, int col) {
    int rowIncr, colIncr;
    char playerSym = GetPlayerSymbol(player);

    DoBasicMove(player, row, col);
}