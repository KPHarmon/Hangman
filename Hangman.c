#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

int main();
int game();
int playerOne();
int playerTwo();
int options();
int help();
int quit();
int counterLives = 8;
char difficulty[7] = "MEDIUM";
    
int main(void)
{
    system("cls");
    int mainInput;
    printf("\nMAIN MENU:\n\n1:  PLAY\n2:  OPTIONS\n3:  HELP\n4:  QUIT\n");
    scanf("%d", &mainInput);
    switch(mainInput)
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
            printf("\nCHOOSE 1, 2, 3, OR 4\n");
            return 0;
    }
}

int game(void)
{
    int countPlayer;
    system("cls");
    printf("\n1:  ONE PLAYER\n2:  TWO+ PLAYERS\n");
    scanf("%d", &countPlayer);
    switch(countPlayer)
    {
        case 1:
            playerOne();
            break;
        case 2:
            playerTwo();
            break;
        default:
            printf("\nCHOOSE 1 OR 2\n");
            break;
    }
}

int playerOne(void)
{
    
}

//Can add spaces, traverse inputted string for space, if it finds a space, save the position, and pass i != (posiion) in middle part of for loop, make nothing instead
int playerTwo(void)
{
    system("cls");
    int wordSize, i, j=0, input, counter = 0;
    char wordTwo[30], blanks[30], guess, wrongChars[9];
    printf("\nPLAYER ONE: TYPE ONE WORD (MAKE SURE CAPS IS ON)\n\nDONT LET THE OTHERS SEE IT!\n");
    scanf("%s", &wordTwo);
    wordSize = strlen(wordTwo);
    
    //Initializing Arrays
    for(i = 0; i < wordSize; i++)
    {
        blanks[i] = '_';
    }
    for(i = 0; i < 9; i++)
    {
        wrongChars[i] = '\0';
    }
    
    //MAIN INTERFACE FOR PLAYER2 GAME
    while(counterLives > 0)
    {
        int flag = 0;
        system("cls");
        //lives updater
        printf(" LIVES: %d", counterLives);
        printf("\n\n");
        
        //updates blanks per guess
        for(i = 0; i < wordSize; i++)
        {
            printf(" %c", blanks[i]);
        }
        
        //updates wrong guesses
        printf("\n\nWRONG GUESSES:\n");
        for(i = 0; i < 9; i++)
        {
            printf(" %c", wrongChars[i]);
        }
        
        //input letter, check to see if input character matches word, if not, take away life
        printf("\n\nGUESS A LETTER\n");
        scanf(" %c", &guess);
        for(i=0; i<wordSize; i++)
        {
            if(wordTwo[i] == guess)
            {
                printf("\a");
                blanks[i] = guess;
                counter++;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            counterLives--;
            wrongChars[j] = guess;
            j++; 
        }
        
        //if player runs out of lives, end game
        if(counterLives == 0)
        {
            printf("\n\n\nYOU LOSE\n\n\nTYPE '1' TO PLAY AGAIN\nTYPE '2' TO RETURN TO MAIN MENU\n");
            scanf(" %d", &input);
            switch(input)
            {
                case 1:
                    playerTwo();
                    break;
                case 2:
                    main();
                    break;
                default:
                    printf("PICK '1' OR '2'");
                    break;
            }
        }
        if(counter == wordSize)
        {
            //changes blank to character if the word contains the guess
            system("cls");
            printf(" LIVES: %d\n\n", counterLives);
            for(i = 0; i < wordSize; i++)
            {
                 printf(" %c", blanks[i]);
            }
            
            //Tracks guesses
            printf("\n\nWRONG GUESSES:\n");
            for(i = 0; i < 9; i++)
            {
                printf(" %c", wrongChars[i]);
            }
            
            //prints "You Win" many times 
            printf("\n\n");
            for(i=0; i<100; i++)
            {
                printf("YOUWIN\t");
            }

            printf("\n\nTYPE '1' TO PLAY AGAIN\nTYPE '2' TO RETURN TO MAIN MENU\n");
            scanf(" %d", &input);
            switch(input)
            {
                case 1:
                    playerTwo();
                    break;
                case 2:
                    main();
                    break;
                default:
                    printf("PICK '1' OR '2'");
                    break;
            }
        }
    }
}

int options(void)
{
    int inputDiff;
    system("cls");
    printf("DIFFICULTY OPTIONS:\n");
    printf("PRESS '1' FOR EASY DIFFICULTY\n");
    printf("PRESS '2' FOR MEDIUM DIFFICULTY\n");
    printf("PRESS '3' FOR HARD DIFFICULTY\n");
    printf("PRESS '4' TO RETURN TO THE MAIN MENU\n");
    printf("\n\n\n\nCURRENT DIFFICULTY SETTING: %s\n", difficulty);
    
    //Take input, depending on input, change value of counterLives
    scanf("%d", &inputDiff);
    switch(inputDiff)
    {
        case 1:
            strcpy(difficulty, "EASY");
            counterLives = 11;
            options();
            break;
        case 2:
            strcpy(difficulty, "MEDIUM");
            counterLives = 8;
            options();
            break;
        case 3:
            strcpy(difficulty, "HARD");
            counterLives = 6;
            options();
            break;
        case 4:
            main();
            break;
        default:
            printf("Choose a difficulty setting.");
            options();
            break;
    }
}

int help(void)
{
    char inputChar;
    inputChar = getchar();
    system("cls");
    printf("\n\n - Play individually or in a group.\n\n - If playing in a group, select a word (don't let others see it!).\n\n - Type a letter you think will be found in the word.\n\n - Continue until the word is correctly guessed or you run out of lives!\n\n\n\n\n\n\n*Type a Letter to Return to the Main Menu*\n\n\n\n\n\n\n\n");

    //if input is a character, return to menu
    scanf(" %c", &inputChar);
    if(inputChar >= 'a' && inputChar <= 'z' || inputChar >= 'A' && inputChar <= 'Z')
    {
        main();
    }
}

int quit(void)
{
    
    //exit program
    return 0;
}