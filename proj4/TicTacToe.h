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
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "GridGame.h"

const int TICTACTOE_BOARD_SIZE = 3;

class TicTacToe: public GridGame {
public:
    /****************************************************************
     * Name: TicTacToe
     *    Default (no-arg) constructor
     * Preconditions:
     *    None  
     * Postconditions:
     *    None
     ****************************************************************/
    TicTacToe();

    /****************************************************************
     * Name: TicTacToe
     *    Custom constructor
     * Preconditions:
     *    None  
     * Postconditions:
     *    None
     ****************************************************************/
    TicTacToe(const char *playerSymbols);

    /****************************************************************
     * Name: ~TicTacToe
     *    Default destructor
     * Preconditions:
     *    None  
     * Postconditions:
     *    None
     ****************************************************************/
    ~TicTacToe();

    /****************************************************************
     * Name: IsDone
     *    Checks whether the game is over
     * Preconditions:
     *    None  
     * Postconditions:
     *    None
     ****************************************************************/
    bool IsDone() const;

    /****************************************************************
     * Name: OutputResults
     *    Output winner and information
     * Preconditions:
     *    None  
     * Postconditions:
     *    None
     ****************************************************************/
    void OutputResults() const;

    /****************************************************************
     * Name: CheckWin
     *    Check if there is a winner
     * Preconditions:
     *    None  
     * Postconditions:
     *    None
     ****************************************************************/
    bool CheckWin(char playerSym, int row, int rowIncr, 
            int col, int colIncr) const;
};

#endif //TICTACTOE_H
