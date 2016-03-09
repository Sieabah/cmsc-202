/*****************************************
** File: GridGame.h
** Project: CMSC 202 Project 4, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    4/19/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *   Holds the definition of the GridGame class, including interactions with the
 *      basic board
**
***********************************************/
#ifndef GRIDGAME_H
#define GRIDGAME_H

#include "GameType.h"

class GridGame {
public:
    /****************************************************************
     * Name: GridGame
     *    Default (no-arg) constructor
     * Preconditions:
     *   None
     * Postconditions:
     *   Good board
     ****************************************************************/
    GridGame();

    /****************************************************************
     * Name: GridGame
     *    Custom constructor
     * Preconditions:
     *   size is positive
     * Postconditions:
     *   good board given
     ****************************************************************/
    GridGame(enum GameType type, const char *name, int size);

    /****************************************************************
     * Name: OutputGreeting
     *    Greet the user to the game
     * Preconditions:
     *   None
     * Postconditions:
     *   None
     ****************************************************************/
    void OutputGreeting() const;

    /****************************************************************
     * Name: GetType
     *    Returns the type of game we're in
     * Preconditions:
     *   None
     * Postconditions:
     *   None
     ****************************************************************/
    enum GameType GetType() { return m_type; }

    /****************************************************************
     * Name: GetPlayerSymbol
     *    Returns the player symbols
     * Preconditions:
     *   player is valid
     * Postconditions:
     *   None
     ****************************************************************/
    char GetPlayerSymbol(int player) const;

    /****************************************************************
     * Name: IsLegalMove
     *    Returns whether move is legal
     * Preconditions:
     *   
     * Postconditions:
     *   
     ****************************************************************/
    const char *IsLegalMove(int player, int row, int col) const;

    /****************************************************************
     * Name: OutputBoard
     *    Draw the board to the console
     * Preconditions:
     *   Initialized board
     * Postconditions:
     *   None
     ****************************************************************/
    void OutputBoard() const;

    /****************************************************************
     * Name: GetBoardSize
     *    Returns size of the current board
     * Preconditions:
     *   None
     * Postconditions:
     *   None
     ****************************************************************/
    int GetBoardSize() const;

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
     * Name: InitBoard
     *    Initializes board with dashes
     * Preconditions:
     *   None
     * Postconditions:
     *   None
     ****************************************************************/
    void InitBoard();

protected:
    /****************************************************************
     * Name: DoBasicMove
     *    Puts new piece for player at {row, col} position
     * Preconditions:
     *   Assumes position has already been pre-checked by IsLegalMove() for
     *      valid bounds and emptiness.
     * Postconditions:
     *   
     ****************************************************************/
    void DoBasicMove(int player, int row, int col);

    /****************************************************************
     * Name: InBounds
     *    Tell if play is within the bounds of the board
     * Preconditions:
     *   none
     * Postconditions:
     *   none
     ****************************************************************/
    static bool InBounds(int row, int col, int boardSize);

    //Holds player symbols
	const char *m_playerSymbols;
    //Board size
	int m_boardSize;
    //Game type
    enum GameType m_type;
    //Game name
    const char *m_gameName;
    //Board
    char **m_board;
};

#endif //GRIDGAME_H
