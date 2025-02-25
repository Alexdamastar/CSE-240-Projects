/*
Alexander Lumala
2/9/25
The Game of Life
We are simulating a cellular automaton, orginally devised by the mathmetaician John Conway, brought to C by me.
*/

#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLS 5

//Variables
char key; // Continue or close the game

typedef enum {F = 0, T = 1} Bool;

int GetInitialState(int init_state[])
{
    int num_alive = 0;
    char comma;

    printf("Enter the offsets for the live cells: ");
    
    while (scanf("%d%c", &init_state[num_alive], &comma) == 2 && comma == ',')
    {
        num_alive++; // Move to the next position in the array
    }

    num_alive++; // Capture the last number
    return num_alive;
}

void SetInitialState(char board[][NUM_COLS], int init_state[], int num_alive)
{
    for (int i = 0; i < num_alive; i++)
    {
        int index = init_state[i];
        int row = index / NUM_COLS;
        int col = index % NUM_COLS;
        board[row][col] = '*';
    }
}

int CountLiveNeighbors(char board[][NUM_COLS], int r, int c)
{
    int count = 0;
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // Row direction offsets
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // Column direction offsets

    for (int i = 0; i < 8; i++)
    {
        int nr = r + dr[i]; // New row index
        int nc = c + dc[i]; // New column index

        // Check if neighbor is inside the grid and alive
        if (nr >= 0 && nr < NUM_ROWS && nc >= 0 && nc < NUM_COLS)
        {
            if (board[nr][nc] == '*') 
            { 
                count++; // Increase count if neighbor is alive
            }
        }
    }

    return count;
}

void NextGeneration(char board[][NUM_COLS])
{
    char new_board[NUM_ROWS][NUM_COLS]; // Temporary board for next state

    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            int live_neighbors = CountLiveNeighbors(board, i, j); // Get live neighbor count

            if (board[i][j] == '*')
            {
                // Rule 1 and 2: Live cell with 2 or 3 neighbors survives
                if (live_neighbors < 2 || live_neighbors > 3)
                {
                    new_board[i][j] = ' '; // Dies
                }
                else
                {
                    new_board[i][j] = '*'; // Survives
                }
            }
            else
            {
                // Rule 3: Dead cell with exactly 3 neighbors comes back to life
                if (live_neighbors == 3)
                {
                    new_board[i][j] = '*'; // Becomes alive
                }
                else
                {
                    new_board[i][j] = ' '; // Stays dead
                }
            }
        }
    }

    // Copy new state back to the board
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }
}

void PrintBoard(char board[][NUM_COLS])
{
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void PlayGameOfLife()
{
    // Declare and init empty board
    char board[NUM_ROWS][NUM_COLS] = {
        {' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };

    // Get and set initial state
    int init_state[NUM_ROWS * NUM_COLS]; // Array to store live cell indices
    int num_alive = GetInitialState(init_state); // Get number of alive cells
    SetInitialState(board, init_state, num_alive); // Place initial live cells
    
    
    for (int gen = 0; gen < 7; gen++)
    {
        printf("generation = %d:\n", gen);
        PrintBoard(board);
        NextGeneration(board);
    }

    printf("Good life!\n");
}

int main()
{
    printf("Welcome! Press 'q' to quit or any other key to continue: ");
    scanf(" %c", &key);
    while (key != 'q')
    {
        PlayGameOfLife();
        printf("Press 'q' to quit or any other key to continue: ");
        scanf(" %c", &key);
    }
    printf("Bye Bye!");

    return 0;
}