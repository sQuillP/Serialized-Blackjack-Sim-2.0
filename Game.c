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

// void otherFunc(cardDecision (*playerTable)[9])
// {
//     return;
// }