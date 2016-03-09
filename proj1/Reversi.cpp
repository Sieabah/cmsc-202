/*****************************************
** File:    Reversi.cpp
** Project: CMSC 202 Project 1, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    3/6/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
**		This file holds all the logic for the Reversi game, from interaction
**	gameplay, printing, etc.
**
***********************************************/
#include "Reversi.h"
#include <iostream>
#include <stdlib.h>

//PlayReversi
//Play Reversi driver function
void PlayReversi(const int boardSize)
{
	//Make reference to pass around
	Board gameBoard;

	//Create the gameboard
	if(!CreateBoard(gameBoard, boardSize))
	{
		return;
	}

	//Start the game loop
	if(!GameLoop(gameBoard))
	{
		std::cout << "Game Loop exited with error." << std::endl;
		return;
	}

	CalculateScore(gameBoard);
}

//CreateBoard
//Creates and initializes board
bool CreateBoard(Board &gameBoard, const int BOARD_SIZE)
{
	//Check good board dimensions
	if(BOARD_SIZE > MAX_GAME_SIZE || BOARD_SIZE < MIN_GAME_SIZE || BOARD_SIZE % 2 == 1)
	{
		std::cout << "The board must be an even size between " << MIN_GAME_SIZE 
			<<" and " << MAX_GAME_SIZE << "." << std::endl;
		return false;
	}

	gameBoard.numberOfPlayers = MAX_PLAYERS;

	gameBoard.playerChars[0] = '-'; //Default Board Character
	gameBoard.playerChars[1] = 'X'; //Player one
	gameBoard.playerChars[2] = 'O'; //Player two

	//Instigate board dimensions
	gameBoard.hardLimit = BOARD_SIZE;
	//Set player turn to 1
	gameBoard.playerTurn = 1;

	//Initialize board to zeros
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			gameBoard.table[i][j] = 0;
		}
	}

	return true;
}

//ValidMove
//Validates input as valid move
bool ValidMove(const Board &gameBoard, const int X, const int Y)
{
	int offset = 1;

	//Determine if the value is between 1 and maximum board size
	//	offset of 1 is required for UX reasons. (values between 1 and 
	//	max, inclusive)
	if(X < offset || Y < offset 
		|| X > gameBoard.hardLimit 
		|| Y > gameBoard.hardLimit)
	{
		std::cout << "\""<< X << " " << Y << "\"" 
			<< " is not on the board!" << std::endl << std::endl;
		return false;
	}

	//Determine if the spot has already been played
	if(gameBoard.table[X-1][Y-1] != 0)
	{
		std::cout << "\""<< X << " " << Y << "\"" 
			<< " has already been played!" << std::endl << std::endl;
		return false;
	}

	return true;
}

//GetNextMove
//Gets next move
void GetNextMove(char playerSymbol, int &row, int &col)
{
	std::cout << "Player " << playerSymbol << "'s turn: ";
	//DEBUG STUFF
	if(SHOW_STEPS)
	{
		std::cout << std::endl;
	}
	std::cin >> row >> col;
}

//GetAndSetMove
//Gets move from current player and applies it to the board
bool GetAndSetMove(Board &gameBoard)
{
	//Predefine invalid move and initialize
	int move[] = {0,0};
	do
	{
		//Catch end of file error and exit the program
		if(std::cin.eof())
		{
			std::cout << "END OF FILE" << std::endl;
			std::cout << "EXITING PROGRAM" << std::endl;
			exit(EXIT_SUCCESS);
		}

		GetNextMove(gameBoard.playerChars[gameBoard.playerTurn],
			move[0],move[1]);

		//Can't prevent bad data such as string without use of continue
		//	when string/char detected
	} while(!ValidMove(gameBoard, move[0], move[1]));

	//Debug see what value positions in the array the move will be placed
	//std::cout << gameBoard.playerTurn << " placed at: " << move[0]-1 << "," 
	//	<< move[1]-1 << std::endl;

	//If all passes, make the move happen, -1 for array offset
	gameBoard.table[move[0]-1][move[1]-1] = gameBoard.playerTurn;

	//Check reversi status
	CheckAndCarryOutReversi(gameBoard, move);

	return true;
}

//IncrementPlayer
//Changes player
void IncrementPlayer(Board &gameBoard)
{
	//If next player if above the limit
	if(++gameBoard.playerTurn > gameBoard.numberOfPlayers)
	{
		//Reset to player one
		gameBoard.playerTurn = 1;
	}
	//Otherwise keep incremented player number from if statement
}

//CheckUp
//Carry out reversi conditions for UP
void CheckUp(Board &gameBoard, const int move[])
{
	//Offset row & col for array accessing
	int row = move[0]-1;
	int col = move[1]-1;
	int iterator = -1;
	bool quit = false;

	//If out of bounds, quit early
	if(row < 0)
	{
		return;
	}

	//Loop through all in that direction
	for (int i = row-1; i >= 0 
		&& i < row 
		&& !quit; i += iterator)
	{
		if(iterator < 0)
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CHECKING UP." << std::endl;
				std::cout <<"\tboardValue("<<i+1<<","<<col+1<<"): " << gameBoard.table[i][col] << std::endl;
			}
			if(gameBoard.table[i][col] == gameBoard.playerTurn)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tsame player" << std::endl;
				}
				iterator = 1;
			}
			else if(gameBoard.table[i][col] == 0)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tzero" << std::endl;
				}
				quit = true;
			}
			else
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tother player" << std::endl;
				}

			}
		}
		else
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CONVERTING (UP).\n" << std::endl;
			}
			//If we found the player we're going to reverse the direction
			//	and reverse all pieces up until the limit
			gameBoard.table[i][col] = gameBoard.playerTurn;

			//For each piece flipped we're going to check their information
			int testPos[2] = {i, col+1};
			CheckUp(gameBoard, testPos);
			CheckDown(gameBoard, testPos);

			CheckUpLeft(gameBoard, testPos);
			CheckUpRight(gameBoard, testPos);
			CheckDownLeft(gameBoard, testPos);
			CheckDownRight(gameBoard, testPos);
		}
	}
	//DEBUG STUFF
	if(SHOW_STEPS)
	{
		if(quit)
		{
			std::cout << "\t EXITED" << std::endl;
		}
	}
}

//CheckDown
//Carry out reversi conditions for DOWN
void CheckDown(Board &gameBoard, const int move[])
{
	//Offset row & col for array accessing
	int row = move[0]-1;
	int col = move[1]-1;
	int iterator = 1;
	bool quit = false;

	//If out of bounds, quit early
	if(row >= gameBoard.hardLimit)
	{
		return;
	}

	//Loop through all in that direction
	for (int i = row+1; i > row 
		&& i < gameBoard.hardLimit 
		&& !quit; i += iterator)
	{
		if(iterator > 0)
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CHECKING DOWN." << std::endl;
				std::cout <<"\tboardValue("<<i+1<<","<<col+1<<"): " << gameBoard.table[i][col] << std::endl;
			}
			if(gameBoard.table[i][col] == gameBoard.playerTurn)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tsame player" << std::endl;
				}
				iterator = -1;
			}
			else if(gameBoard.table[i][col] == 0)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tzero" << std::endl;
				}
				//Quit early
				quit = true;
			}
			else
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tother player" << std::endl;
				}

			}
		}
		else
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CONVERTING (DOWN).\n" << std::endl;
			}

			//If we found the player we're going to reverse the direction
			//	and reverse all pieces up until the limit
			gameBoard.table[i][col] = gameBoard.playerTurn;

			//For each piece flipped we're going to check their information
			int testPos[2] = {i, col+1};
			CheckUp(gameBoard, testPos);
			CheckDown(gameBoard, testPos);

			CheckUpLeft(gameBoard, testPos);
			CheckUpRight(gameBoard, testPos);
			CheckDownLeft(gameBoard, testPos);
			CheckDownRight(gameBoard, testPos);
		}
	}
	//DEBUG STUFF
	if(SHOW_STEPS)
	{
		if(quit)
		{
			std::cout << "\t EXITED" << std::endl;
		}
	}
}

//CheckRight
//Carry out reversi conditions for RIGHT
void CheckRight(Board &gameBoard, const int move[])
{
	//Offset row & col for array accessing
	int row = move[0]-1;
	int col = move[1]-1;
	int iterator = 1;
	bool quit = false;

	//If out of bounds, quit early
	if(col >= gameBoard.hardLimit)
	{
		return;
	}

	//Loop through all in that direction
	for (int i = col+1; i > col 
		&& i < gameBoard.hardLimit 
		&& !quit; i += iterator)
	{
		if(iterator > 0)
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CHECKING RIGHT." << std::endl;
				std::cout <<"\tboardValue("<<row+1<<","<<i+1<<"): " << gameBoard.table[row][i] << std::endl;
			}
			if(gameBoard.table[row][i] == gameBoard.playerTurn)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tsame player" << std::endl;
				}
				iterator = -1;
			}
			else if(gameBoard.table[row][i] == 0)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tzero" << std::endl;
				}
				quit = true;
			}
			else
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tother player" << std::endl;
				}
			}
		}
		else
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CONVERTING "<< row+1<<","<<i+1 <<"(RIGHT).\n" << std::endl;
			}

			//If we found the player we're going to reverse the direction
			//	and reverse all pieces up until the limit
			gameBoard.table[row][i] = gameBoard.playerTurn;

			//For each piece flipped we're going to check their information
			int testPos[2] = {row+1, i};
			CheckUp(gameBoard, testPos);
			CheckDown(gameBoard, testPos);

			CheckUpLeft(gameBoard, testPos);
			CheckUpRight(gameBoard, testPos);
			CheckDownLeft(gameBoard, testPos);
			CheckDownRight(gameBoard, testPos);
		}
	}
	//DEBUG STUFF
	if(SHOW_STEPS)
	{
		if(quit)
		{
			std::cout << "\t EXITED" << std::endl;
		}
	}
}

//CheckLeft
//Carry out reversi conditions for LEFT
void CheckLeft(Board &gameBoard, const int move[])
{
	//Offset row & col for array accessing
	int row = move[0]-1;
	int col = move[1]-1;
	int iterator = -1;
	bool quit = false;

	//If out of bounds, quit early
	if(col < 0)
	{
		return;
	}

	//For in the range of valid values
	for (int i = col-1; i >= 0 
		&& i < col 
		&& !quit; i += iterator)
	{
		//See if we're going checking or converting
		if(iterator < 0)
		{
			
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CHECKING LEFT." << std::endl;
				std::cout <<"\tboardValue("<<row+1<<","<<i+1<<"): " << gameBoard.table[row][i] << std::endl;
			}

			//Go until we see the same player
			if(gameBoard.table[row][i] == gameBoard.playerTurn)
			{
				
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tsame player" << std::endl;
				}
				//Flip the iterator
				iterator = 1;
			}

			//If we hit zero, stop immediately
			else if(gameBoard.table[row][i] == 0)
			{
				
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tzero" << std::endl;
				}
				//Quit the for loop, 'break' :(
				quit = true;
			}
			//Otherwise we do nothing but loop again
			else
			{	
				
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tother player" << std::endl;
				}
			}
		}
		else
		{
			
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CONVERTING (LEFT).\n" << std::endl;
			}

			//If we found the player we're going to reverse the direction
			//	and reverse all pieces up until the limit
			gameBoard.table[row][i] = gameBoard.playerTurn;

			//For each piece flipped we're going to check their information
			int testPos[2] = {row+1, i};
			CheckUp(gameBoard, testPos);
			CheckDown(gameBoard, testPos);

			CheckUpLeft(gameBoard, testPos);
			CheckUpRight(gameBoard, testPos);
			CheckDownLeft(gameBoard, testPos);
			CheckDownRight(gameBoard, testPos);
		}
	}
	//DEBUG STUFF
	if(SHOW_STEPS)
	{
		if(quit)
		{
			std::cout << "\t EXITED" << std::endl;
		}
	}
}

//CheckUpRight
//Carry out reversi conditions for UP-RIGHT
void CheckUpRight(Board &gameBoard, const int move[])
{
	//Offset row & col for array accessing
	int row = move[0]-1;
	int col = move[1]-1;
	int iterator = -1;
	bool quit = false;

	//If out of bounds, quit early
	if(row <= 0 || col >= gameBoard.hardLimit)
	{
		return;
	}

	//Loop through all in that direction
	//	I know this is bad... These conditions would normally be done with
	//		break or continue, but yay for super for loops
	for (int i = row-1, j = col+1; i >= 0 
		&& i < row 
		&& j > col
		&& j <= gameBoard.hardLimit
		&& !quit; i += iterator, j -= iterator)
	{
		if(iterator < 0)
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CHECKING UP-RIGHT." << std::endl;
				std::cout <<"\tboardValue("<<i+1<<","<<j+1<<"): " << gameBoard.table[i][j] << std::endl;
				std::cout <<"\tnextBoardValue("<<i+iterator<<","<<j+iterator<<"): " << std::endl;
			}
			if(gameBoard.table[i][j] == gameBoard.playerTurn)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tsame player" << std::endl;
				}
				iterator = 1;
			}
			else if(gameBoard.table[i][j] == 0)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tzero" << std::endl;
				}
				quit = true;
			}
			else
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tother player" << std::endl;
				}

			}
		}
		else
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CONVERTING (UP-RIGHT).\n" << std::endl;
			}
			//If we found the player we're going to reverse the direction
			//	and reverse all pieces up until the limit
			gameBoard.table[i][j] = gameBoard.playerTurn;

			//For each piece flipped we're going to check their information
			int testPos[2] = {i, j};
			CheckUp(gameBoard, testPos);
			CheckDown(gameBoard, testPos);
			CheckLeft(gameBoard, testPos);
			CheckRight(gameBoard, testPos);

			CheckUpLeft(gameBoard, testPos);
			CheckDownRight(gameBoard, testPos);
		}
	}
	//DEBUG STUFF
	if(SHOW_STEPS)
	{
		if(quit)
		{
			std::cout << "\t EXITED" << std::endl;
		}
	}
}

//CheckUpLeft
//Carry out reversi conditions for UP-LEFT
void CheckUpLeft(Board &gameBoard, const int move[])
{
	//Offset row & col for array accessing
	int row = move[0]-1;
	int col = move[1]-1;
	int iterator = -1;
	bool quit = false;

	//If out of bounds, quit early
	if(row <= 0 || col <= 0)
	{
		return;
	}

	//Loop through all in that direction
	//	I know this is bad... These conditions would normally be done with
	//		break or continue, but yay for super for loops
	for (int i = row-1, j = col-1; i >= 0 
		&& i < row 
		&& j < col
		&& j >= 0
		&& !quit; i += iterator, j += iterator)
	{
		if(iterator < 0)
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CHECKING UP-LEFT." << std::endl;
				std::cout <<"\tboardValue("<<i+1<<","<<j+1<<"): " << gameBoard.table[i][j] << std::endl;
				std::cout <<"\tnextBoardValue("<<i+iterator<<","<<j+iterator<<"): " << std::endl;
			}
			if(gameBoard.table[i][j] == gameBoard.playerTurn)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tsame player" << std::endl;
				}
				iterator = 1;
			}
			else if(gameBoard.table[i][j] == 0)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tzero" << std::endl;
				}
				quit = true;
			}
			else
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tother player" << std::endl;
				}

			}
		}
		else
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CONVERTING (UP-LEFT).\n" << std::endl;
			}
			//If we found the player we're going to reverse the direction
			//	and reverse all pieces up until the limit
			gameBoard.table[i][j] = gameBoard.playerTurn;

			//For each piece flipped we're going to check their information
			int testPos[2] = {i, j};
			CheckUp(gameBoard, testPos);
			CheckDown(gameBoard, testPos);
			CheckLeft(gameBoard, testPos);
			CheckRight(gameBoard, testPos);

			CheckUpRight(gameBoard, testPos);
			CheckDownLeft(gameBoard, testPos);
		}
	}
	//DEBUG STUFF
	if(SHOW_STEPS)
	{
		if(quit)
		{
			std::cout << "\t EXITED" << std::endl;
		}
	}
}

//CheckDownLeft
//Carry out reversi conditions for DOWN-LEFT
void CheckDownLeft(Board &gameBoard, const int move[])
{
	//Offset row & col for array accessing
	int row = move[0]-1;
	int col = move[1]-1;
	int iterator = -1;
	bool quit = false;

	//If out of bounds, quit early
	if(row < 0 || col < 0)
	{
		return;
	}
	//Loop through all in that direction
	//	I know this is bad... These conditions would normally be done with
	//		break or continue, but yay for super for loops
	for (int i = row+1, j = col-1; i >= 0 
		&& i > row 
		&& j < col
		&& j >= 0
		&& !quit; i -= iterator, j += iterator)
	{
		if(iterator < 0)
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CHECKING DOWN-LEFT." << std::endl;
				std::cout <<"\tboardValue("<<i+1<<","<<j+1<<"): " << gameBoard.table[i][j] << std::endl;
				std::cout <<"\tnextBoardValue("<<i+iterator<<","<<j+iterator<<"): " << std::endl;
			}
			if(gameBoard.table[i][j] == gameBoard.playerTurn)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tsame player" << std::endl;
				}
				iterator = 1;
			}
			else if(gameBoard.table[i][j] == 0)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tzero" << std::endl;
				}
				quit = true;
			}
			else
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tother player" << std::endl;
				}

			}
		}
		else
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CONVERTING (UP-LEFT).\n" << std::endl;
			}
			//If we found the player we're going to reverse the direction
			//	and reverse all pieces up until the limit
			gameBoard.table[i][j] = gameBoard.playerTurn;

			//For each piece flipped we're going to check their information
			int testPos[2] = {i, j};
			CheckUp(gameBoard, testPos);
			CheckDown(gameBoard, testPos);
			CheckLeft(gameBoard, testPos);
			CheckRight(gameBoard, testPos);

			CheckUpRight(gameBoard, testPos);
			CheckDownLeft(gameBoard, testPos);
		}
	}
	//DEBUG STUFF
	if(SHOW_STEPS)
	{
		if(quit)
		{
			std::cout << "\t EXITED" << std::endl;
		}
	}
}

//WORK HERE
//CheckDownRight
//Carry out reversi conditions for DOWN-RIGHT
void CheckDownRight(Board &gameBoard, const int move[])
{
	//Offset row & col for array accessing
	int row = move[0]-1;
	int col = move[1]-1;
	int iterator = -1;
	bool quit = false;

	//If out of bounds, quit early
	if(row+1 >= gameBoard.hardLimit || col+1 >= gameBoard.hardLimit)
	{
		return;
	}

	//Loop through all in that direction
	//	I know this is bad... These conditions would normally be done with
	//		break or continue, but yay for super for loops
	for (int i = row+1, j = col+1; i <= gameBoard.hardLimit
		&& i > row 
		&& j > col
		&& j <= gameBoard.hardLimit
		&& !quit; i -= iterator, j -= iterator)
	{
		if(iterator < 0)
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CHECKING DOWN-RIGHT." << std::endl;
				std::cout <<"\tboardValue("<<i+1<<","<<j+1<<"): " << gameBoard.table[i][j] << std::endl;
				std::cout <<"\tnextBoardValue("<<i+iterator<<","<<j+iterator<<"): " << std::endl;
			}
			if(gameBoard.table[i][j] == gameBoard.playerTurn)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tsame player" << std::endl;
				}
				iterator = 1;
			}
			else if(gameBoard.table[i][j] == 0)
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tzero" << std::endl;
				}
				quit = true;
			}
			else
			{
				//DEBUG STUFF
				if(SHOW_STEPS)
				{
					std::cout << "\tother player" << std::endl;
				}

			}
		}
		else
		{
			//DEBUG STUFF
			if(SHOW_STEPS)
			{
				std::cout << "CONVERTING (UP-RIGHT).\n" << std::endl;
			}
			//If we found the player we're going to reverse the direction
			//	and reverse all pieces up until the limit
			gameBoard.table[i][j] = gameBoard.playerTurn;

			//For each piece flipped we're going to check their information
			int testPos[2] = {i, j};
			CheckUp(gameBoard, testPos);
			CheckDown(gameBoard, testPos);
			CheckLeft(gameBoard, testPos);
			CheckRight(gameBoard, testPos);

			CheckUpLeft(gameBoard, testPos);
			CheckDownRight(gameBoard, testPos);
		}
	}
	//DEBUG STUFF
	if(SHOW_STEPS)
	{
		if(quit)
		{
			std::cout << "\t EXITED" << std::endl;
		}
	}
}

//CheckAndCarryOutReversi
//Carry out reversi conditions
void CheckAndCarryOutReversi(Board &gameBoard, int move[])
{
	const int boardLimit = gameBoard.hardLimit;

	//DEBUG STUFF
	if(SHOW_STEPS)
	{
		std::cout << move[0] << "," << move[1] << std::endl;
	}
	CheckUp(gameBoard, move);
	CheckLeft(gameBoard, move);
	CheckRight(gameBoard, move);
	CheckDown(gameBoard, move);

	CheckUpLeft(gameBoard, move);
	CheckUpRight(gameBoard, move);
	CheckDownLeft(gameBoard, move);
	CheckDownRight(gameBoard, move);

	/*
	//Check on entire row and column for reverses
	for (int col = 0; col < boardLimit; col++)
	{
		int testPos[2] = {move[0], col};
		CheckLeft(gameBoard, testPos);
		CheckRight(gameBoard, testPos);
	}
	for (int row = 0; row < boardLimit; row++)
	{
		int testPos[2] = {row, move[1]};
		CheckUp(gameBoard, testPos);
		CheckDown(gameBoard, testPos);
	}
	*/

	/*
	
	for (int i = 0; i < gameBoard.hardLimit; i++)
	{
		int prevNum = 0;
		//Check for all possibilities.
		for (int row = 0, row2 = 0; row+2 < gameBoard.hardLimit; row++)
		{
			//Check each row with offset of 2 to make sure we're always 
			//	within bounds
			if(gameBoard.table[i][row] == gameBoard.table[i][row+2] 
				&& gameBoard.table[i][row+1] != 0
				&& gameBoard.table[i][row] != 0)
			{
				gameBoard.table[i][row+1] = gameBoard.table[i][row];
			}
		}
		for (int col = 0,offset = 2; col+2 < gameBoard.hardLimit; col++ offset++)
		{
			//Check each column with offset of 2 to make sure we're always within bounds
			if(gameBoard.table[col][i] == gameBoard.table[col+offset][i] 
				&& gameBoard.table[col+offset][i] != 0
				&& gameBoard.table[col][i] != 0)
			{
				gameBoard.table[col+1][i] = gameBoard.table[col][i];
			}
		}
	}
	*/
}

//CheckWin
//Check winning conditions
bool CheckWin(Board &gameBoard)
{
	//Initialize board to zeros
	for (int i = 0; i < gameBoard.hardLimit; i++)
	{
		for (int j = 0; j < gameBoard.hardLimit; j++)
		{
			if(gameBoard.table[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

//CalculateScore
//Calculate score
void CalculateScore(const Board &gameBoard)
{
	int score[gameBoard.numberOfPlayers];
	char winner[gameBoard.numberOfPlayers];
	int highScore = 0;
	int ties = 0;
	bool tie = false;

	//Alert the players the game is over
	std::cout << "The game is over\n";

	//Initialize scores to zero
	for (int i = 0; i < gameBoard.numberOfPlayers; i++)
	{
		//Initialize all values to 0
		score[i] = 0;
	}

	//Get all the scores from the current board
	for (int i = 0; i < gameBoard.hardLimit; i++)
	{
		for (int j = 0; j < gameBoard.hardLimit; j++)
		{
			//Increment player value from board
			//	-1 is to remove the offset
			score[gameBoard.table[i][j]-1] += 1;
		}
	}

	//For all players check their scores
	for (int i = 0; i < gameBoard.numberOfPlayers; i++)
	{
		//Print the name and score for specific player
		std::cout << "Player " << gameBoard.playerChars[i+1] 
			<< " controls " << score[i] << " squares.\n";

		//Check to see if there was a tie
		if(score[i] == highScore)
		{
			//Increase amount of players who have tied
			ties++;
			//Boolean to say there is a tie
			tie = true;

			//Make it so the array holds the new players' name
			winner[ties] = gameBoard.playerChars[i+1];
		} 
		//If the score is greater than previous score
		else if(score[i] > highScore) 
		{
			//Remove any ties because any previous ties were beaten
			tie = false;
			ties = 0;

			//Update high score
			highScore = score[i];
			//Set winner
			winner[0] = gameBoard.playerChars[i+1];
		}
		//else, ignore the players' score
	}

	if(tie)
	{
		//Print all winners
		std::cout << "There was a tie between players ";
		for (int i = 0; i <= ties; ++i)
		{
			std::cout << winner[i] << ", ";
		}
		std::cout << "!" << std::endl;
	}
	else
	{
		//Print single winner
		std::cout << "Player " << winner[0] << " wins!" << std::endl;
	}


}

//PrintGameBoard
//Prints whole gameboard
void PrintGameBoard(const Board &gameBoard)
{
	//Loop rows
	for (int i = 0; i < gameBoard.hardLimit; i++)
	{
		//Loop columns
		for (int j = 0; j < gameBoard.hardLimit; j++)
		{
			//Print the character symbol from table ID
			std::cout << gameBoard.playerChars[gameBoard.table[i][j]];
		}
		//Next row, so break line
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

//GameLoop
//Main Reversi Game Loop
bool GameLoop(Board &gameBoard)
{
	bool quitGame = false;
	while(!quitGame)
	{
		if(!GetAndSetMove(gameBoard))
		{
			std::cout << "Something went wrong when getting the player move."
				<< std::endl;
			return false;
		}

		//Go to next player in game
		IncrementPlayer(gameBoard);

		//Print the gameboard after every move and reversi check
		PrintGameBoard(gameBoard);

		//Check win conditions
		if(CheckWin(gameBoard))
		{
			quitGame = true;
		}		
	}
	return true;
}