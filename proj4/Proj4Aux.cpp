#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Proj4Aux.h"

#include "GridGame.h"
#include "TicTacToe.h"
#include "Reversi.h"

using namespace std;


GridGame *SetupGame(int argc, char *argv[]) {
    GridGame *game = NULL;

    if (argc != 2) {
	cerr << "Syntax: " << argv[0] << " {ttt|reversi}" << endl;
    }
    else if (strcmp(argv[1], "ttt") == 0) {
	game = new TicTacToe("XO");
    }
    else if (strcmp(argv[1], "reversi") == 0) {
	game = new Reversi("XO");
    }
    else {
	cerr << argv[1] << ": unrecognized game\n";
    }
    return game;
}


bool GameSpecificIsDone(GridGame *game) {
    bool isDone;

    switch (game->GetType()) {
    case GAME_TICTACTOE:
    {
	TicTacToe *realGame = static_cast<TicTacToe*>(game);
	isDone = realGame->IsDone();
	break;
    }
    case GAME_REVERSI:
    {
	Reversi *realGame = static_cast<Reversi*>(game);
	isDone = realGame->IsDone();
	break;
    }
    default:
	cerr << "In middle of unknown game???\n";
	exit(1);
    }
    return isDone;
}


void DoOnePlayer(GridGame *game, int player) {
    int row, col;
    const char *errorStr;

    do {
	cout << "\nPlayer " << game->GetPlayerSymbol(player) << "'s move: ";
	cin >> row >> col;
	--row, --col; // Go from 1,1 origin tto 0,0
	errorStr = game->IsLegalMove(player, row,  col);
	if (errorStr == NULL) {
	    /* All okay--go ahead and do the move */
	    switch (game->GetType()) {
	    case GAME_TICTACTOE:
	    {
		TicTacToe *realGame = static_cast<TicTacToe*>(game);
		realGame->DoMove(player, row, col);
		break;
	    }
	    case GAME_REVERSI:
	    {
		Reversi *realGame = static_cast<Reversi*>(game);
		realGame->DoMove(player, row, col);
		break;
	    }
	    default:
		cerr << "In middle of unknown game???\n";
		exit(1);
	    }
	}
	else {
	    cout << "Illegal move: " << errorStr << endl;
	}
    } while (errorStr != NULL);
}

void GameSpecificOutputResults(GridGame *game) {
    switch (game->GetType()) {
    case GAME_TICTACTOE:
    {
	TicTacToe *realGame = static_cast<TicTacToe*>(game);
	realGame->OutputResults();
	break;
    }
    case GAME_REVERSI:
    {
	Reversi *realGame = static_cast<Reversi*>(game);
	realGame->OutputResults();
	break;
    }
    default:
	cerr << "In middle of unknown game???\n";
	exit(1);
    }
}
