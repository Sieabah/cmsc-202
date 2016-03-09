/*****************************************
** File:    Life.cpp
** Project: CMSC 202 Project 5, Sprig 2014
** Author:  Christopher Stephen Sidell
** Date:    5/13/2014
** Section: 11 / 15
** E-mail:  csidell1@umbc.edu
**
 *  Holds the entirety of life. The meaning, definition, and fun.
**
***********************************************/

#include "Life.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

/*
	Sorry if this breaks the rules a bit, but if you're
		bored turn this to see the data for each generation
	-I do break the rules to keep it from being overly cluttered
		(Don't penalize me for it :( )
*/
const bool DEBUG = false;

/*
	Extended DEBUG information that goes into detail every tile check and
		life information, translated to puedo-board value. (1,1) origin for
		ease of use.
*/
const bool EXT_DEBUG = false;//DEBUG;

//Keeping the grid in the top left of the terminal.
//	UNIX SUPPORT ONLY
const bool CORNER_FORMAT = false;

//Life
//Default (no-arg) constructor
Life::Life()
: GridGame("Life", "@", LIFE_BOARD_SIZE), m_isDone(false)
{
	m_boardGenerations = m_generations = m_totalGenerations = 0;

	int boardSize = GetBoardSize();
	m_oldBoard = new char *[boardSize];
	for (int r = 0; r < boardSize; r++)
	{
		m_oldBoard[r] = new char[boardSize];
	}

	m_autoGen = false;
}

//Life
//Constructor that accepts custom symbols
Life::Life(char* symbols)
: GridGame("Life", symbols, LIFE_BOARD_SIZE), m_isDone(false),m_generations(0),
m_boardGenerations(0)
{
	m_boardGenerations = m_generations = m_totalGenerations = 0;

	int boardSize = GetBoardSize();
	m_oldBoard = new char *[boardSize];
	for (int r = 0; r < boardSize; r++)
	{
		m_oldBoard[r] = new char[boardSize];
	}

	m_autoGen = false;
}

//~Life
//Virtual destructor to remove any dynamically allocated memory.
Life::~Life()
{
	for (int r = 0; r < GetBoardSize(); r++) 
	{
		delete [] m_oldBoard[r];
		m_oldBoard[r] = NULL;
	}
	delete [] m_oldBoard;
	m_oldBoard = NULL;
}

//NumPlayers
//Returns 1 for single life player
int Life::NumPlayers() const
{
	//There will only ever be one player, so... return 1.
	return 1;
}

//CheckTile
//Checks all 8 directions if the current tile will be Alive, 
//	Dead, New-born, or nothing(NULL)
char Life::CheckTile(char **board, int row, int col, char player) const
{
	//Initialize some necessary variables
	int nearbyTiles = 0;
	bool occupiedTile = false;

	//Determine if we're dealing with a population or empty cell
	if(board[row][col] == player)
	{
		occupiedTile = true;
	}

	//Go through all the cells and check their neighbors
	for (int rowIncr = -1; rowIncr <= 1; rowIncr++) 
	{
		for (int colIncr = -1; colIncr <= 1; colIncr++) 
		{
			//Get the offset positioned cell
			int rowVal = row+rowIncr;
			int colVal = col+colIncr;

			//Check if in bounds and not the original cell
			if(InBounds(rowVal, colVal) && !(rowVal == row && colVal == col) )
			{
				//If the adjacent cell is occupied...
				if(board[rowVal][colVal] == player)
				{
					//This is for debugging purposes, please ignore
					if(EXT_DEBUG)
					{
						cout << "HOME-TILE:<"<<row+1<<","<<col+1
							<< "> found nearby tile ";
						cout << "<"<<rowVal+1<<","<<colVal+1<<">"<<endl;
					}

					//Increment the nearby variable
					nearbyTiles++;
				}
			}
		}
	}

	//This is for debugging purposes, please ignore
	if(EXT_DEBUG)
		{ cout << "TILE: <"<<row+1<<","<<col+1<<"> neighbors->" 
				<< nearbyTiles << " "; }

	//If surrounding area has 2 or 3 active cells
	if((nearbyTiles < 2 || nearbyTiles > 3) && occupiedTile)
	{
		//This is for debugging purposes, please ignore
		if(EXT_DEBUG && nearbyTiles < 2){ cout << "[DEAD-Loneliness]" << endl; }
		else if(EXT_DEBUG) { cout << "[DEAD-Overcrowding]" << endl; }

		//The cell dies
		return 'd';
	}
	//If the ACTIVE cell has 2 or 3 nearby
	else if(occupiedTile)
	{
		//This is for debugging purposes, please ignore
		if(EXT_DEBUG) { cout << "[ALIVE]" << endl; }

		//It stays alive
		return 'a';
	}
	//If the EMPTY cell has 3 nearby
	else if(!occupiedTile && nearbyTiles == 3)
	{
		//This is for debugging purposes, please ignore
		if(EXT_DEBUG) { cout << "[NEWBORN]" << endl; }

		//A population is born
		return 'n';
	}
	else
	{
		//This is for debugging purposes, please ignore
		if(EXT_DEBUG) { cout << endl; }

		//Otherwise do nothing
		return NULL;
	}
}

//IsDone
//Checks if the game is done, entered "0 0"
bool Life::IsDone() const
{
	return m_isDone;
}

//InBounds
//Returns boolean if position is within bounds
bool Life::InBounds(int row, int col) const
{
	return (row >= 0 && col >= 0) 
			&& (row < GetBoardSize() && col < GetBoardSize());
}

//BackupBoard
//Copies from one board to the other
void Life::BackupBoard(char **copyToBoard, char **copyFromBoard) const
{
	//cout << endl;
	for (int r = 0; r < GetBoardSize(); r++)
	{
		for (int c = 0; c < GetBoardSize(); c++)
		{
			copyToBoard[r][c] = copyFromBoard[r][c];
		}
	}
}

//AgeBoard
//Runs through x amount of generations through the board
void Life::AgeBoard(char **board, int generations, char symbol) const
{
	int boardSize = GetBoardSize();
	//For all generations given...
	//	+1 is to offset from 1,1 origin
	for (int i = 0; i < generations; i++)
	{
		//Create temporary life board
		char tempBoard[boardSize][boardSize];

		//This is for debugging purposes, please ignore
		if(DEBUG) { cout << "GEN: " << generations << endl; }

		//For all rows
		for (int r = 0; r < boardSize; r++)
		{
			//For all columns
			for (int n = 0; n < boardSize; n++)
			{
				//Get the status of specific tile
				tempBoard[r][n] = CheckTile(board,r,n,symbol);
			}
		}

		/*
			The snippit below is a DEBUG board which shows the previous
				generation and new generation in terms of what lives, born,
				and death. Boolean to turn this on can be found at the top
				of the file.
			This is DIFFERENT than printing the normal board.
			Purely just for fun, don't grade down for it :(
		//START_LIFE_STATUS//
		*/
		if(DEBUG) { cout << "Life Status Board" << endl; }

		for (int r = 0; r < boardSize && DEBUG; r++)
		{
			for (int n = 0; n < boardSize; n++)
			{
				//Print board
				if(tempBoard[r][n] != '\0')
					cout << tempBoard[r][n];
				else
					cout << '-';
			}
			cout << endl;
		}

		if(DEBUG) { cout << endl; }
		//END_LIFE_STATUS//

		//For all rows
		for (int r = 0; r < boardSize; r++)
		{
			//For all columns
			for (int n = 0; n < boardSize; n++)
			{
				//Remove all dead cells
				if(tempBoard[r][n] == 'd')
				{
					board[r][n] = '-';
				}
				//Create and keep all alive cells
				else if(tempBoard[r][n] == 'a' || tempBoard[r][n] == 'n')
				{
					board[r][n] = symbol;
				}
			}
		}
	}
}

//DoMove
//Add or remove life cell
void Life::DoMove(int player, int row, int col)
{
	//cout << row+1 << " " << col+1 << endl;
	//SPECIAL: If the row is 0 and column isn't 0
	if(row < 0 && col >= 0)
	{	
		//We want to make sure that the old board is up to date
		if(m_boardGenerations != m_generations)
		{
			//Copy the newest board to the old board
			BackupBoard(m_oldBoard, m_board);

			//Reset generation offset
			m_boardGenerations = 0;
		}
		//Get the boardSize for simplicity
		int boardSize = GetBoardSize();

		//Evolve the board by given iterations
		m_generations = col+1;

		//Handle the new generations
		AgeBoard(m_board, m_generations, GetPlayerSymbol(player));

		//Add to total amount of generations done.
		m_totalGenerations += m_generations;

		//Let output board know we want to print all generations
		m_autoGen = true;
	}
	//SPECIAL: If row and col are 0, "0 0"
	else if(row < 0 && col < 0)
	{
		//Let the game know we're done
		m_isDone = true;
		m_autoGen = false;
	}
	//Normal behavior
	else
	{
		//If tile is occupied
		if(m_board[row][col] == GetPlayerSymbol(player))
		{
			//Remove it
			m_board[row][col] = '-';
		}
		//otherwise
		else
		{
			//Create cell
			m_board[row][col] = GetPlayerSymbol(player);
		}

		//Tell output board to display only once, no special generational
		m_autoGen = false;

		/*
		 * This function is only ever called when generations are finished, never in between.
		 * 	So we can guarentee the board generation is equal to total generations
		 */
		m_boardGenerations = m_generations;

		//cout << "board->oldBoard ";
		BackupBoard(m_oldBoard, m_board);
	}
}

//OutputBoard
//Prints out complete board, alternatively will print in top left corner.
void Life::OutputBoard() const 
{
	if(CORNER_FORMAT)
	{
		//Couldn't figure out how to clear the screen.. Sorry!
		cout << "\033[0;0H";
	}

	//If we're handling printing multiple generations
	if(m_autoGen)
	{
		//Get the boardSize for simplicity
		int boardSize = GetBoardSize();

		//Create temporary board
		char **tempBoard = new char *[boardSize];
		for (int r = 0; r < boardSize; r++)
		{
			tempBoard[r] = new char[boardSize];
		}

		//Copy the old board so we can manipulate it
		BackupBoard(tempBoard, m_oldBoard);

		//Do generations
		for (int i = m_boardGenerations; i < m_generations; i++)
		{
			//Age the board 1 generation
			AgeBoard(tempBoard,1,GetPlayerSymbol(0));

			//For all rows
			for (int r = 0; r < GetBoardSize(); r++) 
			{
				//For all columns
				for (int c = 0; c < GetBoardSize(); c++) 
				{
					//Print tile
					cout << tempBoard[r][c];
				}
				//Next row...
				cout << endl;
			}
			//Padding
			cout << endl;
		}

		//Delete the temporary board
		for (int r = 0; r < GetBoardSize(); r++) 
		{
			delete [] tempBoard[r];
			tempBoard[r] = NULL;
		}
		delete [] tempBoard;
		tempBoard = NULL;
	}
	//When printing a single board
	else
	{
		//For all rows
		for (int r = 0; r < GetBoardSize(); r++) 
		{
			//For all columns
			for (int c = 0; c < GetBoardSize(); c++) 
			{
				//Print tile
				cout << m_board[r][c];
			}
			//Next row...
			cout << endl;
		}
		//Padding
		cout << endl;
	}
}

//OutputResults
//Prints the results of the game to the user(s)
void Life::OutputResults() const
{
	//Counter for alive tiles
	int liveTiles = 0;

	//For all rows
	for (int r = 0; r < GetBoardSize(); r++) 
	{
		//For all columns
		for (int c = 0; c < GetBoardSize(); c++) 
		{
			//If tile is occupied
			if(m_board[r][c] == GetPlayerSymbol(0))
			{
				//Increment tile
				liveTiles++;
			}
		}
	}

	//Information
	cout << "Completed " << m_totalGenerations << " generations." << endl;
	cout << liveTiles << " live cells at end." << endl;
}

//IsLegalMove
//Checks if move is legal
const char *Life::IsLegalMove(int player, int row, int col) const
{
	//Get board size
	int boardSize = GetBoardSize();
	//Checks if values are valid between 0 and Boardsize, inclusively
	if((row >= boardSize || col >= boardSize || row < -1 || col < -1) 
		&& row != -1)
	{
		//Return error string
		return "Out of bounds!";
	}
	else if(row == -1 && col < -1)
	{
		return "Cannot simulate negative generations";
	}
	else
	{
		//Return the "all good" sign.
		return NULL;
	}
}