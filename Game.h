#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Player.h"
#ifndef GAME_H
#define GAME_H

typedef struct GameDeck
{
    int cards[300];
    int currentCard;
} GameDeck;


typedef struct GameResources
{
    GameDeck deck;
    Player dealer;
    Player** players;
} GameResources;

void loadPlayerTable(CardDecision (*playerTable)[10], FILE* fp, int rows);
void initializeDeck(GameDeck* deck);
int dealCard(GameDeck* deck, Player* player);
void sessionPlayer(Player* currentPlayer, GameDeck* deck);
CardDecision playerDecide(Player* player, int upCard, bool first);

// bool validatePlayerInput(const char* input);

#endif