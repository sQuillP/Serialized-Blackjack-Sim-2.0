#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef PLAYER_H
#define PLAYER_H


// previous code was too messy, out of place.


typedef enum CardDecision
{
    HIT,
    STAND,
    DOUBLEDOWN,
    SPLIT
} CardDecision;


typedef enum HandType
{
  SOFT,
  HARD,
  DOUBLE
}HandType;


typedef struct Playerstats
{
  int softScore[2];
  int splitScore[2];
  int hardScore[2];
  int doubleDown[2];
  int push;
  int natural21;
} Playerstats;


typedef struct PlayerHand
{
  int hand[15];
  int cardCount;
  int numCards;
  bool doubleDown;
  HandType handType;
} PlayerHand;


typedef struct Player
{
    Playerstats stats;
    PlayerHand hands[4];
    int currentHand;
    CardDecision hardTable[17][10], 
    softTable[9][10],
    doublesTable[10][10];
    
} Player;


#endif