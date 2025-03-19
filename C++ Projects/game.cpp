#include <iostream>
#include <string>
#include <cstdio>  // For file I/O
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <cmath>    // For sqrt()
using namespace std;

class Player
{
    public:
        Player() {} //First creates the constructor
        Player(string nm, int ng) : name(nm), num_guesses(ng) {}

        string GetName() const { return name;}
        int GetNumGuesses() const { return num_guesses;}

        void SetName(string nm) {name = nm;}
        void SetGuesses(int ng) {num_guesses = ng;}

    private:
        string name;
        int num_guesses;

};

class LeaderBoard
{
    public:
        LeaderBoard() {}
        void InsertPlayer(Player player, string filename);
        void Readleaders(string filename);
        void SaveLeaders(string filename);
        void DisplayLeaders();

    private:
        static const int NUM_LEADERS = 5;
        Player leaders[NUM_LEADERS];
};

void LeaderBoard::Readleaders(string filename)
{
    FILE *file = fopen(filename.c_str(), "r");
    char name[50];  // Increase size if names might be longer
    int guesses;
    int index = 0;

    while (fscanf(file, "%49s %d", name, &guesses) == 2 && index < NUM_LEADERS)
    {
        leaders[index] = Player(string(name), guesses);  // Create std::string from name
        index++;
    }

    fclose(file);
}


void LeaderBoard::InsertPlayer(Player player, string filename)
{
    //Look if the player qualifies for the leaderboard
    int insertIndex = -1;

    for(int i = 0; i < NUM_LEADERS; i++)
    {
        if(leaders[i].GetNumGuesses() == 0 || player.GetNumGuesses() < leaders[i].GetNumGuesses())
        {
            insertIndex = i;
            break;
        }
    }

    //if the player doesn't qualify return early
    if (insertIndex == -1)
    {
        return;
    }

    //shift lower ranked players down to make space
    for (int i = NUM_LEADERS - 1; i > insertIndex; i--)
    {
        leaders[i] = leaders[i-1];
    }

    //insert the new player
    leaders[insertIndex] = player;

    //save updated leaderboard to file
    SaveLeaders(filename);
}

void LeaderBoard::SaveLeaders(string filename)
{
    FILE *file = fopen(filename.c_str(), "w");

    for (int i = 0; i < NUM_LEADERS; i++)
    {
        //only write player names that are not empty
        if (leaders[i].GetNumGuesses() > 0)
        {
            fprintf(file, "%s %d\n", leaders[i].GetName().c_str(), leaders[i].GetNumGuesses());
        }
    }

    fclose(file);
}

void LeaderBoard::DisplayLeaders()
{
    for (int i = 0; i < NUM_LEADERS; i++)
    {
        if (leaders[i].GetNumGuesses() > 0) //only display valid scores
        {
            cout << leaders[i].GetName() << " " << leaders[i].GetNumGuesses() << endl;
        }
    }
}

void PlayGuessingGame(Player &current_player, LeaderBoard &leaderboard, string filename)
{
    int guessCount = 0;
    srand(time(NULL));
    int randomTarget = rand() % 91 + 10; // Random number between 10 and 100
    double sqrtTarget = sqrt(randomTarget);

    cout << sqrtTarget << " is the square root of what number? Guess a value between 10 and 100: ";

    bool gameStatus = true;
    int guess;

    while (gameStatus) 
    {
        cin >> guess;
        guessCount++;

        if (guess == randomTarget) 
        {
            cout << "You got it, baby!\n";
            gameStatus = false;
        } 
        else 
        {
            if (guess > randomTarget) 
                cout << "Too high, guess again: ";
            else 
                cout << "Too low, guess again: ";
        }
    }

    cout << "You made " << guessCount << " guesses.\n";

    // Get the player's name
    cout << "Enter your name: ";
    string name;
    cin >> name;

    // Set player details
    current_player.SetName(name);
    current_player.SetGuesses(guessCount);

    // Update leaderboard
    leaderboard.InsertPlayer(current_player, "leaderboard.txt");

    // Display updated leaderboard (optional)
    cout << "Here are the current leaders: \n";
    leaderboard.DisplayLeaders();
}

int main()
{
    LeaderBoard leaderboard;
    leaderboard.Readleaders("leaderboard.txt");
    cout << "Welcome! Press 'q' to quit or any other key to continue:\n";
    char c;
    bool game_over = false;
    while (!game_over)
    {
        cin >> c;
        if (c == 'q')
        {
            game_over = true;
            cout << "Bye Bye!\n";
        }
        else
        {
            Player current_player;
            PlayGuessingGame(current_player, leaderboard, "leaderboard.txt");
           cout << "Press 'q' to quit or any other key to continue: ";
        }
    }
    return 0;
}