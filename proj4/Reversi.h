/*****************************************
** File:    Reversi.h
** Project: CMSC 202 Project 4, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    4/19/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *  This file contains all the rules and definitions for the game 
 *      of reversi.
**
***********************************************/
#ifndef REVERSI_H
#define REVERSI_H
#include "GridGame.h"

const int REVERSI_BOARD_SIZE = 8;

class Reversi: public GridGame {
public:
    /****************************************************************
     * Name: Reversi
     *    Default (no-arg) constructor
     * Preconditions:
     *   None
     * Postconditions:
     *   None
     ****************************************************************/
    Reversi();

    /****************************************************************
     * Name: Reversi
     *    Custom constructor
     * Preconditions:
     *   Custom constructor constructor
     * Postconditions:
     *   
     ****************************************************************/
    Reversi(const char *playerSymbols);

    /****************************************************************
     * Name: ~Reversi
     *    Default destructor
     * Preconditions:
     *    None  
     * Postconditions:
     *    None
     ****************************************************************/
    ~Reversi();

    /****************************************************************
     * Name: IsDone
     *    Checks whether the game is over
     * Preconditions:
     *   None
     * Postconditions:
     *   None
     ****************************************************************/
    bool IsDone() const;

    /****************************************************************
     * Name: DoMove
     *    Puts new piece for player at {row, col} position
     * Preconditions:
     *   Assumes position has already been pre-checked by IsLegalMove() for
     *      valid bounds and emptiness.
     * Postconditions:
     *   
     ****************************************************************/
    void DoMove(int player, int row, int col);

    /****************************************************************
     * Name: OutputResults
     *    Print the final winning information
     * Preconditions:
     *   None
     * Postconditions:
     *   None
     ****************************************************************/
    void OutputResults() const;
protected:
    /****************************************************************
     * Name: FlipTilesInDir
     *    Flip all board pieces if reversi conditions are met
     * Preconditions:
     *   None
     * Postconditions:
     *   None
     ****************************************************************/
    void FlipTilesInDir(char playerSym, int row, int rowIncr,
			int col, int colIncr);
};

#endif //REVERSI_H
