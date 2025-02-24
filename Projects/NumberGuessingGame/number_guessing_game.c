/*
Alexander Lumala
2/16/25
Number Guessing Game
This is a number guessing game with shows the top 5 players on a leaderboard
*/

#include <stdio.h> //The standard input output library is required or else we can't take user input or use print statements
#include <stdlib.h> //Required to use the rand function
#include <time.h> //Time function required to access time functions, in this case time(null)
#include <math.h> //Need to import math functions
#include <stdbool.h> //Required to use boolean values
#include <string.h>  //Required to use string comparsion


//Variables
char key; // Continue or close the program
char name[50];
int guessCount = 0; // Keep track of user's guess count
int randomTarget; // Number that the user needs to guess
bool gameStatus = true; // Tracks whether the game is over or not
int guess; //Tracks the number the user inputted for the guess

struct Leaderboard{
    char name[50];
    int guessCount;
};
struct Leaderboard leaderboard[5] = {0};

//Function prototypes
void loadLeadersFromFile(struct Leaderboard leaders[], const char *filename);
void updateLeaders(struct Leaderboard leaders[], const char *name, int guesses);
void saveLeadersToFile(const struct Leaderboard leaders[], const char *filename);
void displayLeaders(const struct Leaderboard leaders[]);


void promptUserName(char *name)
{
    printf("Please enter your name to start: ");
    scanf("%s", name);
}

int playGuessingGame()
{   
    gameStatus = true;
    guessCount = 0;
    loadLeadersFromFile(leaderboard, "leaderboard.txt");
    promptUserName(name);
    struct Leaderboard player;
    srand(time(NULL));
    randomTarget = rand() % 91 + 10;
    double sqrtTarget = sqrt(randomTarget);
    printf("%.2f is the square root of what number? Guess a value between 10 and 100: ", sqrtTarget);

    while (gameStatus) {
        scanf("%i", &guess);
        guessCount++;
        if (guess == randomTarget) {
            printf("You got it, baby!\n");
            gameStatus = false;
        } else {
            if (guess > randomTarget) {
                printf("Too high, guess again: ");
            } else {
                printf("Too low, guess again: ");
            }
        }
    }
    printf("You made %i guesses.\n", guessCount);

    //We are now moving from the functionality of the game to copying it into the leaderboard

    //Copying the player data
    strcpy(player.name, name);
    player.guessCount = guessCount;
    
    //Update leaderboard with new score
    updateLeaders(leaderboard, name, guessCount);

    //Save leaderboard to file
    saveLeadersToFile(leaderboard, "leaderboard.txt");
    //Load the leaders from the file into the current leaderboard array
    loadLeadersFromFile(leaderboard, "leaderboard.txt");
    //Display the leaders from the array
    printf("Here are the current leaders: \n");
    displayLeaders(leaderboard);
    
    return 0;
}

void updateLeaders(struct Leaderboard leaders[], const char *name, int guesses)
{
    int pos = -1; //If this stays negative 1 the score won't appear on the leader board
    for (int i = 0; i < 5; i++)
    {
        if (leaders[i].guessCount == 0 || guessCount < leaders[i].guessCount)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        for(int j = 4; j > pos; j--)
        {
            leaderboard[j] = leaderboard[j-1];
        }
        strcpy(leaderboard[pos].name, name);
        leaderboard[pos].guessCount = guessCount;
    }
}

void saveLeadersToFile(const struct Leaderboard leaders[], const char *filename)
{
    FILE* fp = fopen(filename, "w");

    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    for (int i = 0; i < 5; i++){ //SWITCH TO WHILE LOOP???
        if (leaders[i].name[0] != '\0'){
            fprintf(fp, "%s made %d guesses\n", leaders[i].name, leaders[i].guessCount);
        }
    }
    fclose(fp);
}

void loadLeadersFromFile(struct Leaderboard leaders[], const char *filename)
{
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "Cannot open %s.\n", filename);
        exit(1);
    }

    int i = 0; // Index for leaderboard array
    while (i < 5 && fscanf(fp, "%s %d", leaders[i].name, &leaders[i].guessCount) == 2) {
        i++;  // Move to the next index in the array
    }

    fclose(fp);
}

void displayLeaders(const struct Leaderboard leaders[])
{
    int i = 0;
    while (leaders[i].name[0] != '\0')
    {
        printf("%s made %d guesses\n", leaders[i].name, leaders[i].guessCount);
        i++;
    }
}


int main()
{
    printf("Welcome! Press 'q' to quit or any other key to continue: ");
    scanf(" %c",  &key);
    while (key != 'q')
    {
        playGuessingGame();
        printf("Press 'q' to quit or any other key to continue: ");
        scanf(" %c", &key);
    }
    printf("Bye Bye!");

    return 0;
}