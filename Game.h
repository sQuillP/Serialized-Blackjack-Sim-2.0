#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Player.h"
#ifndef GAME_H
#define GAME_H



void loadPlayerTable(CardDecision (*playerTable)[10], FILE* fp, int rows);


// bool validatePlayerInput(const char* input);

#endif