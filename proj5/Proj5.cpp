/****************************************************************
 * Proj5.cpp:
 *
 ****************************************************************/

#include <iostream>
#include <cstdlib>
#include "Proj5Aux.h"
#include "GridGame.h"

using namespace std;


int main(int argc, char *argv[]) {
    GridGame *game;
    int numPlayers;

    if ((game = SetupGame(argc, argv)) == NULL) {
	exit(1);
    }
    game->OutputGreeting();
    numPlayers = game->NumPlayers();
    for (int player = 0; !game->IsDone(); player = (player + 1) % numPlayers) {
	DoOnePlayer(game, player);
	game->OutputBoard();
    }
    game->OutputResults();
}
