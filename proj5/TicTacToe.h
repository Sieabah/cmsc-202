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
    *      None
    * Postconditions:
    *      None
    ****************************************************************/
    TicTacToe();

    /****************************************************************
     * Name: TicTacToe
     *    Constructor that accepts custom symbols
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
    TicTacToe(const char *playerSymbols);

    /****************************************************************
     * Name: ~TicTacToe
     *    Virtual destructor to remove any dynamically allocated memory.
     * Preconditions:
     *    None
     * Postconditions:
     *    Deletes all dynamic memory
     ****************************************************************/
    virtual ~TicTacToe();

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
     * Name: FindWinner
     *    Determines who is the winner
     *    Returns:
     *      true if game is over, with "winner" set to winning symbol
     *      false if no one has won yet and there are still moves left
     * Preconditions:
     *    None
     * Postconditions:
     *    Variable passed will hold the winners character
     ****************************************************************/
    virtual bool FindWinner(char& winner) const;

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
};

#endif //TICTACTOE_H
