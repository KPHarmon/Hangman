#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int main (void)
{
    int mainInput;
    printf("\n1:  PLAY\n2:  OPTIONS\n3:  HELP\n4:  QUIT\n");
    scanf("%d", mainInput);
    switch(input)
    {
        case 1:
            game();
            break;
        case 2:
            options();
            break;
        case 3:
            help();
            break;
        case 4:
            quit();
            break;
        default:
            printf("\nYOU CAN ONLY CHOOSE 1 OR 2\n");
            return 0;
    }
}

int game(void)
{
    int countPlayer;
    printf("\n1:  ONE PLAYER\n2:  TWO+ PLAYERS\n");
    scanf("%d", countPlayer);
    switch(countPlayer)
    {
        case1:
            playerOne();
            break;
        case2:
            playerTwo();
            break;
        default:
            printf("\nYOU CAN ONLY CHOOSE 1 OR 2\n");
            break;
    }
}

int playerOne(void)
{
    
}

int playerTwo(void)
{
    int counterLives = 5, wordSize, flag = 0, i;
    char wordTwo[30], guess;
    printf("\nPLAYER ONE: TYPE A WORD\nDONT LET THE OTHERS SEE IT!\n");
    scanf("%s", wordTwo);
    while(counterLives > 0)
    {
        printf("\nCHOOSE A LETTER\n");
        scanf(" %c", guess);
        char x[wordSize];
        for(i = 0; i < wordSize; i++)
        {
            x[i] = " _ ";
        }
        for(i = 0; i < wordSize; i++)
        {
            while(wordTwo[i] != '\0')
            {
                printf("%s", x);
                counterLives--;
                if(counterLives == 0)
                {
                    printf("\n\n\nYOU LOSE\n\n\n");
                }
                while(x[i] != '\0')
                {
                    if (x[i] != "_")
                        flag = 1;
                }
                if(flag == 1)
                    printf("/n/n/nYOU WIN/n/n/n");   
                }
            }
        }
    }
}

int options(void)
{
    
}

int  help(void)
{
    
}

