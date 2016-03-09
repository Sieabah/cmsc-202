/*****************************************
** File:    Reversi.h
** Project: CMSC 202 Project 1, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/4/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
**		This file holds all the definitions for the game reversi.
**
***********************************************/
#ifndef REVERSI_H
#define REVERSI_H

//Constant variable to define overall rules of board creation
const int MAX_GAME_SIZE = 10;	//Maximum board size
const int MIN_GAME_SIZE = 4;	//Minimum board size
const int MAX_PLAYERS = 2;		//Amount of players

const bool SHOW_STEPS = false;	//Print or not to print the steps taken

//-------------------------------------------------------
// Name: 
// Function: 
// PreCondition:  
// PostCondition: 
// Returns:
//---------------------------------------------------------

//-------------------------------------------------------
// Name: Board
// Function: Holds the board and board dimensional limit
// PreCondition: N/a
// PostCondition: N/a
// Returns: N/a
//---------------------------------------------------------
struct Board{
	//One default + Two players = (3) 
	char playerChars[MAX_PLAYERS+1];			//Player symbols
	int playerTurn;								//Player turn number
	int hardLimit;								//Board size limit
	int numberOfPlayers;						//Amount of players

	//0 = No Player
	//1 = Player 1
	//2 = Player 2
	int table[MAX_GAME_SIZE][MAX_GAME_SIZE];	//Table array
};

//-------------------------------------------------------
// Name: CreateBoard
// Function: Initialies the baord with good values
// PreCondition: Given good boardSize and valid gameboard
// PostCondition: A gameboard setup with good values and created table
// Returns: Whether board was created successfully
//---------------------------------------------------------
bool CreateBoard(Board &gameBoard, const int boardSize);

//-------------------------------------------------------
// Name: PlayReversi
// Function: Starts and plays the game
// PreCondition:  A valid boardsize was determined in main
// PostCondition: The game is over
// Returns: Nothing
//---------------------------------------------------------
void PlayReversi(const int boardSize);

//-------------------------------------------------------
// Name: GameLoop
// Function: Holds the looping logic for Reversi
// PreCondition:  A valid gameboard was PostCondition
// PostCondition: The game is over
// Returns: Boolean if loop ended when game was over
//---------------------------------------------------------
bool GameLoop(Board &gameBoard);

//-------------------------------------------------------
// Name: GetAndSetMove
// Function: Get valid move and apply it to the board
// PreCondition:  Given an already valid board
// PostCondition: A new move will be placed on the board which is valid
// Returns: boolean if was successful
//---------------------------------------------------------
bool GetAndSetMove(Board &gameBoard);

//-------------------------------------------------------
// Name: ValidMove
// Function: Determines if the move is within valid ranges
// PreCondition: Given positive numbers
// PostCondition: The given x and y are valid
// Returns: boolean 
//---------------------------------------------------------
bool ValidMove(const int BOARD_SIZE, const int x, const int y);

//-------------------------------------------------------
// Name: GetNextMove
// Function: Asks the user for the next move
// PreCondition: Given valid symbol, the integers can be changed
// PostCondition: The row and col variables will be a good value
// Returns: Nothing
//---------------------------------------------------------
void GetNextMove(char playerSymbol, int &row, int &col);

//-------------------------------------------------------
// Name: IncrementPlayer
// Function: Goes to the next player in the game, loops to first player when
//				limit is reached.
// PreCondition: Given a valid setup board
// PostCondition: The next valid player
// Returns: Nothing 
//---------------------------------------------------------
void IncrementPlayer(Board &gameBoard);

//-------------------------------------------------------
// Name: CheckAndCarryOutReversi
// Function: Checks whether the rules of reversi flip pieces
// PreCondition: Valid game so far
// PostCondition: Reversed pieces will be reversed
// Returns: Nothing
//---------------------------------------------------------
void CheckAndCarryOutReversi(Board &gameBoard, int move[]);

//-------------------------------------------------------
// Name: CheckUp
// Function: Checks the cardinal direction UP
// PreCondition: Given valid move on the board
// PostCondition: Reverses all pieces if condition is valid
// Returns: Nothing
//---------------------------------------------------------
void CheckUp(Board &gameBoard, const int move[]);

//-------------------------------------------------------
// Name: CheckDown
// Function: Checks the cardinal direction DOWN
// PreCondition: Given valid move on the board
// PostCondition: Reverses all pieces if condition is valid
// Returns: Nothing
//---------------------------------------------------------
void CheckDown(Board &gameBoard, const int move[]);

//-------------------------------------------------------
// Name: CheckRight
// Function: Checks the cardinal direction RIGHT
// PreCondition: Given valid move on the board
// PostCondition: Reverses all pieces if condition is valid
// Returns: Nothing
//---------------------------------------------------------
void CheckRight(Board &gameBoard, const int move[]);

//-------------------------------------------------------
// Name: CheckLeft
// Function: Checks the cardinal direction LEFT
// PreCondition: Given valid move on the board
// PostCondition: Reverses all pieces if condition is valid
// Returns: Nothing
//---------------------------------------------------------
void CheckLeft(Board &gameBoard, const int move[]);

//-------------------------------------------------------
// Name: CheckUpLeft
// Function: Checks the cardinal direction UP LEFT
// PreCondition: Given valid move on the board
// PostCondition: Reverses all pieces if condition is valid
// Returns: Nothing
//---------------------------------------------------------
void CheckUpLeft(Board &gameBoard, const int move[]);

//-------------------------------------------------------
// Name: CheckUpRight
// Function: Checks the cardinal direction UP RIGHT
// PreCondition: Given valid move on the board
// PostCondition: Reverses all pieces if condition is valid
// Returns: Nothing
//---------------------------------------------------------
void CheckUpRight(Board &gameBoard, const int move[]);

//-------------------------------------------------------
// Name: CheckDownLeft
// Function: Checks the cardinal direction DOWN LEFT
// PreCondition: Given valid move on the board
// PostCondition: Reverses all pieces if condition is valid
// Returns: Nothing
//---------------------------------------------------------
void CheckDownLeft(Board &gameBoard, const int move[]);

//-------------------------------------------------------
// Name: CheckDownRight
// Function: Checks the cardinal direction DOWN RIGHT
// PreCondition: Given valid move on the board
// PostCondition: Reverses all pieces if condition is valid
// Returns: Nothing
//---------------------------------------------------------
void CheckDownRight(Board &gameBoard, const int move[]);

//-------------------------------------------------------
// Name: CheckWin
// Function: Checks to see if any moves are left to play
// PreCondition: A valid board was generated
// PostCondition: Unaltered board
// Returns: boolean on whether the board is completed
//---------------------------------------------------------
bool CheckWin(const Board &gameBoard);

//-------------------------------------------------------
// Name: CalculateScore
// Function: Calculates the score of each player from the board
// PreCondition: Given completed board with no 
// PostCondition: 
// Returns: 
//---------------------------------------------------------
void CalculateScore(const Board &gameBoard);

#endif
