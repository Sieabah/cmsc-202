#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Proj5Aux.h"

#include "GridGame.h"
#include "TicTacToe.h"
#include "Reversi.h"
#include "Life.h"

using namespace std;


GridGame *SetupGame(int argc, char *argv[]) 
{
	GridGame *game = NULL;

	if (argc != 2) 
	{
		cerr << "Syntax: " << argv[0] << " {ttt|reversi|life}" << endl;
	}
	else if (strcmp(argv[1], "ttt") == 0) 
	{
		game = new TicTacToe("XO");
	}
	else if (strcmp(argv[1], "reversi") == 0) 
	{
		game = new Reversi("XO");
	}
	else if (strcmp(argv[1], "life") == 0) 
	{
		game = new Life("O");
	}
	else 
	{
		cerr << argv[1] << ": unrecognized game\n";
	}
	return game;
}

void DoOnePlayer(GridGame *game, int player) 
{
	int row, col;
	const char *errorStr;

	do 
	{
		cout << "\nPlayer " << game->GetPlayerSymbol(player) << "'s move: ";
		cin >> row >> col;
		--row, --col; // Go from 1,1 origin tto 0,0
		cout << endl;
		errorStr = game->IsLegalMove(player, row,  col);
		if (errorStr == NULL) 
		{
		    /* All okay--go ahead and do the move */
			game->DoMove(player, row, col);
		}
		else 
		{
			cout << "Illegal move: " << errorStr << endl;
		}
	} while (errorStr != NULL);
}
