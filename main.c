#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "Player.h"
#include "Game.h"

/*
TODO: 

- Main needs to be refactored/broken up into funcitons.

*/


int main()
{
    char buf[256];
    char* stringBuf = NULL;
    char** files = (char**) malloc(sizeof(char*));
    int fileCount = 0;
    int simulations = 0;
    FILE* fp = NULL;
    Player** players;
    GameResources resources;

    srand(time(NULL));

    printf("###Welcome to blackjack 2.0###\n\n");
    printf("Please Enter the file paths for each player file separated by a whitespace...\n");
    printf("Blackjack 2.0>");

    if(fgets(buf,sizeof(buf),stdin) != NULL)
    {
        // validateInput(buf);
        stringBuf = strtok(buf," ");
        while(stringBuf != NULL)
        {
            files = (char**) realloc(files, sizeof(char*)*(1+fileCount));
            files[fileCount] = (char*) malloc(sizeof(char)*25);
            strcpy(files[fileCount],stringBuf);
            files[fileCount][strlen(files[fileCount])-1] = '\0';
            fileCount++;
            stringBuf = strtok(NULL," ");
        }
    }
    else
    {
        printf("Invalid input, exiting program...");
        exit(1);
    }

    printf("How many simulations would you like to run?\n");
    printf("Backjack 2.0>");
    fgets(buf,sizeof(buf),stdin);
    simulations = atoi(buf);

    if(simulations == 0)
    {
        printf("Please enter a positive, nonzero integer.\n");
        exit(1);
    }

    resources.players = (Player**)malloc(sizeof(Player*)*fileCount);
    initializeDeck(&resources.deck);

    for(int i = 0; i<fileCount; i++)
    {
        resources.players[i] = (Player*)malloc(sizeof(Player));
        fp = fopen(files[i],"r");
        printf("%s\n\n",files[i]);
        if(fp == NULL)
        {
            printf("Unable to open %s, exiting the program.\n",files[i]);
            exit(1);
        }
        loadPlayerTable(resources.players[i]->hardTable , fp, 17);
        loadPlayerTable(resources.players[i]->softTable, fp, 9);
        loadPlayerTable(resources.players[i]->doublesTable, fp, 10);
        fclose(fp);
    }

    // begin the game simulation

   

    return 0;
}