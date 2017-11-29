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
int persisLives;
    
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
            break;
    }
}

//mAIN MENU FOR THE GAME
int game(void)
{
    int countPlayer;
    system("cls");
    printf("\n1:  SINGLE PLAYER\n2:  TWO+ PLAYERS\n3:  MAIN MENU\n");
    scanf("%d", &countPlayer);
    switch(countPlayer)
    {
        case 1:
            playerOne();
            break;
        case 2:
            playerTwo();
            break;
        case 3:
            main();
            break;
        default:
            printf("\nCHOOSE 1 OR 2\n");
            game();
    }
}

int playerOne(void)
{
    system("cls");
    int wordSize, i, j=0, input, counter = 0, catInput;
    char wordOne[30], blanks[30], guess, wrongChars[9];
    
    //COLLECTING STRING FROM TXT FILE
    srand((int)time(NULL));
    int count = 0;

    FILE *file = fopen("listCountries.txt", "r");   
    
    char line[40];
    while(fgets(line, sizeof line, file) != NULL)
    {
        count++;
        if((rand() * count) / RAND_MAX == 0)
        {
            // reads text until newline
            fscanf(file, "%[^\n]", wordOne);
        }
    } 
    fclose(file);
    
    wordSize = strlen(wordOne);
    persisLives = counterLives;
    //INITIALIZING ARRAY
    for(i = 0; i < wordSize; i++)
    {
        blanks[i] = '_';  
    } 
    for(i = 0; i < 9; i++)
    {
        wrongChars[i] = '\0';
    }
    
    //MAIN INTERFACE FOR PLAYER1 GAME
    while(persisLives > 0)
    {
        int flag = 0;
        system("cls");
        //lives updater
        printf(" LIVES: %d", persisLives);
        printf("\n\n");
        //blanks updater
        for(i = 0; i < wordSize; i++)
        {
            printf(" %c", blanks[i]);
        }
        //guesses tracker
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
            if(wordOne[i] == guess)
            {
                printf("\a");
                blanks[i] = guess;
                counter++;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            persisLives--;
            wrongChars[j] = guess;
            j++; 
        }
        if(persisLives == 0)
        {
            printf("\n\n\nYOU LOSE, THE CORRECT ANSWER IS %s\n\n\nTYPE '1' TO PLAY AGAIN\nTYPE '2' TO RETURN TO MAIN MENU\n", wordOne);
            scanf(" %d", &input);
            switch(input)
            {
                case 1:
                    playerOne();
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
            system("cls");
            printf(" LIVES: %d\n\n", persisLives);
            for(i = 0; i < wordSize; i++)
            {
                 printf(" %c", blanks[i]);
            }
            //guesses tracker
            printf("\n\nWRONG GUESSES:\n");
            for(i = 0; i < 9; i++)
            {
                printf(" %c", wrongChars[i]);
            }
            
            printf("\n\nYOU WIN!");

            printf("\n\nTYPE '1' TO PLAY AGAIN\nTYPE '2' TO RETURN TO MAIN MENU\n");
            scanf(" %d", &input);
            switch(input)
            {
                case 1:
                    playerOne();
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

int playerTwo(void)
{
    system("cls");
    int wordSize, i, j=0, input, counter = 0;
    char wordTwo[30], blanks[30], guess, wrongChars[9];
    int persisLives = counterLives;
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
    while(persisLives > 0)
    {
        int flag = 0;
        system("cls");
        //lives updater
        printf(" LIVES: %d", persisLives);
        printf("\n\n");
        //blanks updater
        for(i = 0; i < wordSize; i++)
        {
            printf(" %c", blanks[i]);
        }
        //guesses tracker
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
            persisLives--;
            wrongChars[j] = guess;
            j++; 
        }
        if(persisLives == 0)
        {
            printf("\n\n\nYOU LOSE, THE CORRECT ANSWER IS %s\n\n\nTYPE '1' TO PLAY AGAIN\nTYPE '2' TO RETURN TO MAIN MENU\n", wordTwo);
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
                    printf("YOU CAN ONLY PICK '1' OR '2'");
                    break;
            }
        }
        if(persisLives == wordSize)
        {
            system("cls");
            printf(" LIVES: %d\n\n", persisLives);
            for(i = 0; i < wordSize; i++)
            {
                 printf(" %c", blanks[i]);
            }
            //guesses tracker
            printf("\n\nWRONG GUESSES:\n");
            for(i = 0; i < 9; i++)
            {
                printf(" %c", wrongChars[i]);
            }
            
            printf("\n\nYOU WIN!");

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
                    printf("YOU CAN ONLY PICK '1' OR '2'");
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
    scanf("%d", &inputDiff);
    switch(inputDiff)
    {
        case 1:
            strcpy(difficulty, "EASY");
            counterLives = 11;
            persisLives = counterLives;
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
            printf("Choose a difficult setting.");
            options();
    }
}

int help(void)
{
    char inputChar;
    inputChar = getchar();
    system("cls");
    printf("\n\n - PLAY INDIVIDUALLY OR IN A GROUP.\n\n - IF PLAYING IN A GROUP, SELECT A WORD (DON'T LET OTHERS SEE IT!).\n\n - TYPE A LETTER YOU THINK WILL BE FOUND IN THE WORD.\n\n - CONTINUE UNTIL THE WORD IS CORRECTLY GUESSED OR YOU RUN OUT OF LIVES!\n\n\n\n\n\n\n*TYPE A LETTER TO RETURN TO THE MAIN MENU*\n\n\n\n\n\n\n\n");
    scanf(" %c", &inputChar);
    if(inputChar >= 'a' && inputChar <= 'z' || inputChar >= 'A' && inputChar <= 'Z')
    {
        main();
    }
}
int quit(void)
{
    return 0;
}