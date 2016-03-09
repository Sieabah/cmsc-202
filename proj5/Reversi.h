/*****************************************
** File:    Reversi.h
** Project: CMSC 202 Project 5, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    5/13/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *  Holds the Reversi class (PROVIDED)
**
***********************************************/

#ifndef REVERSI_H
#define REVERSI_H
#include "GridGame.h"

const int REVERSI_BOARD_SIZE = 4;

class Reversi: public GridGame {
public:

    /****************************************************************
     * Name: Reversi
     *    Default (no-arg constructor)
     * Preconditions:
     *  None
     * Postconditions:
     *  None
     ****************************************************************/
    Reversi();

    /****************************************************************
     * Name: Reversi
     *    Constructor that allows custom player symbols
     * Preconditions:
     *  None
     * Postconditions:
     *  None
     ****************************************************************/
    Reversi(const char *playerSymbols);

    /****************************************************************
     * Name: Reversi
     *    Virtual destructor to delete any dynamic memory
     * Preconditions:
     *  None
     * Postconditions:
     *  All dynamic memory is released.
     ****************************************************************/
    virtual ~Reversi();

    /****************************************************************
     * Name: IsDone
     *    Checks if the game is over
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
    virtual bool IsDone() const;

    /****************************************************************
     * Name: DoMove
     *    Puts new piece for player at {row, col} position
     * Preconditions:
     *    Assumes position has already been pre-checked by IsLegalMove() for
     *      valid bounds and emptiness.
     * Postconditions:
     *    None
     ****************************************************************/
    virtual void DoMove(int player, int row, int col);

    /****************************************************************
     * Name: OutputResults
     *    Print the results of the board to the players
     * Preconditions:
     *    Game is over
     * Postconditions:
     *    None
     ****************************************************************/
    virtual void OutputResults() const;

private:
    /****************************************************************
     * Name: InBounds
     *    Finds out if given values are in bounds
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
    static bool InBounds(int row, int col, int boardSize);

    /****************************************************************
     * Name: FlipTilesInDir
     *    Flips tiles in the direction given
     * Preconditions:
     *    None
     * Postconditions:
     *    All pieces between places will be flipped.
     ****************************************************************/
    void FlipTilesInDir(char playerSym, int row, int rowIncr,
			int col, int colIncr);
};

#endif //REVERSI_H
