#include "Game.h"
#include <stdio.h>




/*Function will scan the number of rows specified in the parameters.
 Scanned rows are then added to the player table.*/
void loadPlayerTable(CardDecision (*playerTable)[10], FILE* fp, int rows)
{
    char buf[250];
    char* decision = NULL;
    int charCounter = 0, lineCounter = 0;
    while(fgets(buf,sizeof(buf), fp) && strcmp(buf,"\n") != 0)
    {
        for(decision = strtok(buf," "), charCounter = 0; charCounter<10; decision = strtok(NULL," "), charCounter++)
        {
            if(strcmp(decision,"h") == 0)
                playerTable[lineCounter][charCounter] = HIT;
            else if(strcmp(decision,"s") == 0)
                playerTable[lineCounter][charCounter] = STAND;
            else if(strcmp(decision,"d") == 0)
                playerTable[lineCounter][charCounter] = DOUBLEDOWN;
            else if(strcmp(decision,"sp") == 0)
                playerTable[lineCounter][charCounter] = SPLIT;
            else
            {
                printf("Error parsing file. Please check file format...\n");
                exit(1);
            }
        }
        lineCounter++;
    }
}

//Create a deck of cards and shuffle everything.
void initializeDeck(GameDeck* gameDeck)
{
    gameDeck->currentCard = 0;
    int counter = 0;
    for(int i = 0 ;i<300; i++)
    {
        if(i%24 == 0 && counter < 10)
            counter++;
        gameDeck->cards[i] = counter;
    }
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<300; j++)
        {
            int pos = rand()%300;
            int temp = gameDeck->cards[pos];
            gameDeck->cards[pos] = gameDeck->cards[j];
            gameDeck->cards[j] = temp;
        }
    }
}



void sessionPlayer(Player* currentPlayer, GameDeck* deck)
{
    // Splitting can only be done with the first two cards.
    // if the player splits, divide the two cards into two different hands.
    // add another card to each of the split decks.

    // Deal two cards to the player's hand
    //  first;
    PlayerHand* currentHand = &currentPlayer->hands[currentPlayer->currentHand];
    dealCard(deck, currentPlayer);
    dealCard(deck, currentPlayer);

    if(currentHand->hand[0] == currentHand->hand[1])
        currentHand->handType = DOUBLE;
    else if(currentHand->hand[0] == 1 || currentHand->hand[1] == 1)
        currentHand->handType = SOFT;
    else
        currentHand->handType = HARD;




    
}


CardDecision playerDecide(Player* currentPlayer, int upCard, bool first)
{

}


/*Updates a player's current hand. Works for the dealer too.*/
void updateCurrentHand(PlayerHand* curHand)
{
    int currentSum = 0;
    int aceCount = 0;
    for(int i = 0; i<curHand->numCards; i++)
    {   
        if(curHand->hand[i] != 1)
            currentSum+= curHand->hand[i];
        else
            aceCount ++;
    }
    if(aceCount >0 && currentSum +11+aceCount-1<=21)
        curHand->cardCount = currentSum+11+aceCount-1;
    else
        curHand->cardCount = currentSum+aceCount;
}


// Return a card from the top of the deck.
// advance the current card in the player and the deck.
int dealCard(GameDeck* deck, Player* currentPlayer)
{ 
    int curHand = currentPlayer->currentHand;
    PlayerHand* playerDeck = &currentPlayer->hands[curHand];
    playerDeck->hand[playerDeck->numCards] = deck->cards[deck->currentCard];
    playerDeck->numCards++;
    deck->currentCard++;
    updateCurrentHand(playerDeck);
}

