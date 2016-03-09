#ifndef PROJ4AUX_H
#define PROJ4AUX_H

#include "GridGame.h"

GridGame *SetupGame(int argc, char *argv[]);
bool GameSpecificIsDone(GridGame *game);
void DoOnePlayer(GridGame *game, int player);
void GameSpecificOutputResults(GridGame *game);

#endif //PROJ4AUX_H
