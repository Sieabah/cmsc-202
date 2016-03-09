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

#ifndef GRIDGAME_H
#define GRIDGAME_H

class GridGame {
public:
    /****************************************************************
     * Name: GridGame
     *    Default (no-arg) constructor
    * Preconditions:
    *      None
    * Postconditions:
    *      None
    ****************************************************************/
    GridGame();

    /****************************************************************
     * Name: ~GridGame
     *    Virtual destructor to remove any dynamically allocated memory.
     * Preconditions:
     *    None
     * Postconditions:
     *    Deletes all dynamic memory
     ****************************************************************/
    virtual ~GridGame();

    /****************************************************************
     * Name: OutputGreeting
     *    Greets the user with custom greeting
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
    virtual void OutputGreeting() const;

    /****************************************************************
     * Name: NumPlayers
     *    Returns number of players
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
    virtual int NumPlayers() const;

    /****************************************************************
     * Name: GetPlayerSymbol
     *    Returns player symbol
     * Preconditions:
     *    player - Is a valid player number
     * Postconditions:
     *    None
     ****************************************************************/
    virtual char GetPlayerSymbol(int player) const;

    /****************************************************************
     * Name: GetBoardSize
     *    Returns board size
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
    virtual int GetBoardSize() const;

    /****************************************************************
    * Name: IsLegalMove
    *    Checks if move is legal
    * Preconditions:
    *    None
    * Postconditions:
    *    Returns NULL on good move, else returns err string.
    ****************************************************************/
    virtual const char *IsLegalMove(int player, int row, int col) const;

    /****************************************************************
     * Name: OutputBoard
     *    Prints the board to the user
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
    virtual void OutputBoard()const;

    /****************************************************************
     * Name: IsDone (ABSTRACT)
     *    Checks if the game is done, must be override for the game
     * Preconditions:
     *    None
     * Postconditions:
     *    Game is done or not
     ****************************************************************/
    virtual bool IsDone() const = 0;

    /****************************************************************
     * Name: DoMove (ABSTRACT)
     *    Complete the player move, must be override for the game
     * Preconditions:
     *    Move is a valid move already checked
     * Postconditions:
     *    Move is carried out
     ****************************************************************/
    virtual void DoMove(int player, int row, int col) = 0;

    /****************************************************************
     * Name: OutputResults (ABSTRACT)
     *    Prints the results of the game to the user(s)
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
    virtual void OutputResults() const = 0;

protected:
    /****************************************************************
     * Name: GridGame
     *    Constructor that accepts custom symbols
     * Preconditions:
     *    None
     * Postconditions:
     *    None
     ****************************************************************/
    GridGame( const char *name, const char *playerSymbols, int boardSize);

    /****************************************************************
     * Name: DoBasicMove
     *  Puts new piece for player at {row, col} position
     * Preconditions:
     *    Assumes position has already been pre-checked by IsLegalMove() for
     *   valid bounds and emptiness.
     * Postconditions:
     *    None
     ****************************************************************/
    virtual void DoBasicMove(int player, int row, int col);

    // The only data member that the subclassed games should really
    // need full read/write access to, once game is set up.
    char **m_board;

private:
    const char *m_gameName; //Holds game name
    int m_boardSize; //Holds board size
    const char *m_playerSymbols; //Holds player symbols
};

#endif //GRIDGAME_H