#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Player.h"
#include "Game.h"

/*
TODO: 
- Program needs to be more robust on user input.
- Maintain cleanliness on the main

*/


int main()
{
    char buf[256];
    char* stringBuf = NULL;
    char** files = (char**) malloc(sizeof(char*));
    int fileCount = 0;
    FILE* fp = NULL;
    Player** players;

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
    players = (Player**)malloc(sizeof(Player*)*fileCount);


    for(int i = 0; i<fileCount; i++)
    {
        players[i] = (Player*)malloc(sizeof(Player));
        fp = fopen(files[i],"r");
        printf("%s\n\n",files[i]);
        if(fp == NULL)
        {
            printf("Unable to open %s, exiting the program.\n",files[i]);
            exit(1);
        }
        loadPlayerTable(players[i]->hardTable , fp, 17);
        loadPlayerTable(players[i]->softTable, fp, 9);
        loadPlayerTable(players[i]->doublesTable, fp, 10);

    }


    // printf("%d \t %d\t%d\n",players[0]->hardTable[8][3],players[0]->softTable[5][6], players[0]->doublesTable[2][3]);


    return 0;
}