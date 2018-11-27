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
int options();
int help();
int win();
int lose();
const char* assignlists();
char* random_word(FILE*);

//Word Lists functions
void countries();
void movies();
void books();
void brands();
void people();
void winter();
void animals();
void hackathon();

//Initialize default amount of lives
int difficultyLives = 8;
char wordOne[30];
FILE* file;

//Main Menu
int main(void){
    system("cls");
    int mainInput;
    printf("MAIN MENU:\n\n1:  PLAY\n2:  OPTIONS\n3:  QUIT\n");
    printf("____________   \n");
    printf("|         |    \n");
    printf("|         0    \n");
    printf("|        /|\\  \n");
    printf("|        / \\  \n");
    printf("|              \n");
    printf("|              \n");
    scanf("%d", &mainInput);
    switch(mainInput){
        case 1:
            playerOne();
            break;
        case 2:
            difficultyLives = options();
            break;
        case 3:
	        return 0;
            break;
        default:
            printf("\nCHOOSE 1, 2, 3\n");
            break;
    }
	return 0;
}

//Single player game
int playerOne(void){
    system("cls");
    srand((int)time(NULL));
	char line[256];
	int flag1 = 0;
    int i = 0, j = 0, input, counter = 0, spaces = 0, catInput, calibrate = 0;
    char blanks[30], guess, wrongChars[11] = "";
    int count = 0;
    int counterLives = difficultyLives;     //currentLives value will change throughout run, will grab the static
											//counterLives value before each run(selected in options or by default)
    //Category Selection
    printf("CHOOSE A CATEGORY:\n\n");
    printf("1.  ANIMALS\n");
    printf("2.  BOOKS\n");
    printf("3.  BRANDS\n");
    printf("4.  COUNTRIES\n");
    printf("5.  MOVIES\n");
    printf("6.  PEOPLE\n");
    printf("7.  WINTER\n");
    scanf("%d", &catInput);

	//set list path
    char path[30] = "";
    switch(catInput){
        case 1:
            strcpy(path, "lists/listAnimals.txt");
            break;
       case 2:
            strcpy(path, "lists/listBooks.txt");
            break;
        case 3:
            strcpy(path, "lists/listBrands.txt");
            break;
        case 4:
            strcpy(path, "lists/listCountries.txt");
            break;
        case 5:
            strcpy(path, "lists/listMovies.txt");
            break;
        case 6:
            strcpy(path, "lists/listPeople.txt");
            break;
        case 7:
            strcpy(path, "lists/listWinter.txt");
            break;
        dafault:
			return 0;
    }
    
	//Pick a 'random' line
	char wordOne[256] = "";
    int randInt = (rand()%66);
    FILE *file = fopen(path, "r");
    printf("%s", path);
    if(file == NULL)
        printf("\nfile not found\n");
    while (fgets(line, sizeof(line), file)) {
        if(i == randInt){
            memset(wordOne, '\0', sizeof(wordOne));
            strcpy(wordOne, line);
            break;
        }
        i++;
    }
    fclose(file);

    //Store length of the found string
	int wordSize = strlen(wordOne) - 1;

    //Initialize array blanks with underscores or slashes if it finds a space
    for(i = 0; i < wordSize; i++){
        if(wordOne[i] == ' '){
        	blanks[i] = '/';
			spaces++;
    	}else{
			blanks[i] = '_';
    	}
    }

    //While loop will continuously display updated loops until a person runs out of lives
    while(counterLives > 0){
		int flag = 0;
        system("cls");
        
		printf("WordOne: %s\nline: %d\n", wordOne, randInt);

        //Dislay number of lives
        printf(" LIVES: %d\n\n", counterLives);
        
        //Display array of blanks
        for(i = 0; i < wordSize; i++)
            printf(" %c", blanks[i]);
        
        //Display array of wrong guesses
        printf("\nWRONG GUESSES:\n");
        for(i = 0; i < 11; i++)
            printf(" %c", wrongChars[i]);
        
        //Scans for user input and check to see if input matches character in generated word
        printf("\n\nGUESS A LETTER\n");
        scanf(" %c", &guess);
        for(i=0; i<wordSize; i++){
            if(wordOne[i] == guess && blanks[i] == '_'){
                printf("\a");
                blanks[i] = guess;
                flag = 1;
				counter++;
            }
		}

		//if not found, lose a life
		if (flag == 0) {
			counterLives--;
			wrongChars[j] = guess;
			j++;
		}
       
		//Lose Screen
		if (counterLives == 0) {
			system("cls");

			//Display final Lives
			printf(" LIVES: 0", counterLives);
			printf("\n");

			//Display final blanks
			for (i = 0; i < wordSize; i++)
				printf(" %c", blanks[i]);

			//Display final guesses
			printf("\n\nWRONG GUESSES:\n");
			for (i = 0; i < 9; i++) {
				printf(" %c", wrongChars[i]);
				printf("\n\n\nYOU LOSE, THE CORRECT ANSWER IS %s\n\n\nTYPE '1' TO PLAY AGAIN\nTYPE '2' TO RETURN TO MAIN MENU\n", wordOne);
				scanf(" %d", &input);
				switch (input) {
				case 1:
					playerOne();
					return 0;
				default:
					main();
					return 0;
				}
			}
		}
        
        //Win Screen
        else if(counter == (wordSize-spaces)){
            system("cls");
            
            //Display Lives
            printf(" LIVES: %d\n", counterLives);
            printf("\n");
        
            //Display blanks
            for(i = 0; i < wordSize; i++)
                printf(" %c", blanks[i]);
    
            //Display Guesses
            printf("\n\nWRONG GUESSES:\n");
            for(i = 0; i < 11; i++)
                printf(" %c", wrongChars[i]);
            
            //Display menu to play again or return to main menu
            printf("\n\nYOU WIN!");
            
			printf("\n\nTYPE '1' TO PLAY AGAIN\nTYPE '2' TO RETURN TO MAIN MENU\n");
            scanf(" %d", &input);
            switch(input){
                case 1:
                    playerOne();
					return 0;
                default:
                    main();
					return 0;
            }
    	}
    }
}

//Options menu
int options(void){
    system("cls");
    int inputDiff, counterLives;
    printf("DIFFICULTY OPTIONS:\n");
    printf("PRESS '1' FOR EASY DIFFICULTY\n");
    printf("PRESS '2' FOR MEDIUM DIFFICULTY\n");
    printf("PRESS '3' FOR HARD DIFFICULTY\n");
    printf("PRESS '4' TO RETURN TO THE MAIN MENU\n");
    scanf("%d", &inputDiff);
    
    //Change value of counterLives to selected value
    switch(inputDiff){
        case 1:
            counterLives = 11;
            break;
	case 3:
            counterLives = 6;
            break;
        default:
            counterLives = 8;
	    break;
    }
    return counterLives;
}


//Kade Harmon
