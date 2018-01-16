#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <assert.h>
#define LINE_LENGTH 1024

//Initialize functions
int main();
int game();
int playerOne();
int playerTwo();
int options();
int help();
int quit();
int win();
int lose();

//Word Lists functions
int countries();
int movies();
int books();
int brands();
int people();
int winter();
int animals();
int hackathon();

//Initialize default amount of lives
int counterLives = 8;
char difficulty[7] = "MEDIUM";
int persisLives;
FILE *file;
char wordOne[30], wordTwo[30];

//Main Menu
int main(void)
{
    system("cls");
    int mainInput;
    printf("MAIN MENU:\n\n1:  PLAY\n2:  OPTIONS\n3:  HELP\n4:  QUIT\n");
    printf("____________   \n");
    printf("|         |    \n");
    printf("|         0    \n");
    printf("|        /|\\  \n");
    printf("|        / \\  \n");
    printf("|              \n");
    printf("|              \n");
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

//Single player Selection
int game(void)
{
    int countPlayer;
    system("cls");
    printf("CHOOSE PLAYER SETTING:\n\n1:  SINGLE PLAYER\n2:  TWO+ PLAYERS\n3:  MAIN MENU\n");
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

//Single player game
int playerOne(void)
{
    srand((int)time(NULL));
    system("cls");
    int wordSize, i, j=0, input, counter = 0, catInput, calibrate = 0;
    char blanks[30], guess, wrongChars[9];
    int count = 0;
    persisLives = counterLives;     //persisLives value will change throughout run, will grab the static
                                    //counterLives value before each run(selected in options or by default)
    //Category Selection
    printf("CHOOSE A CATEGORY:\n\n");
    printf("1.  ANIMALS\n");
    printf("2.  BOOKS\n");
    printf("3.  BRANDS\n");
    printf("4.  COUNTRIES\n");
    printf("5.  HACKATHON\n");
    printf("6.  MOVIES\n");
    printf("7.  PEOPLE\n");
    printf("8.  WINTER\n");
    printf("--------------------\n");
    printf("9.  PLAYER SELECTION\n");
    scanf("%d", &catInput);
    
    //Workaround for C not liking multiple file pulls in same function
    switch(catInput)
    {
        case 1:
            animals();
            break;
        case 2:
            books();
            break;
        case 3:
            brands();
            break;
        case 4:
            countries();
            break;
        case 5:
            hackathon();
            break;
        case 6:
            movies();
            break;
        case 7:
            people();
            break;
        case 8:
            winter();
            break;
        case 9:
            game();
            break;
        dafault:
            main();
            break;
    }
    
    //Scan through scanning length of file, chooses a random line, pulls string, stores in variable wordOne
    char line[40];
    while(fgets(line, sizeof line, file) != NULL)
    {
        char *p = strchr(line, '\n');
        if (p != NULL) {
            assert(*p == '\n');
        *p = '\0';
    }
    else 
    {
        char linebuff[LINE_LENGTH];
        while((p = fgets(linebuff, LINE_LENGTH, file)) != NULL) 
        {
            if ((p = strchr(linebuff, '\n')) != NULL)
                break;
        }
    }
    assert(strchr(line, '\n') == NULL);
        
        count++;
        if ((rand() / (float)RAND_MAX) <= (1.0 / count)) 
        {
            fscanf(file, "%[^\n]", wordOne);
        }
    } 
    fclose(file);
    
    //Store length of the found string
    wordSize = strlen(wordOne);

    //Initialize array blanks with underscores or slashes if it finds a space
    for(i = 0; i < wordSize; i++)
    {
        blanks[i] = '_';
        if(wordOne[i] == ' ')
        {
            blanks[i] = '/';
            calibrate++;      
        }
    }
    
    //Initialize array of incorrect guesses
    for(i = 0; i < 9; i++)
    {
        wrongChars[i] = '\0';
    }
    
    //While loop will continuously display updated loops until a person runs out of lives
    while(persisLives > 0)
    {
        int flag = 0, flag2 = 0;
        system("cls");
        
        //Dislay number of lives
        printf(" LIVES: %d", persisLives);
        printf("\n\n");
        
        //Display array of blanks
        for(i = 0; i < wordSize; i++)
        {
            printf(" %c", blanks[i]);
        }
        
        //Display array of wrong guesses
        printf("\n\nWRONG GUESSES:\n");
        for(i = 0; i < 9; i++)
        {
            printf(" %c", wrongChars[i]);
        }
        
        //Scans for user input and checks to see if input matches character in generated word
        printf("\n\nGUESS A LETTER\n");
        scanf(" %c", &guess);
        for(i=0; i<wordSize; i++)
        {
            if(wordOne[i] == guess  && blanks[i] == '_')
             {
                printf("\a");
                blanks[i] = guess;
                counter++;
                flag = 1;
             }
        }
        
        //If the input is not found, remove a life and add to array of wrong guesses
        if(flag == 0)
        {
            persisLives--;
            wrongChars[j] = guess;
            j++;
        }
        
        //Checks to find underscores, if there is then change flag
        for(i = 0; i<wordSize; i++)
        {
            if(blanks[i] == '_')
            {
                flag2 = 1;
                break;  
            }
        }
        
        //If the lives reaches zero and flag from above is triggered, display lose screen
        if(flag2 == 1 && persisLives == 0)
        {
            system("cls");
            
            //Display final Lives
            printf(" LIVES: %d\n", persisLives);
            printf("\n");
        
            //Display final blanks
            for(i = 0; i < wordSize; i++)
            {
                printf(" %c", blanks[i]);
            }
            
            //Display final guesses
            printf("\n\nWRONG GUESSES:\n");
            for(i = 0; i < 9; i++)
            {
                printf(" %c", wrongChars[i]);
            }
            
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
                    playerOne();
                    break;
            }
        }
        
        //If a person fills up blanks, while still having a life, display win screen
        else if(flag2 == 0)
        {
            system("cls");
            
            //Display Lives
            printf(" LIVES: %d\n", persisLives);
            printf("\n");
        
            //Display blanks
            for(i = 0; i < wordSize; i++)
            {
                printf(" %c", blanks[i]);
            }
    
            //Display Guesses
            printf("\n\nWRONG GUESSES:\n");
            for(i = 0; i < 9; i++)
            {
                printf(" %c", wrongChars[i]);
            }
            
            //Display menu to play again or return to main menu
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
                    printf("YOU CAN ONLY PICK '1' OR '2'");
                    playerOne();
                    break;
            }
        }
    }
}

//Mutliplayer game
int playerTwo(void)
{
    system("cls");
    int wordSize, i, j=0, k, input, input2, counter = 0;
    char blanks[30], guess, wrongChars[9];
    int persisLives = counterLives;
    
    //Has one user input a word
    printf("\nPLAYER ONE: TYPE ONE WORD (MAKE SURE CAPS IS ON)\n\nDONT LET THE OTHERS SEE IT!\n");
    scanf("%s", &wordTwo);
    wordSize = strlen(wordTwo);
    
    //Initializing array of blanks
    for(i = 0; i < wordSize; i++)
    {
        blanks[i] = '_';
    }
    
    //Initializing array of wrong guesses
    for(i = 0; i < 9; i++)
    {
        wrongChars[i] = '\0';
    }
    
    //Main interface for game 
    while(persisLives > 0)
    {
        system("cls");
        int flag = 0, flag2 = 0;
        
        //Display Lives
        printf(" LIVES: %d\n", persisLives);
        printf("\n");
        
        //Display blanks
        for(i = 0; i < wordSize; i++)
        {
            printf(" %c", blanks[i]);
        }
        
        //Display wrong guesses
        printf("\n\nWRONG GUESSES:\n");
        for(i = 0; i < 9; i++)
        {
            printf(" %c", wrongChars[i]);
        }
        
        //Scans for user input and checks to see if input matches a character in generated word
        printf("\n\nGUESS A LETTER\n");
        scanf(" %c", &guess);
        
        //Check for duplicates
        for(i=0; i<wordSize; i++)
        {
            if(wordTwo[i] == guess  && blanks[i] == '_')
             {
                printf("\a");
                blanks[i] = guess;
                counter++;
                flag = 1;
             }
        }
        
        //If the input is not found, remove a life and add to array of wrong guesses
        if(flag == 0)
        {
            persisLives--;
            wrongChars[j] = guess;
            j++;
        }
        
        //Checks to find underscores, if there is then change flag
        for(i = 0; i<wordSize; i++)
        {
            if(blanks[i] == '_')
            {
                flag2 = 1;
                break;  
            }
        }
        
        //If the lives reaches zero and flag from above is triggered, display lose screen
        if(flag2 == 1 && persisLives == 0)
        {
            system("cls");
            
            //Display final Lives
            printf(" LIVES: %d\n", persisLives);
            printf("\n");
        
            //Display final blanks
            for(i = 0; i < wordSize; i++)
            {
                printf(" %c", blanks[i]);
            }
            
            //Display final guesses
            printf("\n\nWRONG GUESSES:\n");
            for(i = 0; i < 9; i++)
            {
                printf(" %c", wrongChars[i]);
            }
            
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
                    printf("PICK '1' OR '2'");
                    playerTwo();
                    break;
            }
        }
        
        //If a person fills up blanks, while still having a life, display win screen
        else if(flag2 == 0)
        {
            system("cls");
            
            //Display Lives
            printf(" LIVES: %d\n", persisLives);
            printf("\n");
        
            //Display blanks
            for(i = 0; i < wordSize; i++)
            {
                printf(" %c", blanks[i]);
            }
    
            //Display Guesses
            printf("\n\nWRONG GUESSES:\n");
            for(i = 0; i < 9; i++)
            {
                printf(" %c", wrongChars[i]);
            }
            
            //Display menu to play again or return to main menu
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
                    playerTwo();
                    break;
            }
        }
    }
}

//Options menu
int options(void)
{
    system("cls");
    int inputDiff;
    printf("DIFFICULTY OPTIONS:\n");
    printf("PRESS '1' FOR EASY DIFFICULTY\n");
    printf("PRESS '2' FOR MEDIUM DIFFICULTY\n");
    printf("PRESS '3' FOR HARD DIFFICULTY\n");
    printf("PRESS '4' TO RETURN TO THE MAIN MENU\n");
    printf("\n\n\n\nCURRENT DIFFICULTY SETTING: %s\n", difficulty);
    scanf("%d", &inputDiff);
    
    //Change value of counterLives to selected value
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

//Help menu
int help(void)
{
    char inputChar;
    inputChar = getchar();
    system("cls");
    printf("\nHELP MENU:\n\n - PLAY INDIVIDUALLY OR IN A GROUP.\n\n - IF PLAYING IN A GROUP, SELECT A WORD (DON'T LET OTHERS SEE IT!).\n\n - TYPE A LETTER YOU THINK WILL BE FOUND IN THE WORD (REMEMBER TO IGNORE PUNCTUATION MARKS).\n\n - CONTINUE UNTIL THE WORD IS CORRECTLY GUESSED OR YOU RUN OUT OF LIVES!\n\n\n\n*TYPE A LETTER TO RETURN TO THE MAIN MENU*\n");
    scanf(" %c", &inputChar);
    if(inputChar >= 'a' && inputChar <= 'z' || inputChar >= 'A' && inputChar <= 'Z')
    {
        main();
    }
}

//Quit program
int quit(void)
{
    return 0;
}

//Functions for wordlists
int countries(void)
{
    file = fopen("lists\listCountries.txt", "r");
}
int movies(void)
{
    file = fopen("lists\listMovies.txt", "r");
}
int books(void)
{
    file = fopen("lists\listBooks.txt", "r");
}
int winter(void)
{
    file = fopen("lists/listWinter.txt", "r");
}
int animals(void)
{
    file = fopen("lists\listAnimals.txt", "r");
}
int people(void)
{
    file = fopen("lists\listPeople.txt", "r");
}
int brands(void)
{
    file = fopen("lists\listBrands.txt", "r");
}
int hackathon(void)
{
    file = fopen("lists\listHackathon.txt", "r");
}

//Kade Harmon