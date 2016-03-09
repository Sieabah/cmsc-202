/*****************************************
** File:    TicTacToe.h
** Project: CMSC 202 Project 5, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    5/13/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *  Holds the TicTacToe class
**
***********************************************/

#ifndef LIFE_H
#define LIFE_H

#include "GridGame.h"

const int LIFE_BOARD_SIZE = 20;

class Life: public GridGame {
public:
    /****************************************************************
     * Name: Life
     *    Default (no-arg) constructor
    * Preconditions:
    *      None
    * Postconditions:
    *      None
    ****************************************************************/
     Life();

    /****************************************************************
     * Name: Life
     *    Constructor that accepts custom symbols
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
     Life(char* symbols);

    /****************************************************************
     * Name: ~Life
     *    Virtual destructor to remove any dynamically allocated memory.
     * Preconditions:
     *    None
     * Postconditions:
     *    Deletes all dynamic memory
     ****************************************************************/
     virtual ~Life();

    /****************************************************************
     * Name: NumPlayers
     *    Returns 1 for single life player
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
     virtual int NumPlayers() const;

    /****************************************************************
     * Name: IsDone
     *    Checks if the game is done, entered "0 0"
     * Preconditions:
     *    None
     * Postconditions:
     *    Game is done or not
     ****************************************************************/
     virtual bool IsDone() const;

    /****************************************************************
     * Name: DoMove
     *    Add or remove life cell
     * Preconditions:
     *    Move is a valid move already checked
     * Postconditions:
     *    Move is carried out
     ****************************************************************/
     virtual void DoMove(int player, int row, int col);

    /****************************************************************
     * Name: OutputResults
     *    Prints the results of the game to the user(s)
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
     virtual void OutputResults() const;

    /****************************************************************
     * Name: OutputBoard
     *    Prints out complete board, alternatively will print in top
     *         left corner.
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
     virtual void OutputBoard() const;

     /****************************************************************
     * Name: BackupBoard
     *    Copies the values from one board to another board
     * Preconditions:
     *    None
     * Postconditions:
     *    They will be equal
     ****************************************************************/
     virtual void BackupBoard(char **copyToBoard, char **copyFromBoard) const;

     /****************************************************************
     * Name: AgeBoard
     *    Run through x amount of generations for said board. Board given
     *      will have the completed aged board.
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
     virtual void AgeBoard(char** board, int generations, char symbol) const;

    /****************************************************************
     * Name: IsLegalMove
     *    Checks if move is legal
     * Preconditions:
     *    None
     * Postconditions:
     *    Returns NULL on good move, else returns err string.
     ****************************************************************/
     virtual const char *IsLegalMove(int player, int row, int col) const;
private:
    //Hold total number of generations
     int m_totalGenerations;

     //Hold intermittent generations
     int m_generations;

     //Holds board generation
     int m_boardGenerations;
     
     //Boolean if game is over since there really is no "end-check" for life.
     bool m_isDone;

     //Holds copy of old board for use with OutputBoard
     char **m_oldBoard;

     //Boolean for OutputBoard to print generations or single output
     bool m_autoGen;

     /****************************************************************
     * Name: InBounds
     *    Returns boolean if position is within bounds
     * Preconditions:
     *    None
     * Postconditions:
     *    Valid position
     ****************************************************************/
     virtual bool InBounds(int row, int col) const;

     /****************************************************************
     * Name: CheckTile
     *    Checks all 8 directions if the current tile will be Alive, 
     *         Dead, New-born, or nothing(NULL)
     * Preconditions:
     *    Good row/col value
     * Postconditions:
     *    None
     ****************************************************************/
     virtual char CheckTile(char **board, int row, int col, char player) const;
};

#endif //LIFE_H
