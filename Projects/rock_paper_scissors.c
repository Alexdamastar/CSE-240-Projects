/*
Alexander Lumala
2/1/25
Rock, Paper, Scissors!
Simple C program that plays rock paper scissors with you
*/

#include <stdio.h> //The standard input output library is required or else we can't take user input or use print statements
#include <stdlib.h> //Required to use the rand function
#include <time.h> //Time function required to access time functions, in this case time(null)
#include <string.h> //Required to use string comparsion 

// Function prototypes
void GetPlayerMove();
void GetComputerMove();
void PlayRockPaperScissorsGame();

//Variables
char key; // Continue or close the game
char game[12]; // Tracking game status ("in_progress" or "done")
char playerMove; // Player's move
char computerMove; // Computer's move
char winner[9]; // Game winner ("player" or "computer")
char choices[3] = {'r', 'p', 's'}; // Choices for the computer
int randomNum; // Random number for computer's move

int main() 
{
    printf("Welcome to Rock, Paper, Scissors! Press 'q' to quit or any other key to continue: ");
    scanf(" %c", &key); // Read single character input
    while (key != 'q')
    {
        PlayRockPaperScissorsGame();
        printf("Press 'q' to quit or any other key to continue: ");
        scanf(" %c", &key); // Read single character input again
    }
    printf("Bye Bye!");
}

void GetPlayerMove()
{
    //Just gets the player's move through user input
    printf("Enter your move (r for rock, p for paper, s for scissors): ");
    scanf(" %c", &playerMove);
}

void GetComputerMove()
{
    srand(time(NULL)); //Sets a seed (or starting point) for the random number generator based off the current time the code is run
    randomNum = rand() % 3;
    computerMove = choices[randomNum]; // Assign the computer's move
    printf("Computer's Move: %c\n", computerMove);
}

void PlayRockPaperScissorsGame()
{
    strcpy(game, "in_progress"); // Game in progress
    while (strcmp(game, "done") != 0) //Overarching while loop keeps the moves running until someone wins outright
    {
        GetPlayerMove();
        GetComputerMove();

        if (playerMove == 'r' && computerMove != 'r')
        {
            if (computerMove == 'p')
            {
                strcpy(winner, "computer");
                strcpy(game, "done");
            }
            else if (computerMove == 's')
            {
                strcpy(winner, "player");
                strcpy(game, "done");
            }
        }
        else if (playerMove == 'p' && computerMove != 'p')
        {
            if (computerMove == 's')
            {
                strcpy(winner, "computer");
                strcpy(game, "done");
            }
            else if (computerMove == 'r')
            {
                strcpy(winner, "player");
                strcpy(game, "done");
            }
        }
        else if (playerMove == 's' && computerMove != 's')
        {
            if (computerMove == 'r')
            {
                strcpy(winner, "computer");
                strcpy(game, "done");
            }
            else if (computerMove == 'p')
            {
                strcpy(winner, "player");
                strcpy(game, "done");
            }
        }
        else if (playerMove != 'r' && playerMove != 's' && playerMove != 'p')
        {
            printf("Invalid move.\n");
        }
        else if (playerMove == computerMove)
        {
            continue; // If moves are the same, continue
        }
    }
    if (strcmp(winner, "computer") == 0)
    {
        printf("Computer wins!\n");
    }
    else
    {
        printf("You win!\n");
    }
}